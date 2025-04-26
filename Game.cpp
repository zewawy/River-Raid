#include "Game.h"
#include "GameConfig.h"
#include"fuel.h"
#include"Bullet.h"
#include"jet.h"
#include"Helicopter.h"
#include "plane.h"

Game::Game()
{
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	createToolbar();

	//3 - create and draw the backgroundPlayingArea


	//4- Create the Plane
	plane = new Plane(400, 600, 10);  // coordinates are an example we need to change according to the window size ya kevin

	//5- Create the Bullet
	//TODO: Add code to create and draw the Bullet

	//6- Create the enemies
	//TODO: Add code to create and draw enemies in random places

	//7- Create and clear the status bar
	clearStatusBar();

	// Add a new fuel object at position (100, 200)
	fuelDepots.push_back(new FuelDepot(this, { 600, 200 }));

	// Add a new Jet object at position (200, 150)
	jets.push_back(new Jet(this, { 600, 300 }));

	// Add a new helicopter object at position (250, 300)
	helicopters.push_back(new Helicopter(this, { 450, 400 }));

	bullet.push_back(new Bullet(this, { 300, 400 }));
}

Game::~Game()
{
}

clicktype Game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click

}

string Game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

window* Game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}

void Game::createToolbar() 
{
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new Toolbar(this, toolbarUpperleft, 0, config.toolBarHeight);
	gameToolbar->draw();
}

void Game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void Game::printMessage(string msg) const
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);

}

window* Game::getWind() const
{
	return pWind;
}

void Game::go() const
{
	
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - River Raid (CIE101-project) - - - - - - - - - -");

	do
	{
		
		printMessage("Ready...");
		drawAll();
		int x, y;
		getMouseClick(x, y);	//Get the coordinates of the user click
		//if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		//{
			//[1] If user clicks on the Toolbar
		if (y >= 0 && y < config.toolBarHeight)
		{
			isExit = gameToolbar->handleClick(x, y);
		}
		//}

	} while (!isExit);

}

void Game::drawAll()const {
	for (auto j : jets)
		j->draw();
	for (auto h : helicopters)
		h->draw();
	for (auto f : fuelDepots)
		f->draw();
	for (auto h : helicopters)
		h->draw();  // Loop through all Helicopter objects and draw them

	for (auto b : bullet)                  
		b->draw();
	
	plane->move(*pWind);
	
	plane->draw(*pWind);
}


