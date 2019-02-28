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
#include "Explosion.hpp"

//global variables
const int W = 1200;
const int H = 800;

float DEGTORAD = 0.017453f;

//check if something has collided
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

    Texture  t2;
    t2.loadFromFile("./images/background.jpg");

    t2.setSmooth(true);

    Sprite background(t2);

    //entities in game are held here as pointers
    std::list<Entity*> entities;

    //creation of 15 asteroids
    for(int i=0;i<15;i++)
    {
      entities.push_back(new asteroid(rand()%W, rand()%H, Large));
    }

    player *p = new player();
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
                entities.push_back(new bullet(p->x, p->y, p->angle));
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
            entities.push_back(new explosion(a->x , a->y , Two));


            for(int i=0;i<2;i++)
            { 
             if (a->R==15) continue;
                entities.push_back(new asteroid(a->x,a->y, Small));
            }

           }
      //if a player collids with astroid 
      ///destroy asteroid, make an explosion, respawn player
      if (a->name==Player && b->name==Asteroid)
       if ( isCollide(a,b) )
           {
            b->life=false;

            entities.push_back(new explosion(a->x , a->y, One));

            p->respawn();
           }
    }

    //controls animation of theship
    if (p->thrust)  p->set_Anim_Go();
    else   p->set_Anim_Normal();


    for(auto e:entities)
      //if e's name is explosion 
     if (e->name==Explosion)
      //kills player or destroys as
      if (e->anim.isEnd()) e->life=0;

    //spawn new as as long as the random number mod 150 == 0
    if (rand()%150==0)
     {
       entities.push_back(new asteroid(0,rand()%H, Large));
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
