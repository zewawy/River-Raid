#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"
#include <vector>
using namespace std;

struct Tree {
    int x, y;
};

class Background {
private:
    window* pWind;
    int offsetY;
    vector<Tree> trees;

public:
    Background(window* w);
    void draw();
    void scrollDown(int speed);
};
