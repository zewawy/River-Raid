#include "fuel.h"
#include "Game.h" 

FuelDepot::FuelDepot(Game* pGame, point ref)
    : GameObject(pGame, ref, 50, 100, RED, GRAY) {
}

void FuelDepot::draw() const
{
    window* w = pGame->getWind();

    int x = RefPoint.x;
    int y = RefPoint.y;

    w->SetPen(GRAY);
    w->SetBrush(GRAY);
    w->DrawRectangle(x, y, x + 25, y + 2.5);

    w->SetPen(RED);
    w->SetBrush(RED);
    w->DrawRectangle(x + 2.5, y + 2.5, x + 22.5, y + 35);

    w->SetPen(GRAY);
    w->SetBrush(GRAY);
    w->DrawRectangle(x + 6.25, y + 5, x + 18.25, y + 17.5);

    w->SetPen(DARKGRAY);
    w->SetBrush(DARKGRAY);
    w->DrawRectangle(x + 6.25, y + 17.5, x + 18.25, y + 20);
    w->DrawRectangle(x + 6.5, y + 27.5, x + 11.25, y + 31.25);

    w->SetPen(GRAY);
    w->SetBrush(GRAY);
    w->DrawRectangle(x + 2.5, y + 35, x + 22.5, y + 47.5);

    w->SetPen(DARKGRAY);
    w->SetBrush(DARKGRAY);
    w->DrawRectangle(x, y + 47.5, x + 25, y + 50);
}
