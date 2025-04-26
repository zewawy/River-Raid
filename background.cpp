#include "Background.h"
#include "GameConfig.h"

Background::Background(window* w) : pWind(w), offsetY(0) {}

void Background::draw() {
    int screenWidth = 1200;
    int screenHeight = 600;
    int riverWidth = 400;

    int landWidth = (screenWidth - riverWidth) / 2;

    // Draw Left Land
    pWind->SetPen(DARKGREEN, 1);
    pWind->SetBrush(DARKGREEN);
    pWind->DrawRectangle(0, 0, landWidth, screenHeight);

    // Draw River
    pWind->SetPen(LIGHTBLUE, 1);
    pWind->SetBrush(LIGHTBLUE);
    pWind->DrawRectangle(landWidth, 0, landWidth + riverWidth, screenHeight);

    // Draw Right Land
    pWind->SetPen(DARKGREEN, 1);
    pWind->SetBrush(DARKGREEN);
    pWind->DrawRectangle(landWidth + riverWidth, 0, screenWidth, screenHeight);

    // Optional: river border lines
    pWind->SetPen(BLACK, 2);
    pWind->DrawLine(landWidth, 0, landWidth, screenHeight);
    pWind->DrawLine(landWidth + riverWidth, 0, landWidth + riverWidth, screenHeight);
}


void Background::scrollDown(int speed) {
    offsetY += speed;

    if (offsetY >= 600) offsetY = 0;  // Reset when full screen height is scrolled

    int screenWidth = 1200;
    int screenHeight = 600;
    int riverWidth = 400;
    int landWidth = (screenWidth - riverWidth) / 2;

    // Clear background (optional if using full redraw)
    pWind->SetBrush(config.bkGrndColor);  // If you have a config color
    pWind->SetPen(config.bkGrndColor, 1);
    pWind->DrawRectangle(0, 0, screenWidth, screenHeight);

    // Draw Top Part
    for (int i = -offsetY; i < screenHeight; i += screenHeight) {
        // Left Land
        pWind->SetPen(DARKGREEN, 1);
        pWind->SetBrush(DARKGREEN);
        pWind->DrawRectangle(0, i, landWidth, i + screenHeight);

        // River
        pWind->SetPen(LIGHTBLUE, 1);
        pWind->SetBrush(LIGHTBLUE);
        pWind->DrawRectangle(landWidth, i, landWidth + riverWidth, i + screenHeight);

        // Right Land
        pWind->SetPen(DARKGREEN, 1);
        pWind->SetBrush(DARKGREEN);
        pWind->DrawRectangle(landWidth + riverWidth, i, screenWidth, i + screenHeight);

        // River borders
        pWind->SetPen(BLACK, 2);
        pWind->DrawLine(landWidth, i, landWidth, i + screenHeight);
        pWind->DrawLine(landWidth + riverWidth, i, landWidth + riverWidth, i + screenHeight);
    }
}

