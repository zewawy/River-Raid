#pragma once
#include "GameObject.h"

class Helicopter : public GameObject
{
public:
    Helicopter(Game* pGame, point ref);
    void draw() const override;
};