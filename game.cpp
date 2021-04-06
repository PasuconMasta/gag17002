/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "flyingObject.h"
#include "bullet.h"
#include "ship.h"
#include <vector>

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;





/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br)
    : topLeft(tl), bottomRight(br)
{
    // Set up the initial conditions of the game***
    spaceShip.setRadius(10);
    


    //create intial Rocks
    levelUp();

   
    
}



 /***************************************
  * GAME :: ADVANCE
  * advance the game one unit of time
  ***************************************/
void Game :: advance() 
{
    spaceShip.advance();
    spaceShip.wrap();


    int i = 0;
    while (i < asteroids.size())
    {
        if (asteroids[i]->isAlive() == false)
        {
            createRocks();
        }
        i++;
    }
    
   
    
    
    advanceRocks();
    advanceBullets();
    handleCollition();
    if (score !=0 && score % 40 == 0)
    {
        levelUp();
        score++;
    }

    
}


/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game:: draw(const Interface & ui)
{
    if (spaceShip.isAlive())
    {
        spaceShip.draw();
    }
    
   
    int i = 0;
    while (i < asteroids.size())
    {
        if (asteroids[i]->isAlive())
        {
            asteroids[i]->draw();
        }
        
        i++;
    }


    i = 0;
    while (i < bullets.size())
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
        
        i++;
    }
 
    if (spaceShip.isAlive() == false)
    {
        Point messagePoint; messagePoint.setX(-20); messagePoint.setY(100);
        drawText(messagePoint, "You Crashed!");
    }
    
    Point scorePoint; scorePoint.setX(-180); scorePoint.setY(180);
    drawNumber(scorePoint, score);


    Point levelPoint; levelPoint.setX(-20); levelPoint.setY(180);
    drawText(levelPoint, "level");
    Point levelNumPoint; levelNumPoint.setX(10); levelNumPoint.setY(189);
    drawNumber(levelNumPoint, level);

    frames++;
}


/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game:: handleInput(const Interface & ui)
{

    // change direction of ship
    if (ui.isLeft())
    {
        spaceShip.turnleft();
    }

    if (ui.isRight())
    {
        spaceShip.turnRight();
    }

    

    // engage ship thrusters 
    if (ui.isUp())
    {
        spaceShip.setIsThrust(true);
        spaceShip.thurst();
    }
    else 
    {
        spaceShip.setIsThrust(false);
    }

    //fire bullets from ship
     if (ui.isSpace() && spaceShip.isAlive())
    {
         //create bullet
        Bullet newBullet;

        // gives bullets same velocity as the space ship
        newBullet.getVelocity().setDx(spaceShip.getVelocity().getDx()); 
        newBullet.getVelocity().setDy(spaceShip.getVelocity().getDy());

        //set Bullet trajectory
        newBullet.fire(spaceShip.getPoint(), spaceShip.getDirection(), BULLET_SPEED);
        bullets.push_back(newBullet); 
        
    }

     if (ui.isSpace() && !spaceShip.isAlive())
     {
         level = 0;
         frames = 0;
         score = 0;
         asteroids.clear();
         spaceShip.reset();
         levelUp();
     }


 }

void Game:: advanceRocks()
{
    

    int i = 0;
    while (i < asteroids.size())
    {
        asteroids[i]->advance();
        asteroids[i]->rotate();
        asteroids[i]->wrap();
        
        i++;
    }
    

}


/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
    Bullet newBullet; newBullet.setAlive(false); bullets.push_back(newBullet);

    // Move each of the bullets forward if it is alive
   
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i].advance();
            bullets[i].wrap();
            bullets[i].setAge(bullets[i].getAge() + 1);
            bullets[i].killOldBullets();

        }
    }

    
   
}

void Game:: createRocks()
{
    
   

}

void Game::cleanUpZombies()
{
    // Look for dead bullets
    vector<Bullet>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet bullet = *bulletIt;
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        //Bullet* pBullet = *bulletIt;

        if (!bullet.isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...


            // remove from list and advance
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++; // advance
        }

    }

    // Look for dead asteroids
    vector<Rock*>::iterator asteroidIt = asteroids.begin();
    while (asteroidIt != asteroids.end())
    {
        Rock* pAsteroid = *asteroidIt;
      

        if (!pAsteroid->isAlive())
        {
            
            pAsteroid = NULL;
            delete pAsteroid;
            

            // remove from list and advance
            asteroidIt = asteroids.erase(asteroidIt);
        }
        else
        {
            asteroidIt++; // advance
        }

    }
    
}


/**********************************************************
* Function:  handleCollition
* Description: checks if objetc have hit
**********************************************************/
void Game :: handleCollition()
{

    // check to see if the ship crashed
    int i = 0;
    while (i < asteroids.size()) //loop all asteroids
    {
        if (asteroids[i]->isAlive())
        {
            Rock thisAsteroid = *asteroids[i]; //convert asteroid to workable format


            //check of ship crashed
            if (getClosestDistance(spaceShip, thisAsteroid) <= (spaceShip.getRadius() + thisAsteroid.getRadius()))
            {
                if (frames > 20)
                {
                    spaceShip.setAlive(false);
                }
                
            }

            //check if Bullet hit 
            int bulletIndex = 0;
            while (bulletIndex < bullets.size()) //loop through bullets
            {
                if (getClosestDistance(bullets[bulletIndex], thisAsteroid) <= (bullets[bulletIndex].getRadius() + thisAsteroid.getRadius()))
                {
                    bullets[bulletIndex].setAlive(false);
                    cleanUpZombies();
                    asteroids[i]->kill();
                    breakUpAsteroids(*asteroids[i]);
                    cleanUpZombies();
                    score++;

                    
                }
                bulletIndex++;
            }
            



        }
        i++;
    }

}



/**********************************************************
* Function:  breakUpAsteroids
* Description: breaks up asteroids and deletes them
**********************************************************/
void Game::breakUpAsteroids(Rock asteroid)
{
    if ( asteroid.getType() == "LrgAsteroid")
    {
        
        
     
        asteroids.push_back(new Medasteroid);
        asteroids[asteroids.size() - 1]->setPoint(asteroid.getPoint());
     

        asteroids.push_back(new Medasteroid);
        asteroids[asteroids.size() - 1]->setPoint(asteroid.getPoint());
        
        asteroids.push_back(new Smaasteroid);
        asteroids[asteroids.size() - 1]->setPoint(asteroid.getPoint());

    }

    if (asteroid.getType() == "MedAsteroid")
    {
        asteroids.push_back(new Smaasteroid);
        asteroids[asteroids.size() - 1]->setPoint(asteroid.getPoint());

        asteroids.push_back(new Smaasteroid);
        asteroids[asteroids.size() - 1]->setPoint(asteroid.getPoint());

    }



}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject & obj1, const FlyingObject & obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}



void Game :: levelUp()
 {
    int i = 0;
    while (i < (level + 5))
    {
        asteroids.push_back(new Lrgasteroid);
        i++;
    }

    level++;
    frames = 0;
}



