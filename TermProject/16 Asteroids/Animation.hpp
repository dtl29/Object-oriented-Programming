#pragma once
#include <SFML/Graphics.hpp>

//controls the frame for the animation
class Animation
{
public:
	float Frame, speed;
	Sprite sprite;
    std::vector<IntRect> frames;

	Animation(){}

    Animation (Texture &t, int x, int y, int w, int h, int count, float Speed)
	{
	    Frame = 0;
        speed = Speed;

		for (int i=0;i<count;i++)
         frames.push_back( IntRect(x+i*w, y, w, h)  );

		sprite.setTexture(t);
		sprite.setOrigin(w/2,h/2);
        sprite.setTextureRect(frames[0]);
	}


	void update()
	{
   		Frame += speed;
		int n = frames.size();
		if (Frame >= n) Frame -= n;
		if (n>0) sprite.setTextureRect( frames[int(Frame)] );
	}

	bool isEnd()
	{
	  return Frame+speed>=frames.size();
	}

};

struct animationContainer{
	Texture t1,t2,t3,t4,t5,t6,t7,t8,t9;
	Animation sExplosion;
	Animation sRock;
	Animation sRock_small;
	Animation sBullet;
	Animation sPlayer;
	Animation sPlayer_go;
	Animation sExplosion_ship;
	Animation pwrup;
	Sprite background;
	Sprite live;
	animationContainer()
	{
		 t1.loadFromFile("images/spaceship.png");
		 t2.loadFromFile("images/background.jpg");
		 t3.loadFromFile("images/explosions/type_C.png");
		 t4.loadFromFile("images/rock.png");
		 t5.loadFromFile("images/fire_blue.png");
		 t6.loadFromFile("images/rock_small.png");
		 t7.loadFromFile("images/explosions/type_B.png");
		 t8.loadFromFile("images/power_up.png");
		 t9.loadFromFile("images/lives.png");
		
		t1.setSmooth(true);
		t2.setSmooth(true);

		background = *(new Sprite(t2));
		live = *(new Sprite(t9));

		 sExplosion = Animation(t3, 0,0,256,256, 48, 0.5);
		 sRock = Animation(t4, 0,0,64,64, 16, 0.2);
		 sRock_small = Animation(t6, 0,0,64,64, 16, 0.2);
		 sBullet = Animation(t5, 0,0,32,64, 16, 0.8);
		 sPlayer = Animation(t1, 40,0,40,40, 1, 0);
		 sPlayer_go = Animation(t1, 40,40,40,40, 1, 0);
		 sExplosion_ship = Animation(t7, 0,0,192,192, 64, 0.5);
		 pwrup = Animation(t8,0,0,64,64,16,0.2);
	}
};