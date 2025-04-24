#include "Helicopter.h"
#include "Game.h" 

Helicopter::Helicopter(Game* pGame, point ref)
    : GameObject(pGame, ref, 100, 100, GRAY, BLACK) {
}  

void Helicopter::draw() const
{
    window* w = pGame->getWind();

    int x = RefPoint.x;
    int y = RefPoint.y;

    w->SetBrush(BLACK);
    w->DrawEllipse(x + 138, y + 71, x + 142, y + 51, FILLED);
    w->DrawEllipse(x + 138, y + 73.4, x + 142, y + 93.4, FILLED);
    w->DrawEllipse(x + 87, y + 44, x + 107, y + 48, FILLED);
    w->DrawEllipse(x + 113, y + 44, x + 133, y + 48, FILLED);

    w->SetPen(BLACK);
    w->DrawLine(x + 104, y + 87, x + 104, y + 94);
    w->DrawLine(x + 118, y + 87, x + 118, y + 94);

    w->SetBrush(GRAY);
    w->DrawRectangle(x + 106, y + 46, x + 114, y + 56, FILLED);

    w->SetBrush(GRAY);
    w->DrawArc(x + 104, y + 64, x + 140, y + 80, 270, 90);

    w->SetPen(BLACK);
    w->SetBrush(GRAY);
    w->DrawEllipse(x + 130, y + 54, x + 80, y + 90, FILLED);

    w->SetBrush(WHITE);
    w->DrawCircle(x + 110, y + 70, 12, FILLED);

    w->DrawArc(x + 92, y + 94, x + 134, y + 102, 0, 180);
}
