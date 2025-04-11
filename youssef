#include <iostream>
#include <sstream>
#include <cmath>

#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"



int tank() {  //tank
	window w(1600, 800, 200, 100);
	w.ChangeTitle("enemy tank");
	w.SetPen(BLACK);
	w.SetBrush(FORESTGREEN);
	w.DrawRectangle(800, 200, 1100, 600);   // tank body


	w.SetBrush(SLATEGREY);
	w.DrawRectangle(900, 490, 1000, 540);   // ventilation system

	w.SetBrush(DARKGREEN);
	int lsidex[] = { 790,870,870,820,820,870,870,790 };   // left side bumper aixs
	int lsidey[] = { 180,180,240,240,560,560,620,620 };
	w.DrawPolygon(lsidex, lsidey, 8, FILLED);
	int rsidex[] = { 1110,1030,1030,1080,1080,1030,1030,1110 };   //right side bumper axis
	int rsidey[] = { 180,180,240,240,560,560,620,620 };
	w.DrawPolygon(rsidex, rsidey, 8, FILLED);

	int turret_x[] = { 910,990,1060,990,910,840 }; // turret axis
	int turret_y[] = { 260,260,360,460,460,360 };
	w.DrawPolygon(turret_x, turret_y, 6, FILLED);

	w.SetBrush(GRAY);
	int tbody_x[] = { 888,1012,1055,985,915,845 };  // turret cover? (idk the name of this thing) axis
	int tbody_y[] = { 300,300,360,455,455,360 };
	w.DrawPolygon(tbody_x, tbody_y, 6, FILLED);
	w.DrawRectangle(915, 295, 985, 270); // other vent above cover

	w.SetBrush(SLATEGREY);
	w.SetPen(SLATEGRAY);
	w.DrawCircle(935, 420, 20);   //random circles at this point
	w.DrawCircle(965, 420, 20);
	w.SetPen(BLACK);

	w.SetBrush(FORESTGREEN);
	w.DrawCircle(920, 360, 35);  //entrance
	w.DrawCircle(985, 355, 30);  // other entrance???
	w.SetBrush(BLACK);
	w.DrawCircle(985, 375, 5); // handles
	w.DrawCircle(920, 340, 8);

	w.SetBrush(DARKGREEN);
	int barrel_x[] = { 935,965,960,940 };  // tank barrel axis
	int barrel_y[] = { 260,260,40,40 };
	w.DrawPolygon(barrel_x, barrel_y, 4);
	return 0;
}


int heli() {   // helicopter
	window w(1600, 800, 200, 100);
	w.SetPen(BLACK);
	w.SetBrush(DARKKHAKI);
	w.DrawRectangle(950, 300, 1100, 500, FILLED, 90, 90); // tail
	w.DrawRectangle(600, 340, 450, 460, FILLED, 70, 70);  // nose

	w.SetPen(DARKKHAKI);
	w.DrawTriangle(550, 300, 550, 340, 477, 340);  //triangles 3ashan el da5la el fo2 dy(nose)
	w.DrawTriangle(550, 500, 550, 459, 477, 459);

	w.SetPen(BLACK);
	w.DrawRectangle(700, 250, 1000, 550, FILLED, 100, 150); // dol keda 3ashan el selem
	w.SetPen(DARKKHAKI);
	w.DrawTriangle(740, 499, 740, 548, 650, 499);
	w.DrawTriangle(740, 300, 740, 251, 650, 300);

	w.SetPen(BLACK);
	w.DrawRectangle(550, 300, 1000, 500); //body (ta7t 3ashan ye3mel cover lel tail wel nose
	w.DrawLine(550, 300, 477, 340);   // dy wel ta7taha 3ashan ta7deed el 7orof beto3 el triangles (fo2)
	w.DrawLine(550, 500, 477, 459);   // ta7t
	w.DrawLine(650, 300, 740, 251); // dy wel ta7taha lel triangles el tanya beta3et el selem (fo2)
	w.DrawLine(650, 500, 740, 548); //ta7t

	w.SetBrush(LIGHTCYAN);
	w.DrawArc(477, 340, 625, 460, 90, 270, FILLED);  // glass

	w.SetBrush(DARKKHAKI);
	w.DrawRectangle(530, 370, 630, 430, FILLED, 80, 80);  //setup for fans
	w.DrawRectangle(970, 370, 1070, 430, FILLED, 80, 80);

	w.SetBrush(BLACK);
	w.DrawRectangle(545, 395, 555, 405); // center of left fan
	int lu_x[] = { 550,545,530,525,250,260 };    // left upper wing of left fan
	int lu_y[] = { 395,400,385,390,115,105 };
	w.DrawPolygon(lu_x, lu_y, 6);
	int ru_x[] = { 555,550,565,560,835,845 };  // right upper wing
	int ru_y[] = { 400,395,380,375,100,110 };
	w.DrawPolygon(ru_x, ru_y, 6);
	int ld_x[] = { 545,550,535,540,260,250 };  // left lower wing
	int ld_y[] = { 400,405,420,425,700,690 };
	w.DrawPolygon(ld_x, ld_y, 6);
	int rd_x[] = { 550,555,570,575,850,840 };  // right lower wing
	int rd_y[] = { 405,400,415,410,685,695 };
	w.DrawPolygon(rd_x, rd_y, 6);

	w.DrawRectangle(995, 395, 1005, 405);  // center of right fan
	int lu_x2[] = { 1000,995,980,975,700,710 };   // left upper wing of right fan
	int lu_y2[] = { 395,400,385,390,115,105 };
	w.DrawPolygon(lu_x2, lu_y2, 6);
	int ru_x2[] = { 1005,1000,1015,1010,1285,1295 }; // right upper wing
	int ru_y2[] = { 400,395,380,375,100,110 };
	w.DrawPolygon(ru_x2, ru_y2, 6);
	int ld_x2[] = { 995,1000,985,990,710,700 };  // left lower iwng
	int ld_y2[] = { 400,405,420,425,700,690 };
	w.DrawPolygon(ld_x2, ld_y2, 6);
	int rd_x2[] = { 1000,1005,1020,1025,1300,1290 };  // right lower wing
	int rd_y2[] = { 405,400,415,410,685,695 };
	w.DrawPolygon(rd_x2, rd_y2, 6);
	return 0;
}





void player_plane() {
    window w(2000, 1000, 5, 5);
    w.ChangeTitle("Plane Movement Test");

    int x = 960; // Starting X
    int y = 770; // Starting Y
    int p_speed = 10;

    while (true) {
        
        w.SetBrush(WHITE);    // or whatever your background color is
        w.SetPen(WHITE);      // match the pen too, in case any outlines show
        w.DrawRectangle(0, 0, 2000, 1000, FILLED); // fill the whole screen


        // Draw the plane at current (x, y)
        w.SetPen(LIGHTGRAY, 5);
        w.DrawLine(x, y, x + 80, y); // wingspan
        w.SetPen(BLACK);
        w.SetBrush(GRAY);
        w.DrawRectangle(x + 20, y + 30, x + 61, y + 81); // body
        w.DrawArc(x + 20, y + 60, x + 60, y, 0, 180, FILLED); // nose
        w.DrawTriangle(x + 20, y + 80, x + 60, y + 80, x + 40, y + 120); // tail
        w.DrawTriangle(x + 33, y + 105, x + 33, y + 130, x - 10, y + 130); // left back wing
        w.DrawTriangle(x + 47, y + 105, x + 47, y + 130, x + 90, y + 130); // right back wing
        w.DrawRectangle(x + 33, y + 105, x + 48, y + 131); // mid-wing connector

        // Left wing
        int ipX[] = { x + 20, x + 20, x - 60, x - 60 };
        int ipY[] = { y + 35, y + 75, y + 60, y + 50 };
        w.DrawPolygon(ipX, ipY, 4, FILLED);

        // Right wing
        int ipm[] = { x + 60, x + 60, x + 140, x + 140 };
        int ipn[] = { y + 35, y + 75, y + 60, y + 50 };
        w.DrawPolygon(ipm, ipn, 4, FILLED);

        if (GetKeyState(87)) {
            y -= p_speed; // Move up
        }
        if (GetKeyState(83)) {
            y += p_speed; // Move down
        }
        if (GetKeyState(65)) {
            x -= p_speed; // Move left
        }
        if (GetKeyState(68)) {
            x += p_speed; // Move right
        }
     

        w.UpdateBuffer();
        Pause(30);
      
    }
   
}

