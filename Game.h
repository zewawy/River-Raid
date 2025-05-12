#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Toolbar.h"
#include "fuel.h"
#include <vector>              
#include "Jet.h"
#include "Helicopter.h"
#include "Bullet.h"
#include "plane.h"
#include "Background.h"
#include "StatusBar.h"

class Game {
private:
	window* pWind;	//Pointer to the CMU graphics window
	Toolbar* gameToolbar;
	std::vector<FuelDepot*> fuelDepots;
	std::vector<Jet*> jets;
	std::vector<Helicopter*> helicopters;
	std::vector<Bullet*> bullet;

	Plane* pPlane;
	Plane* plane;
	Background* bg;
	StatusBar* status;





public:
	Game();
	~Game();

	clicktype getMouseClick(int& x, int& y) const; //Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window
	void createToolbar();
	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go();

	void updateAll();

	window* getWind() const;		//returns a pointer to the graphics window

	void drawAll() const;


};

