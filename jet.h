#pragma once
#include "GameObject.h"
#include "GameConfig.h"

class Jet : public GameObject
{
private:
    int speed;
    int direction;  // +1: right, -1: left

public:
    Jet(Game* pGame, point ref, int spd );
    void move();
    void draw() const override;
};
