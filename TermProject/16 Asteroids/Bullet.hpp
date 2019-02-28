#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

//derived class from entity
class bullet: public Entity
{
public:
  bullet(float x, float y, float angle)
  {
    name = Bullet;
    tex.loadFromFile("images/fire_blue.png");
    anim = Animation(tex, 0,0,32,64, 16, 0.8);
    settings(anim, x, y, angle, 10);
  }

  void  update()
  {
   dx=cos(angle*DEGTORAD)*6;
   dy=sin(angle*DEGTORAD)*6;
  // angle+=rand()%6-3;
   x+=dx;
   y+=dy;

   if (x>W || x<0 || y>H || y<0) life=0;
  }
private:
};
