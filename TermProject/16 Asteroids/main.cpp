#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
using namespace sf;

#include "Animation.hpp"
#include "Entity.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

//global variables
const int W = 1200;
const int H = 800;

float DEGTORAD = 0.017453f;

class explosion : public Entity
{
public:
  Texture t7;
  Animation sExplosion_ship;
  //creator for explosions
  explosion(float x,float y)
  {
    name = Explosion;
    t7.loadFromFile("images/explosions/type_B.png");
    sExplosion_ship = Animation(t7, 0,0,192,192, 64, 0.5);
    settings(sExplosion_ship,x,y);
  }
  //virtual ~Explosion(){}
//checks if the entities have collided 
//private:

};

bool isCollide(Entity *a,Entity *b)
{
  return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}


int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t4,t5,t6,t7;
    t1.loadFromFile("./images/spaceship.png");
    t2.loadFromFile("./images/background.jpg");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0,0,256,256, 48, 0.5);
    Animation sRock(t4, 0,0,64,64, 16, 0.2);
    Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
    Animation sBullet(t5, 0,0,32,64, 16, 0.8);
    Animation sPlayer(t1, 40,0,40,40, 1, 0);
    Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
    Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);


    std::list<Entity*> entities;

    for(int i=0;i<15;i++)
    {
      asteroid *a = new asteroid();
      a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
      entities.push_back(a);
    }

    player *p = new player();
    p->settings(sPlayer,200,200,0,20);
    entities.push_back(p);

    /////main loop/////
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
             if (event.key.code == Keyboard::Space)
              {
                bullet *b = new bullet();
                b->settings(sBullet,p->x,p->y,p->angle,10);
                entities.push_back(b);
              }
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle-=3;
    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
    else p->thrust=false;



    for(auto a:entities)
     for(auto b:entities)
    {
      if (a->name == Asteroid && b->name == Bullet)
       if ( isCollide(a,b) )
           {
            a->life=false;
            b->life=false;

            //create entity exposiln
            /*Move to own class */
            Entity *e = new Entity();
            e->settings(sExplosion,a->x,a->y);
            e->name=Explosion;
            entities.push_back(e);


            for(int i=0;i<2;i++)
            { 
             if (a->R==15) continue;
             Entity *e = new asteroid();
             e->settings(sRock_small,a->x,a->y,rand()%360,15);
             entities.push_back(e);
            }

           }

      if (a->name==Player && b->name==Asteroid)
       if ( isCollide(a,b) )
           {
            b->life=false;

            //create explosion again 
            /*same as before move to own class*/
            /*
            Entity *e = new Entity();
            e->settings(sExplosion_ship,a->x,a->y);
            e->name=Explosion;
            */
            entities.push_back(explosion(a->x , a->y));

            p->settings(sPlayer,W/2,H/2,0,20);
            p->dx=0; p->dy=0;
           }
    }

    //controls animation of theship
    if (p->thrust)  p->anim = sPlayer_go;
    else   p->anim = sPlayer;


    for(auto e:entities)
      //if e's name is explosion 
     if (e->name==Explosion)
      //kills player or destroys as
      if (e->anim.isEnd()) e->life=0;

    //spawn new as as long as the random number mod 150 == 0
    if (rand()%150==0)
     {
       asteroid *a = new asteroid();
       a->settings(sRock, 0,rand()%H, rand()%360, 25);
       entities.push_back(a);
     }

     //iterats through the vector i that holds the entities 
    for(auto i=entities.begin();i!=entities.end();)
    {
      //pointer e now points to i
      Entity *e = *i;

      e->update();
      e->anim.update();

      //if e is dead kill e 
      if (e->life==false) {i=entities.erase(i); delete e;}
      else i++;
    }



   //////draw//////
   app.draw(background);

   for(auto i:entities)
     i->draw(app);

   app.display();
    }

    return 0;
}
