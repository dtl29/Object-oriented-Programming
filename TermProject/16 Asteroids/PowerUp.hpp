#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

class powerup : public Entity
{
public:
	powerup(float x, float y, Animation a)
		//: anim(a) , name(PowerUp)
		{
			name = PowerUp;
			anim = a;
			dx=rand()%8-4;
    		dy=rand()%8-4;
			settings(anim, x, y, rand()%360, 25);
		}
	void  update()
	{
	   x+=dx;
	   y+=dy;

	   if (x>W) x=0;  if (x<0) x=W;
	   if (y>H) y=0;  if (y<0) y=H;
	}	
};