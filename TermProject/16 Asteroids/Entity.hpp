#pragma once

enum Entities
{
  Player,
  Asteroid,
  Bullet,
  Explosion,
};

//base class for the objects of the game
class Entity
{
public:
  float x,y,dx,dy,R,angle;
  bool life;
  //std::string name;
  Entities name;
  Animation anim;
  Texture tex;

   	const int W = 1200;
	const int H = 800;
	float DEGTORAD = 0.017453f;

  Entity()
  {
    life=1;
  }

  void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
  {
    anim = a;
    x=X; y=Y;
    angle = Angle;
    R = radius;
  }

  virtual void update(){};

  void draw(RenderWindow &app)
  {
    anim.sprite.setPosition(x,y);
    anim.sprite.setRotation(angle+90);
    app.draw(anim.sprite);

    CircleShape circle(R);
    circle.setFillColor(Color(255,0,0,170));
    circle.setPosition(x,y);
    circle.setOrigin(R,R);
    app.draw(circle);
  }

  virtual ~Entity(){};
};