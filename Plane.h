#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"
#include "Bullet.h" 
#include "Drawable.h"
#include <vector>

class Game;

class Plane {
public:
    Plane(Game* game, int startX, int startY, int speed);
    ~Plane(); // delete the bullets

    void move(window& win);  // move and draw the plane
    void draw(window& w);

    void fireBullet(); // fire them bullets

    void consumeFuel();      
    int getFuelLevel() const; 
private:
    Game* pGame;
    int x, y;
    int fuelLevel; 
    int p_speed;
    std::vector<Bullet*> bullets; // store bullets
};


   

