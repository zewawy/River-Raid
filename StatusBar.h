#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"
#include <string>

class StatusBar {
private:
    window* pWind;
    int points, speed, lives, fuel;

public:
    StatusBar(window* w);
    void draw() const;

    void updatePoints(int p);
    void updateSpeed(int s);
    void updateLives(int l);
    void updateFuel(int f);
};
