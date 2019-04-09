#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

class explosion : public Entity
{
public:

  //creator for explosions
  explosion(float x, float y, Animation a)
    //: anim(a)
  {
    name = Explosion;
    anim = a;
    settings(anim,x,y);
  }
private:
};