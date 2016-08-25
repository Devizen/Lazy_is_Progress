#include "characters.h"
#include "level1.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void motiondetect()
{
	bool bSomethingHappened = false;
	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	switch (load)
	{
	case levelzeroa:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.115; // 125ms should be enough
		}
		break;

	/*case levelzerob:*/
		//For First Character
		//Move Right
		//if (g_enemy.m_cLocation.X > 0 &&
		//	(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.X++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.X++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Left
		//if (g_enemy.m_cLocation.X > 0 &&
		//	g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.X--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.X--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Down
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
		//	map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	//if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] == map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] &&
		//	//	door2 == true)
		//	//{
		//	//	g_enemy.m_cLocation.Y++;
		//	//	bSomethingHappened = true;
		//	//}
		//	//else if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] == map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] &&
		//	//	door4 == true)
		//	//{
		//	//	g_enemy.m_cLocation.Y++;
		//	//	bSomethingHappened = true;
		//	//}
		//	if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] &&
		//		door4 == true)
		//	{
		//		g_enemy.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] &&
		//		door2 == true)
		//	{
		//		g_enemy.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false && door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X ] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.Y++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//	else if (door4 == true && 
		//		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] !=
		//		map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X])
		//	{
		//		g_enemy.m_cLocation.Y++;
		//	}
		//}

		////Move Up
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
		//	map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.Y--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.Y--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////For Second Character
		////Move Right
		//if (g_enemy2.m_cLocation.X > 0 &&
		//	(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		//	map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.X++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.X++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Left
		//if (g_enemy2.m_cLocation.X > 0 &&
		//	g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		//	map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.X--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.X--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Down
		//if (g_enemy2.m_cLocation.Y > 0 &&
		//	(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		//	map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] || 
		//			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.Y++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Up
		//if (g_enemy2.m_cLocation.Y > 0 &&
		//	(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		//	map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.Y--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.Y--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}
	/*	break;*/

	case levelone:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;

		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			check = downd;
			if (door1 == true)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			else if (door1 == false)
			{
				if (/*map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X] ||*/
					releasestate(g_enemy2, release_enemy) == true ||
					releasestate(g_enemy2, release_enemy1) == true || 
					releasestate(g_enemy2, release_enemy2) == true || 
					releasestate(g_enemy2, release_enemy3) == true || 
					releasestate(g_enemy2, release_enemy4) == true || 
					releasestate(g_enemy2, release_enemy5) == true || 
					releasestate(g_enemy2, release_enemy6) == true || 
					releasestate(g_enemy2, release_enemy7) == true || 
					releasestate(g_enemy2, release_enemy8) == true)
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
			else
			{

			}
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		}
		break;

	case leveltwo:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		}
		break;
	}

	//if (bSomethingHappened)
	//{
	//	// set the bounce time to some time in the future to prevent accidental triggers
	//	ai_BounceTime = g_dElapsedTime + 0.175; // 125ms should be enough
	//}
}

//Done by Eugene.
void rendercharacters()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD charColor3 = 0x2B;
	WORD yellow = 0xFFE0;


	switch (load)
	{
	case levelzeroa:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		break;

	case levelzerob:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		//g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		//g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//Doors
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, charColor);

		//Close Doors
		g_Console.writeToBuffer(closedoor1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(closedoor2.m_cLocation, (char)219, charColor);

		//Levers
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever3.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever4.m_cLocation, (char)219, yellow);

		//Boxes
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxtwo.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxthree.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxfour.m_cLocation, (char)254, charColor);

		break;

	case levelone:

		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//Door
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

		//Lever
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);

		//Box
		g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, charColor);

		//Release A.I
		g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy2.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy3.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy4.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy5.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy6.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy7.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy8.m_cLocation, (char)219, charColor);
		break;

	case leveltwo:
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

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//platform
		g_Console.writeToBuffer(g_platform.m_cLocation, (char)254, charColor3);

		//powerup
		COORD C;
			C.X = 23;
		C.Y = 10;

		g_Console.writeToBuffer(C, (char)206, charColor3);
		break;
	}
}