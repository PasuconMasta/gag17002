#include "bullet.h"


// Put your bullet methods here


void Bullet :: fire(Point point, float angle, float speed)
{
        setPoint(point);
        angle = angle + 90;
       

        float x; float y;
        //this->velocity.setDx(speed * (-cos(3.141592 / 180.0 * angle))*-1);
        //this->velocity.setDy(speed * (sin(3.141592 / 180.0 * angle)));
        this->velocity.setDx(this->velocity.getDx() + (speed * (-cos(3.141592 / 180.0 * angle)) * -1));
        this->velocity.setDy(this->velocity.getDy() + (speed * (sin(3.141592 / 180.0 * angle))));
}


