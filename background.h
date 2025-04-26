#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

class Background {
private:
    window* pWind;
    int offsetY;

public:
    Background(window* w);
    void draw();
    void scrollDown(int speed);
};