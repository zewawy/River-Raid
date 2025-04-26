#include "Background.h"
#include "GameConfig.h"
#include <cstdlib>

Background::Background(window* w) : pWind(w), offsetY(0) {}
void Background::draw() {
    int screenWidth = 1200;
    int screenHeight = 600;
    int riverWidth = 400;
    int landWidth = (screenWidth - riverWidth) / 2;

    for (int i = 0; i < 20; ++i) {  // 20 trees
        Tree tree;
        if (i % 2 == 0) {
            tree.x = rand() % (landWidth - 30);  // Left land
        }
        else {
            tree.x = landWidth + riverWidth + (rand() % (landWidth - 30)); // Right land
        }
        tree.y = rand() % (screenHeight - 30);
        trees.push_back(tree);
    }

    // Left Land
    pWind->SetPen(DARKGREEN, 1);
    pWind->SetBrush(DARKGREEN);
    pWind->DrawRectangle(0, 0, landWidth, screenHeight);

    // Right Land
    pWind->SetPen(DARKGREEN, 1);
    pWind->SetBrush(DARKGREEN);
    pWind->DrawRectangle(landWidth + riverWidth, 0, screenWidth, screenHeight);

    // River
    pWind->SetPen(LIGHTBLUE, 1);
    pWind->SetBrush(LIGHTBLUE);
    pWind->DrawRectangle(landWidth, 0, landWidth + riverWidth, screenHeight);

    // Borders
    pWind->SetPen(BLACK, 2);
    pWind->DrawLine(landWidth, 0, landWidth, screenHeight);
    pWind->DrawLine(landWidth + riverWidth, 0, landWidth + riverWidth, screenHeight);

    //Draw Trees Randomly on Left and Right Land
    for (int i = 0; i < 10; ++i) { // 10 trees on each side
        int treeXLeft = rand() % (landWidth - 30); // random X left side
        int treeYLeft = rand() % (screenHeight - 30);

        int treeXRight = landWidth + riverWidth + (rand() % (landWidth - 30)); // random X right side
        int treeYRight = rand() % (screenHeight - 30);

        // Left Tree
        pWind->SetPen(DARKGREEN, 1);
        pWind->SetBrush(GREEN);
        pWind->DrawCircle(treeXLeft, treeYLeft, 15);

        // Right Tree
        pWind->SetPen(DARKGREEN, 1);
        pWind->SetBrush(GREEN);
        pWind->DrawCircle(treeXRight, treeYRight, 15);
    }
}

void Background::scrollDown(int speed) {
    offsetY += speed;
    if (offsetY >= 600) offsetY = 0;

    int screenWidth = 1200;
    int screenHeight = 600;
    int riverWidth = 400;
    int landWidth = (screenWidth - riverWidth) / 2;

    // Clear screen
    pWind->SetBrush(config.bkGrndColor);
    pWind->SetPen(config.bkGrndColor, 1);
    pWind->DrawRectangle(0, 0, screenWidth, screenHeight);

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

    // Draw Borders
    pWind->SetPen(BLACK, 2);
    pWind->DrawLine(landWidth, 0, landWidth, screenHeight);
    pWind->DrawLine(landWidth + riverWidth, 0, landWidth + riverWidth, screenHeight);

    // Move and draw trees
    for (auto& tree : trees) {
        tree.y += speed;

        if (tree.y > screenHeight) {
            tree.y = 0;
            if (tree.x < landWidth) {
                tree.x = rand() % (landWidth - 30);
            }
            else {
                tree.x = landWidth + riverWidth + (rand() % (landWidth - 30));
            }
        }

        // Draw tree trunk
        pWind->SetPen(BROWN, 1);
        pWind->SetBrush(BROWN);
        pWind->DrawRectangle(tree.x - 3, tree.y + 15, tree.x + 3, tree.y + 30);

        // Draw tree leaves
        pWind->SetPen(DARKGREEN, 1);
        pWind->SetBrush(GREEN);
        pWind->DrawCircle(tree.x, tree.y, 15);
    }

}
