#pragma once
#include "Entity.hpp"

//derived class of entity
class asteroid: public Entity
{
public:
  asteroid()
  {
    dx=rand()%8-4;
    dy=rand()%8-4;
    //name="asteroid";
    name = Asteroid;
  }

  void  update()
  {
   x+=dx;
   y+=dy;

   if (x>W) x=0;  if (x<0) x=W;
   if (y>H) y=0;  if (y<0) y=H;
  }
private:
  const int W = 1200;
  const int H = 800;

};