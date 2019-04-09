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
#include "PowerUp.hpp"

#include <iostream>

//global variables
const int W = 1200;
const int H = 800;

float DEGTORAD = 0.017453f;
void game();
void gameOver();

//check if something has collided
bool isCollide(Entity *a,Entity *b)
{
  return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}


int main()
{
    game();

    return 0;
}
void game()
{
	 //entities in game are held here as pointers
    std::list<Entity*> entities; 

	RenderWindow app(VideoMode(W, H), "Asteroids!");
	srand(time(0));

	int numberOfPU = 0;

    animationContainer anim;

    app.setFramerateLimit(60);


	 //creation of 15 asteroids
    for(int i=0;i<15;i++)
    {
      entities.push_back(new asteroid(rand()%W, rand()%H, Large));
    }

    player *p = new player();
    entities.push_back(p);

    Sprite life1 = anim.live;
	Sprite life2 = anim.live;
	life2.setPosition(50.0f,0);
	Sprite life3 = anim.live;
	life3.setPosition(100.0f,0);

    /////main loop/////
    while (app.isOpen())
    {

       Event event;
       while (app.pollEvent(event))
       {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
            {
	             if (event.key.code == Keyboard::Space)
	              {
	              	if(p->get_shots() == 1)
	              	{
	                	entities.push_back(new bullet(p->x, p->y, p->angle, anim.sBullet));
	            	}	
	            	else if(p->get_shots() == 2)
	            	{
	            		entities.push_back(new bullet(p->x-10, p->y-10, p->angle, anim.sBullet));
	            		entities.push_back(new bullet(p->x+10, p->y+10, p->angle, anim.sBullet));
	            	}
	            	else
	            	{
	            		entities.push_back(new bullet(p->x-10, p->y-10, p->angle, anim.sBullet));
	            		entities.push_back(new bullet(p->x, p->y, p->angle, anim.sBullet));
	            		entities.push_back(new bullet(p->x+10, p->y+10, p->angle, anim.sBullet));
	            	}
	              }
	            
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
            entities.push_back(new explosion(a->x , a->y, anim.sExplosion_ship));


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

            entities.push_back(new explosion(a->x , a->y,anim.sExplosion));
            if(p->get_lives() <= 1)
            {
            	app.close();
    			gameOver();
            }
            p->respawn();
            if(p->get_lives() == 2)
            {
            	life3.scale(0.0f,0.0f);
            }
            if(p->get_lives() == 1)
            {
            	life2.scale(0.0f, 0.0f);
            }
           }
        if(a->name==Player && b->name==PowerUp)
        {
        	if(isCollide(a,b))
        	{	
	        	b->life = false;
	        	p->increase_shots();
	        	numberOfPU -= 1;
	        }
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
     if(rand()%350==0 && numberOfPU < 4)
     {
     	numberOfPU += 1;
     	entities.push_back(new powerup(rand()%W,rand()%H, anim.pwrup));
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
   app.draw(anim.background);
   app.draw(life1);
   app.draw(life2);
   app.draw(life3);

   for(auto i:entities)
     i->draw(app);

   app.display();
    }
}
void gameOver()
{
	RenderWindow app(VideoMode(W, H), "Game Over!");
	Texture go;
	go.loadFromFile("./images/background_GameOver.jpg");
	go.setSmooth(true);
	Sprite background_2;
	background_2 = *(new Sprite(go));
	while(app.isOpen())
	{
		app.draw(background_2);
		app.display();
		Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
             {
             	if(event.key.code == Keyboard::S)
             	{
             		app.close();
             		game();
             	}
             }
         }
	}
}