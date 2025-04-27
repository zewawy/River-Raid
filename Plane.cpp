#include "Plane.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"

Plane::Plane(Game* game, int startX, int startY, int speed) {
    pGame = game;
    x = startX;
    y = startY;
    p_speed = speed;
}

Plane::~Plane()
{
    for (auto b : bullets) {
        delete b;
    }
    bullets.clear();
}



void Plane::move(window & win) {
    if (GetKeyState(87) & 0x8000) y -= p_speed; // w
    if (GetKeyState(83) & 0x8000) y += p_speed; // s
    if (GetKeyState(65) & 0x8000) x -= p_speed; // a
    if (GetKeyState(68) & 0x8000) x += p_speed; // d

    if (GetKeyState(VK_SPACE) & 0x8000) {
        fireBullet();
    } // spacebar

    for (auto bullet : bullets) {
        bullet->move();  
    }   // to move the bullets
}


void Plane::draw(window& w) {
    w.SetPen(LIGHTGRAY, 5);
    w.DrawLine(x, y, x + 80, y); // wings
    w.SetPen(BLACK);
    w.SetBrush(GRAY);
    w.DrawRectangle(x + 20, y + 30, x + 61, y + 81);
    w.DrawArc(x + 20, y + 60, x + 60, y, 0, 180, FILLED);
    w.DrawTriangle(x + 20, y + 80, x + 60, y + 80, x + 40, y + 120);
    w.DrawTriangle(x + 33, y + 105, x + 33, y + 130, x - 10, y + 130);
    w.DrawTriangle(x + 47, y + 105, x + 47, y + 130, x + 90, y + 130);
    w.DrawRectangle(x + 33, y + 105, x + 48, y + 131);

    int ipX[] = { x + 20, x + 20, x - 60, x - 60 };
    int ipY[] = { y + 35, y + 75, y + 60, y + 50 };
    w.DrawPolygon(ipX, ipY, 4, FILLED);

    int ipm[] = { x + 60, x + 60, x + 140, x + 140 };
    int ipn[] = { y + 35, y + 75, y + 60, y + 50 };
    w.DrawPolygon(ipm, ipn, 4, FILLED);
   
    for (auto bullet : bullets) {  // to draw the bullets to fire
        bullet->draw();
    }
}

void Plane::fireBullet() {
    // Spawn bullet at center of the plane
    point spawn;
    spawn.x = x + 40; // center
    spawn.y = y;      // top of plane

    Bullet* newBullet = new Bullet(pGame, spawn);  // no pointer for now but it should be Game* so add it ya kevin lama te3mel kol 7aga
    bullets.push_back(newBullet);
}
