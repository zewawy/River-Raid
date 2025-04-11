#include "fuelDepots.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	
/*
void fuel(window& w, int x, int y) {
	w.SetPen(GRAY);
	w.SetBrush(GRAY);
	w.DrawRectangle(x, y, x + 50, y + 5);


	w.SetPen(RED);
	w.SetBrush(RED);
	w.DrawRectangle(x + 5, y + 5, x + 45, y + 70);

	w.SetPen(GRAY);
	w.SetBrush(GRAY);
	w.DrawRectangle(x + 12.5, y + 10, x + 37.5, y + 35);

	w.SetPen(DARKGRAY);
	w.SetBrush(DARKGRAY);
	w.DrawRectangle(x + 12.5, y + 35, x + 37.5, y + 40);


	w.SetPen(DARKGRAY);
	w.SetBrush(DARKGRAY);
	w.DrawRectangle(x + 12.5, y + 55, x + 22.5, y + 62.5);


	w.SetPen(GRAY);
	w.SetBrush(GRAY);
	w.DrawRectangle(x + 5, y + 70, x + 45, y + 95);

	w.SetPen(DARKGRAY);
	w.SetBrush(DARKGRAY);
	w.DrawRectangle(x, y + 95, x + 50, y + 100);

}
*/

/*void jets(window& w, int x, int y) {
    w.SetPen(BLACK);
    w.SetBrush(LIGHTBLUE);
    w.DrawCircle(x+30, y+30, 30);

    w.SetPen(BLACK);
    w.SetBrush(DARKSLATEGRAY);
    w.DrawEllipse(x-30,y+27 , x+90 ,y+60);

    w.SetPen(BLACK);
    w.SetBrush(LIGHTBLUE);
    w.DrawCircle(x,y+42,3);

    w.SetPen(BLACK);
    w.SetBrush(LIGHTBLUE);
    w.DrawCircle(x+30, y + 42, 3);

    w.SetPen(BLACK);
    w.SetBrush(LIGHTBLUE);
    w.DrawCircle(x+60, y + 42, 3);
}*/



void helicopter(window& w, int x, int y)
{

    w.SetBrush(BLACK);
    w.DrawEllipse(x+138, y+71, x+142, y+51, FILLED);
    w.DrawEllipse(x+138, y+73.4, x+142, y+93.4, FILLED);
    w.DrawEllipse(x+87, y+44, x+107, y+48, FILLED);
    w.DrawEllipse(x+113, y+44, x+133, y+48, FILLED);

    w.SetPen(BLACK);
    w.DrawLine(x+104, y+87, x+104, y+94);
    w.DrawLine(x+118, y+87, x+118, y+94);
    w.SetBrush(GRAY);
    w.DrawRectangle(x+106, y+46, x+114, y+56, FILLED);

    w.SetBrush(GRAY);
    w.DrawArc(x+104, y+64, x+140, y+80, 270, 90);
    w.SetPen(BLACK);
    w.SetBrush(GRAY);
    w.DrawEllipse(x+130, y+54, x+80, y+90, FILLED);
    w.SetBrush(WHITE);
    w.DrawCircle(x+110, y+70, 12, FILLED);
    w.DrawArc(x+92, y+94, x+134, y+102, 0, 180);

}



