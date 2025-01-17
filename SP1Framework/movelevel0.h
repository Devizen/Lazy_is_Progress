#include "game.h"
#include "main.h"

//Linking Console.
extern Console g_Console;

//Linking Map.
extern char map[25][80];

//Linking game states.
extern LEVELS load;

//Linking characters
extern SGameChar g_sChar;
extern SGameChar g_nChar;

extern objects
boxone,
boxtwo,
boxthree,
boxfour,
boxfive,
g_door1,
g_door2,
g_door3,
g_door4,
closedoor1,
closedoor2,
g_lever1,
g_lever2,
g_lever3,
g_lever4,
g_box1;

extern RELEASE
release_enemy,
release_enemy1,
release_enemy2,
release_enemy3,
release_enemy4,
release_enemy5,
release_enemy6,
release_enemy7,
release_enemy8;

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double g_dBounceTimeBoost;

extern bool g_abKeyPressed[K_COUNT];