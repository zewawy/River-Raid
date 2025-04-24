
#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
private: int speed; int scale;

public: Bullet(Game* pGame, point startPos, int speed = 10, int scale = 1); 

	  void move();                   // Moves the bullet upward  
	  void draw() const override;   // Draws the bullet on screen  
	  bool isOffScreen() const;     // Checks if bullet went out of screen  
};