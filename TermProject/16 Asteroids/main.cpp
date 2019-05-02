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
struct event_listener
{
  // Window events
  virtual void on_close() { }
  virtual void on_gain_focus() { }
  virtual void on_lose_focus() { }
  virtual void on_resize(sf::Event::SizeEvent) { }

  // Mouse events
  virtual void on_mouse_button_press(sf::Event::MouseButtonEvent) { }
  virtual void on_mouse_button_release(sf::Event::MouseButtonEvent) { }

  // Keyboard events
  virtual void on_key_press(sf::Event::KeyEvent) { }
  virtual void on_key_release(sf::Event::KeyEvent) { }
};
struct event_source
{
  event_source(sf::Window &w)
    : window (&w){}
  void listen(event_listener &l)
  {listeners.push_back(&l);}
  void poll()
  {
    sf::Event e;
    while(window->pollEvent(e))
      process(e);
  }
  void process(sf::Event const &e)
  {
    switch(e.type)
    {
        case Event::Closed :
          return notify([e](event_listener *l){l->on_close();});
        case Event::Resized :
          return notify([e](event_listener *l){l->on_resize(e.size);});
        case Event::MouseButtonPressed :
          return notify([e](event_listener *l){l->on_mouse_button_press(e.mouseButton);});
        case Event::MouseButtonReleased :
          return notify([e](event_listener *l){l->on_mouse_button_release(e.mouseButton);});
        case Event::KeyPressed :
          return notify([e](event_listener *l){l->on_key_press(e.key);});
        case Event::KeyReleased :
          return notify([e](event_listener *l){l->on_key_release(e.key);});
        default :
          break;
    }
  }

  template<typename T>
  void notify(T fn)
  {
    for(event_listener *l : listeners)
    {
      fn(l);
    }
  }

  sf::Window *window;
  std::vector<event_listener *> listeners;
};

struct ass_app : event_listener
{
  ass_app()
    : window(VideoMode(W,H),"Asteroids"), p(new player()), numberOfPU(0)
    
    {
      window.setFramerateLimit(60);
      //start with 15 asteriods
      for(int i = 0; i < 15; i++)
      {
        entities.push_back(new asteroid(rand()%W, rand()%H, Large));
      }
      //pus player in game
      entities.push_back(p);
      life1 = anim.live;
      life2 = anim.live;
      life2.setPosition(50.0f,0);
      life3 = anim.live;
      life3.setPosition(100.0f,0);
      srand(time(0));
    }
  bool is_open() const {return window.isOpen();}
  void on_close() override
  {
    window.close();
  }
  void on_mouse_button_press(sf::Event::MouseButtonEvent e) override
  {
    //mouse doensnt do anything yet 
    //could make it shoot as well
    return;
  }
  void on_key_press(sf::Event::KeyEvent e) override
  {
    Event event;
    while(window.pollEvent(event))  
    {
      if(e.code == Keyboard::Space)
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
  void thrusters()
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      p->angle += 3;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      p->angle -= 3;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      p->thrust = true;
    else
      p->thrust = false;
    if(p->thrust) p->set_Anim_Go();
    else p->set_Anim_Normal();
  }
  void checkColision()
  {
    for(auto a : entities)
    {
      for(auto b : entities)
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
              on_close();
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
    }
  }
  void explosion_animation()
  {
      for(auto e:entities)
      //if e's name is explosion 
     if (e->name==Explosion)
      //kills player or destroys as
      if (e->anim.isEnd()) e->life=0; 
  }
  void spawnNewAss()
  {
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
  }
  void deleteEntity()
  {
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
  }
  void draw()
  {
    window.draw(anim.background);
    window.draw(anim.background);
    window.draw(life1);
    window.draw(life2);
    window.draw(life3);

   for(auto i:entities)
     i->draw(window);

    window.display();
  }
  animationContainer anim;
  sf::RenderWindow window;
  player *p;
  int numberOfPU;
  std::list<Entity *> entities;
  Sprite life1;
  Sprite life2;
  Sprite life3;
};

int main()
{
  ass_app app;

  event_source events(app.window);
  events.listen(app);

  while(app.is_open())
  {
    events.poll();
    app.thrusters();
    app.checkColision();
    app.explosion_animation();
    app.spawnNewAss();
    app.deleteEntity();
    app.draw();
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
             		main();
             	}
             }
         }
	}
}