#include "Jet.h"
#include "Game.h" 
#include "GameConfig.h"
#include <iostream>
 
Jet::Jet(Game* pGame, point ref, int spd)
    : GameObject(pGame, ref, 60, 30, LIGHTBLUE, DARKSLATEGRAY),
    speed(spd), direction(10) {
}


void Jet::move() {
    RefPoint.x += direction * speed;

    // boundary between x = 400 and x = 800
    if (RefPoint.x <= 400 || RefPoint.x + width >= 800) {
        direction *= -1; // reverse direction
    }
}
void Jet::draw() const
{
    window* w = pGame->getWind();


    int x = RefPoint.x;
    int y = RefPoint.y;

    w->SetPen(BLACK);
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(x + 15, y + 15, 15);

    w->SetPen(BLACK);
    w->SetBrush(DARKSLATEGRAY);
    w->DrawEllipse(x - 15, y + 13.5, x + 45, y + 30);

    w->SetPen(BLACK);
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(x, y + 21, 1.5);
    w->DrawCircle(x + 15, y + 21, 1.5);
    w->DrawCircle(x + 30, y + 21, 1.5);
}
