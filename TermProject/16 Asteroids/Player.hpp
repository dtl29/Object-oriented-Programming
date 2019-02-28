#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

//derived class of entity
class player: public Entity
{
public:
   bool thrust;

   player()
   {
      name = Player;
      tex.loadFromFile("./images/spaceship.png");
      tex.setSmooth(true);
      normal = Animation(tex, 40,0,40,40, 1, 0);
      go = Animation (tex, 40,40,40,40, 1, 0);
      anim = normal;
      settings(anim,200,200,0,20);
   }
   void respawn()
   {
   		settings(anim,W/2,H/2,0,20);
   		 dx=0; dy=0;
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
   void set_Anim_Normal() {anim = normal; return;}
   void set_Anim_Go() {anim = go; return;}
 private:
 	Animation go, normal;
};