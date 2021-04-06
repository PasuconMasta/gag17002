#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include <cmath>
#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "uiDraw.h"


// Put your Bullet class here
class Bullet : public FlyingObject {
private:
	int lifeSpan;
	int age;


public:
	Bullet() {
		point.setX(200); point.setY(-200);
		alive = true;
		lifeSpan = 40;
		age = 0;
		setRadius(1);


	}
	~Bullet() {}

	void addAge() { age++; }
	void setAge(int input) { this->age = input; }
	void setLifeSpan(int input) { this->lifeSpan = input; }
 	void killOldBullets() { if (age >= lifeSpan) { kill(); } }


	int getAge() { return age; }
	int getLifeSpan() { return lifeSpan;
	}

	void fire(Point point, float angle, float speed);
	virtual void draw() { drawDot(this->getPoint()); }
	

};






#endif /* bullet_h */
