#pragma once
#include "Entity.hpp"

//derived class of entity
class player: public Entity
{
public:
   bool thrust;

   player()
   {
      name = Player;
      lives = 3;
      shots = 1;
      tex.loadFromFile("./images/spaceship.png");
      tex.setSmooth(true);
      normal = Animation(tex, 40,0,40,40, 1, 0);
      go = Animation (tex, 40,40,40,40, 1, 0);
      anim = normal;
      settings(anim,W/2,H/2,0,20);
      thrust = false;
   }
   void respawn()
   {
   		settings(anim,W/2,H/2,0,20);
     		 dx=0; dy=0;
         lives -= 1;
    }
   void update()
   {
     if (thrust)
      { dx+=cos(angle*DEGTORAD)*0.2;
        dy+=sin(angle*DEGTORAD)*0.2; }
     else
      { dx*=0.99;
        dy*=0.99; }

    int maxSpeed=15;
    float speed = sqrt(dx*dx+dy*dy);
    if (speed>maxSpeed)
     { dx *= maxSpeed/speed;
       dy *= maxSpeed/speed; }

    x+=dx;
    y+=dy;

    if (x>W) x=0; if (x<0) x=W;
    if (y>H) y=0; if (y<0) y=H;
   }
   int get_lives() { return lives;}
   int get_shots() { return shots;}
   void set_lives(int n){lives = n;}
   void increase_shots(){shots += 1;}
   void set_Anim_Normal() {anim = normal; return;}
   void set_Anim_Go() {anim = go; return;}
 private:
 	Animation go, normal;
  int lives;
  int shots;
};