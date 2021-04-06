

#include "flyingObject.h"
#include "uiDraw.h" 
#include <cmath>

// Put your FlyingObject method bodies here

void FlyingObject::advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}


void  FlyingObject :: fire(Point point, float angle, float speed)
{
    

    this->velocity.setDx( speed * (-cos(3.141592 / 180.0 * angle)));
    this->velocity.setDy(speed * (sin(3.141592 / 180.0 * angle)));


}


void FlyingObject::wrap()
{
	Point tl(-200, 200);
	Point br(200, -200);
	//if (isWrapable()) {
		if (point.getX() < tl.getX()) {
			point.setX(br.getX());
		}
		if (point.getX() > br.getX()) {
			point.setX(tl.getX());
		}
		if (point.getY() > tl.getY()) {
			point.setY(br.getY());
		}
		if (point.getY() < br.getY()) {
			point.setY(tl.getY());
		}

	//}
}

/*void FlyingObject::rotate(float rotation)
{
 this->velocity.setDx( speed * (-cos(3.141592 / 180.0 * angle)));
    this->velocity.setDy(speed * (sin(3.141592 / 180.0 * angle)));
    {velocity.setAngle(velocity.getAngle() + rotation)
}*/
