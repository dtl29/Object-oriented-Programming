#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

enum TypeOfE
{
  One,
  Two,
};

class explosion : public Entity
{
public:

  //creator for explosions
  explosion(float x,float y, TypeOfE type)
  {
    name = Explosion;
    if(type == One)
    {
      tex.loadFromFile("images/explosions/type_B.png");
      anim = Animation(tex, 0,0,192,192, 64, 0.5);
      settings(anim,x,y);
    }
    else
    {
      tex.loadFromFile("images/explosions/type_C.png");
      anim = Animation (tex, 0,0,256,256, 48, 0.5);
      settings(anim,x,y);
    }
  }
private:
};