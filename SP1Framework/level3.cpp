#include "level3.h"
#include "characters.h"
#include "health.h"
#include "game.h"

//Done by Daniel.
void level3()
{
	string line = " ";
	string name = "Text/Level/level3.txt";
	loadlevel(name);

	COORD c;

	c.X = 0;
	c.Y = 0;

	for (int i = 0; i <= y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}

	COORD y;
	y.X = 15;
	y.Y = 15;

	rendercharacters();
	motiondetect();

	if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
		(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
	{
		//Set boolean to false so the health will not reset.
		restarthealth = false;
		//Deduct one health.
		g_sChar.health -= 1;
		//Revert the level settings.
		spawn();
	}

	if (g_nChar.m_cLocation.X == 49 &&
		g_nChar.m_cLocation.Y == 11 &&
		g_sChar.m_cLocation.X == 11 &&
		g_sChar.m_cLocation.Y == 11)
	{
		g_sChar.m_cLocation.X = 11;
		g_sChar.m_cLocation.Y = 10;

		g_nChar.m_cLocation.X = 49;
		g_nChar.m_cLocation.Y = 10;
		g_sChar.health = 3;

		load = mainscreen;

	}
	if (g_sChar.health < 1)
	{
		level = two;
		load = defeated;
		renderGame();
		rendercharacters();
	}
}