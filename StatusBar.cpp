#include "StatusBar.h"
#include "GameConfig.h"

StatusBar::StatusBar(window* w) : pWind(w), points(0), speed(5), lives(5), fuel(50) {}

void StatusBar::draw() const {
    pWind->SetPen(WHITE);
    pWind->SetFont(20, BOLD, BY_NAME, "Arial");

    std::string status = "Points: " + std::to_string(points)
        + "                     |                     Game Speed: " + std::to_string(speed)
        + "                     |                     Lives: " + std::to_string(lives)
        + "                     |                     Fuel: " + std::to_string(fuel);

    pWind->DrawString(10, pWind->GetHeight() - config.statusBarHeight + 10, status);
}

void StatusBar::updatePoints(int p) { points = p; }
void StatusBar::updateSpeed(int s) { speed = s; }
void StatusBar::updateLives(int l) { lives = l; }
void StatusBar::updateFuel(int f) { fuel = f; }
