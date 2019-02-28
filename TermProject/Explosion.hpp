#pragma once
#include "Entity.hpp"

class explosion : public Entity
{
public:

  //creator for explosions
  explosion(float x,float y, int type)
  {
    name = Explosion;
    if(type == 1)
    {
      t7.loadFromFile("images/explosions/type_B.png");
      sExplosion = Animation(t7, 0,0,192,192, 64, 0.5);
      settings(sExplosion,x,y);
    }
    else
    {
      t3.loadFromFile("images/explosions/type_C.png");
      sExplosion = Animation (t3, 0,0,256,256, 48, 0.5);
      settings(sExplosion,x,y);
    }
  }
private:
  Texture t7;
  Texture t3;
  Animation sExplosion;

};