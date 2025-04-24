#include "Bullet.h" 
#include "GameConfig.h"
#include "Game.h" 


Bullet::Bullet(Game* pGame, point startPos, int spd, int scl) 
	: GameObject(pGame, startPos, 20, 60, DARKKHAKI, DARKKHAKI) { 
	speed = spd; scale = scl; 
}




void Bullet::move() { RefPoint.y -= speed; }

void Bullet::draw() const {
	window* w = pGame->getWind();

	int x = RefPoint.x;
	int y = RefPoint.y;

	int bxaxis[] = {
		x + 20 * scale, x + 20 * scale, x + 25 * scale, x + 45 * scale, x + 50 * scale,
		x + 50 * scale, x + 48 * scale, x + 48 * scale, x + 50 * scale, x + 50 * scale,
		x + 20 * scale, x + 20 * scale, x + 22 * scale, x + 22 * scale
	};

	int byaxis[] = {
		y + 100 * scale, y, y - 20 * scale, y - 20 * scale, y,
		y + 100 * scale, y + 100 * scale, y + 110 * scale, y + 110 * scale, y + 120 * scale,
		y + 120 * scale, y + 110 * scale, y + 110 * scale, y + 100 * scale
	};

	w->SetBrush(DARKKHAKI);
	w->SetPen(DARKKHAKI);
	w->DrawPolygon(bxaxis, byaxis, 14, FILLED);

	w->SetBrush(DARKGRAY);
	w->SetPen(DARKGRAY);

	int topHalfX[] = {
		x + 25 * scale, x + 25 * scale, x + 35 * scale, x + 45 * scale, x + 45 * scale
	};

	int topHalfY[] = {
		y - 20 * scale, y - 60 * scale, y - 90 * scale, y - 60 * scale, y - 20 * scale
	};

	w->DrawPolygon(topHalfX, topHalfY, 5, FILLED);
}

bool Bullet::isOffScreen() const { return RefPoint.y + height < config.toolBarHeight; }