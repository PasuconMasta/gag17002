/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "uiDraw.h"
#include "uiInteract.h"
#include "flyingObject.h"
#include <vector>
#include <sstream>
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
using namespace std;

class Game
{
private:
    // The coordinates of the screen
    Point topLeft;
    Point bottomRight;
    Ship spaceShip;
    vector<Rock*> asteroids;
    vector<Bullet> bullets;
    int score = 0;
    int level = 0;
    int frames = 0;
 


public:
    /*********************************************
   * Constructor
   * Initializes the game
   *********************************************/
    Game(Point tl, Point br);
  

    /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
    void handleInput(const Interface& ui);


    /*********************************************
   * Function: advance
   * Description: Move everything forward one
   *  step in time.
   *********************************************/
    void advance();
   



   /*********************************************
  * Function: draw
  * Description: draws everything for the game.
  *********************************************/
  // draws all the objects at thier new location per frame
    void draw(const Interface& ui);



 /*********************************************
 * Function: getClosestDistance
 * Description: ????
 *********************************************/
    float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const;


    void cleanUpZombies();



    //create the objects
     void createRocks();
    
    //loop through asteroids vector and advance each item
    void advanceRocks();
    void advanceBullets();
    //void advanceShip();


    void handleCollition();
    void breakUpAsteroids(Rock asteroid);
    void levelUp();

    
};



#endif /* GAME_H */
