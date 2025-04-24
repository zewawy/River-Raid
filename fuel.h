#pragma once
#include "GameObject.h"

class FuelDepot : public GameObject
{
public:
    FuelDepot(Game* pGame, point ref);
    void draw() const override;
};
