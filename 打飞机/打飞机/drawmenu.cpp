#pragma once
#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
#include"API.h"
#include"game.h"
#include"plane.h"
#include"Enemy.h"
using namespace std;
static void drawhelp(int flag)
{
	drawRow(4, 2, 197, ' '); 
	switch (flag)
	{
	case 0:SetPos(80, 4);cout << "简单的敌人：简单敌人有着较慢的移动速度。"; break;//困难
	case 1:SetPos(80, 4); cout << "冷酷的敌人：冷酷的敌人移动速度较快，难对付哟。"; break;//地狱
	case 2:SetPos(98, 4); cout << "选择飞机"; break;//机库
	case 3:SetPos(94, 4);cout<<"查看游戏故事背景"; break;//帮助
	case 4:SetPos(98, 4); cout << "退出游戏。"; break;//退出
	}
}
void Game::help()
{
	system("cls");
	drawFrame(1, 1, 198, 65, '=', 'H');
	SetPos(99, 3);
	cout << "W  M  G";
	SetPos(95, 62);
	cout << " 按 k 返回";
	drawRow(60, 2, 197, '-');
	drawRow(6, 2, 197, '-');
	SetPos(92, 63);
	cout << "Made by:wby ga lyf bzy ";
	drawFrame(70, 30, 128, 36, '-', '|');
	SetPos(97, 29);
	cout << "wmgnb!";
	SetPos(72, 31);
	cout << "    在遥远的wmg星球上，总有一些反动分子在侵扰着整个星球";
	SetPos(72, 32);

	cout << "的安宁，而wmg为了守护这个美丽jg的星球，特地派出三架战斗";
	SetPos(72, 33);
	cout << "机与敌交战，在不断的交战中，总是在wmg的注视下大胜而归，";
	SetPos(72, 34);
	cout << "使wmg星球回归平静。wmg也得以颐养天年，星球太平无事。";

	while (1)
	{
		if (_kbhit())
		{
			char x = _getch();
			if (x == 'k') drawmenu();
		}
	}
}
void Game::drawmenu()
{
	
	system("cls");
	Frame a[5];
	int flag = 0;
	for(int i=0;i<5;i++)
	a[i] = { (SHORT)45,(SHORT)i*11+9,(SHORT)75,(SHORT)i*11+13,0};
	SetPos(99,3);
	cout << "W  M  G";
	SetPos(92, 62);
	cout << "按 w,s 选择 按 k 确定";
	drawFrame(1, 1, 198, 65,'=','H');
	drawRow(60, 2, 197, '-');
	drawRow(6, 2, 197, '-');
	SetPos(92, 63);
	cout << "Made by:wby ga lyf bzy ";
	SetPos(55, 11);
	cout << "1.困难难度";
	drawhelp(flag);
	SetPos(55, 22);
	cout << "2.地狱难度";
	SetPos(57, 33);
	cout << "3.机库";
	SetPos(55, 44);
	cout << "4.故事背景";
	SetPos(58, 55);
	cout << "退出";
	SetPos(151, 11);
	for(int i=0;i<5;i++)
	drawFrame(a[i], '-', '|');
	plane.drawplane({ 151,45 });
	smallEnemy gmw;
	middleEnemy mgw;
	highEnemy wmg;
	gmw.init = 0;
	mgw.init = 0;
	while (1)
	{
		wmg.drawenemy({140, 13});
		gmw.drawenemy({ 138,30 });
		mgw.drawenemy({ 157,36 });
		plane.drawfire();
		Sleep(150);

		//	Frameblink();
		if (a[flag].flag == 0)
		{
			
			drawFrame(a[flag], '\0', '\0');
			a[flag].flag = 1;
		}
		else
		{
			drawFrame(a[flag], '-', '|');
			a[flag].flag = 0;
		}
		if (_kbhit())
		{
			char x = _getch();
			switch (x)
			{
			case 's':
			case 'S':
				drawFrame(a[flag], '-', '|');
				if (flag < 4) {
					flag++;
					drawhelp(flag);
				}
				break;
			case 'W':
			case 'w':
				drawFrame(a[flag], '-', '|');
				if (flag > 0) {
					flag--;
					drawhelp(flag);
				}
				break;
			case 'K':
			case 'k':
				switch (flag)
				{
				case 1: level=3; //地狱
				case 0: system("cls"); drawplay(); Playing(); break;//困难
						
				case 2:drawjiku(); break;//机库
				case 3:help(); //帮助
				case 4:exit(0);//退出
				}
				break;
			case'Q':
			case 'q':exit(0);
			
			}
		}

	}
}	
//int main()
//{
//	
//	full_screen();
//	HideCursor();
//	drawmenu();
//	SetPos(151, 11);
//	
//	//int a;
//	cout << endl;
//	//cin >> a;
//	return 0;
//}