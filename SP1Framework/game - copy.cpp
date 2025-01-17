// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "health.h"

//Add-ons
#include <fstream>
#include <string>

using std::vector;
using namespace std;

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];


// Game specific variables here
SGameChar   g_sChar;
SGameChar	g_nChar;
SGameChar	g_menu;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(80, 25, "SP1 Framework");

const unsigned int x = 80;
const unsigned int y = 25;

char collision[y][x];

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;

	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;

	g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
	g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
	g_sChar.m_bActive = true;
	g_nChar.m_cLocation.X = g_Console.getConsoleSize().X / 4;
	g_nChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 4;
	g_nChar.m_bActive = true;
	g_sChar.health = 15; // Set the initial health of the player

	//Menu Arrow
	g_menu.m_cLocation.X = 30;
	g_menu.m_cLocation.Y = 8;

	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(0, 16, L"Consolas");
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
	g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
	g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	g_abKeyPressed[K_RETURN] = isKeyPressed(VK_RETURN);
	g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
	// get the delta time
	g_dElapsedTime += dt;
	g_dDeltaTime = dt;

	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	}
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	clearScreen();      // clears the current screen and draw from scratch 
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: renderSplashScreen();
		break;
	case S_MENU: menu();
		break;
	case S_GAME: renderGame();
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
		//g_eGameState = S_GAME;
		g_eGameState = S_MENU;
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();    // moves the character, collision detection, physics, etc
	// sound can be played here too.
}

void moveCharacter()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	COORD c;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character

	if (g_abKeyPressed[K_UP])
	{
		if (g_sChar.m_cLocation.Y > 0)
		{
			g_sChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		if (g_nChar.m_cLocation.Y > 0)
		{
			g_nChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LEFT])
	{
		if (g_sChar.m_cLocation.X > 0)
		{
			g_sChar.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_nChar.m_cLocation.X > 0)
		{
			g_nChar.m_cLocation.X--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_DOWN])
	{
		if (g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
		{
			g_sChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_nChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
		{
			g_nChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_RIGHT])
	{
		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
		{
			g_sChar.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_nChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
		{
			g_nChar.m_cLocation.X++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_SPACE])
	{
		g_sChar.m_bActive = !g_sChar.m_bActive;
		bSomethingHappened = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}
void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
		g_bQuitGame = true;
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer();
}

void renderSplashScreen()  // renders the splash screen
{
	string line;
	ifstream myfile("Text/splashScreen.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 9;
	c.Y = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
		myfile.close();
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found");
	}

	//memset is clear

}

void menu()
{
	string line;
	ifstream myfile("Text/menu.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 20;
	c.Y = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
		myfile.close();
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found");
	}

	g_Console.writeToBuffer(g_menu.m_cLocation, '>');

	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_UP] && 
		g_menu.m_cLocation.Y > 8 && 
		g_menu.m_cLocation.Y <= 10)
	{
		g_menu.m_cLocation.Y--;
		bSomethingHappened = true;
	}

	if (g_abKeyPressed[K_DOWN] &&
		g_menu.m_cLocation.Y < 10 && 
		g_menu.m_cLocation.Y >= 8)
	{
		g_menu.m_cLocation.Y++;
		bSomethingHappened = true;
	}

	if (g_menu.m_cLocation.Y == 8 && g_abKeyPressed[K_RETURN])
	{
		g_eGameState = S_GAME;
	}

	if (g_menu.m_cLocation.Y == 10 && g_abKeyPressed[K_RETURN])
	{
		g_bQuitGame = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}

}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderhealth(&g_Console, g_sChar.health); // draw health to the screen
	renderCharacter();  // renders the character into the buffer
}

void renderMap()
{

	////   // Set up sample colours, and output shadings
	//const WORD colors[] = {
	//	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	//	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	//};

	//COORD c;
	//c.X = 0;
	//c.Y = 0;

	//for (unsigned int i = 0; i < 70; ++i)
	//{
	//	c.X = i;
	//	c.Y = 0;
	//	map.push_back('X');
	//	g_Console.writeToBuffer(c, map[i]);
	//}

	string line;
	ifstream myfile("Text/level1.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 0;
	int increase = 0;
	if (myfile.is_open())
	{
		//for (unsigned int height = 0; height < y; height++)
		//{
		//	for (unsigned int width = 0; width < x; width++)
		//	{
		//		myfile >> collision[width][height];
		//	}
		//}

		while (getline(myfile, line))
		{

			for (int j = 0; j < line.length(); j++)
			{
				collision[increase][j] = line[j];
			}
			increase++;
		}
		myfile.close();
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found");
	}

	increase = 0;
	while (increase != 25)
	{
		for (unsigned int height = 0; height < x; height++)
		{
			g_Console.writeToBuffer(c, collision[increase][height]);
		}
		increase++;
		c.Y++;
	}
	
}

void renderCharacter()
{
	// Draw the location of the character
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	if (g_sChar.m_bActive)
	{
		charColor = 0x0A;
	}
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

	// Draw the location of the character
	if (g_nChar.m_bActive)
	{
		charColor = 0x0C;
	}
	g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

}

void renderFramerate()
{
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / g_dDeltaTime << "fps";
	c.X = g_Console.getConsoleSize().X - 9;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	// displays the elapsed time
	ss.str("");
	ss << g_dElapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str(), 0x59);
}
void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}
