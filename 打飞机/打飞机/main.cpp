#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
#include"plane.h"
#include"API.h"
#include"bullet.h"
#include "game.h"
using namespace std;
int main()
{
	system("color 21");
	srand((int)time(0));
	ios::sync_with_stdio(false);
	full_screen();
	HideCursor();
	system("color 0F");
	Game game;
	game.initgame();
	game.drawmenu();
	return 0;
}