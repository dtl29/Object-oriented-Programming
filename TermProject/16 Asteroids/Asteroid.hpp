#pragma once
#include "Entity.hpp"
#include "Animation.hpp"
enum TypeOfA
{
  Small, 
  Large,
};

//derived class of entity
class asteroid: public Entity
{
public:
  asteroid(float x, float y, TypeOfA type )
  {
    dx=rand()%8-4;
    dy=rand()%8-4;
    //name="asteroid";
    name = Asteroid;
    if(type == Large)
    {
      tex.loadFromFile("images/rock.png");
      anim = Animation(tex, 0,0,64,64, 16, 0.2);
      settings(anim, x, y, rand()%360, 25);
    }
    else
    {
      tex.loadFromFile("images/rock_small.png");
      anim = Animation(tex, 0,0,64,64, 16, 0.2);
      settings(anim, x, y, rand()%360, 15);
    }
  }

  void  update()
  {
   x+=dx;
   y+=dy;

   if (x>W) x=0;  if (x<0) x=W;
   if (y>H) y=0;  if (y<0) y=H;
  }
private:
};