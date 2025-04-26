#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"
#include "Bullet.h" 
#include "Drawable.h"
#include <vector>
#include "Game.h"

class Plane {
public:
    Plane(int startX, int startY, int speed);
    ~Plane(); // delete the bullets

    void move(window& win);  // move and draw the plane
    void draw(window& w);

    void fireBullet(); // fire them bullets

private:
    int x, y;
    int p_speed;
    std::vector<Bullet*> bullets; // store bullets
};
