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
g_door4,
g_lever1,
g_box1;

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double g_dBounceTimeBoost;

extern bool g_abKeyPressed[K_COUNT];