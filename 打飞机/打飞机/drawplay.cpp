#pragma once
#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
#include"API.h"
#include"plane.h"
#include"game.h"
#include"star.h"
using namespace std;
void Game::drawplay()
{

	drawFrame(59, 1, 146, 65, '=', '|');
	drawFrame(147, 1, 170, 25, '-', '|');
	drawFrame(147, 26, 170, 36, '-', '|');
	SetPos(153, 5);
	cout << "分数：";
	SetPos(153, 6);
	cout << "0";
	SetPos(153, 7);
	cout << "等级：";
	SetPos(153, 9);
	cout << "称号：";
	//drawRow(37, 147, 170, '=');
	drawFrame(147, 37, 170, 65, '-', '|');
	SetPos(153, 27);
	cout << "w,a,s,d移动";
	SetPos(153, 29);
	cout << "按 k 射击";
	SetPos(150, 31);
	cout<<"按 空格 放炸弹";
	SetPos(153, 33);
	cout << "按 p 暂停";
	SetPos(153, 35);
	cout << "按 q 退出";
	plane.drawplane({ 148,47 });
	SetPos(165, 52);
	cout << "* 3";
	SetPos(155, 58);
	cout << "炸弹      * 2";
	plane.drawfire();
	drawFrame(30, 1, 58, 65, '=', '|');
	
}
static void drawhelp(int flag)
{
	drawRow(44, 41, 149, ' ');
	switch (flag)
	{
	case 0:SetPos(80, 44); cout << "byl号  体积适中，采用双发子弹"; break;
	case 1:SetPos(65, 44); cout << "cw号  体积较小，便于躲避敌人，采用激光发射，能消灭整列敌人，攻击性能较强"; break;
	case 2:SetPos(70, 44); cout << "wmg号  体积较大，采用散弹发射，同时发出三列子弹，功能全面"; break;
	}

}
void Game::drawjiku()
{
	Plane a, b, c;
	int flag = 0;
	system("cls");
	SetPos(99, 3);
	cout << "W  M  G";
	SetPos(92, 4);
	cout << "按 a,d 移动  按 k 选择";
	drawFrame(1, 1, 198, 65, '=', 'H');
	drawFrame(40, 40, 150, 48, '=', '|');
	drawRow(60, 2, 197, '-');
	drawRow(6, 2, 197, '-');
	SetPos(92, 63);
	cout << "Made by:wby ga lyf bzy ";
	drawFrame(83, 10, 112, 14, '-', '|');
	SetPos(92, 12);
	cout << "选 择 飞 机";
	a.initplane(1);
	a.drawplane({ 45, 21 });
	b.initplane(2);
	b.drawplane({ 91,21 });
	c.initplane(3);
	c.drawplane({ 132,21 });
	SetPos(49, 35);
	cout << "byl号";
	SetPos(94, 35);
	cout << "cw号";
	SetPos(138, 35);
	cout << "wmg号";
	drawFrame(40, 20, 63, 37, '-', '|');
	drawhelp(flag);
	Frame q[3];
	q[0] = { (SHORT)40,(SHORT)20 ,(SHORT)63,(SHORT)37,0 };
	q[1] = { (SHORT)86,(SHORT)20,(SHORT)109,(SHORT)37,0 };
	q[2] = { (SHORT)127,(SHORT)20 ,(SHORT)150,(SHORT)37,0 };
	//drawFrame(127, 20, 150, 37, '-', '|');
	//drawFrame(86, 20, 109, 37, '-', '|');
	while (1)
		{
			a.drawfire();
			b.drawfire();
			c.drawfire();
			Sleep(8);
			if (_kbhit())
			{
				char x = _getch();
				switch (x)
				{
				case 'D':
					case 'd':
						
						if (flag < 2) {drawFrame(q[flag], ' ', ' ');
							flag++;
							drawFrame(q[flag], '-', '|');
							drawhelp(flag);
						}
						break;
					case 'A':	case 'a':
						
						if (flag > 0) {drawFrame(q[flag], ' ', ' ');
							flag--;
							drawFrame(q[flag], '-', '|');
							drawhelp(flag);
						}
						break;
					case'K':	case 'k':
						initgame(); plane.initplane(flag + 1); drawmenu(); return;
						
					case 'Q':case 'q':exit(0);
					case '@':
						int zb = 0;
						string a = "wmgnb";
						while (1)
						{
							if (_kbhit())
							{
								char x = _getch();
								if (x == a[zb])
									zb++;
								else break;
							}	if (zb == a.size() )
								{
									initgame(); plane.initplane(flag + 1);plane.life = 9999;  drawmenu();
									break;

								}
							
						}
						break;//作弊码？
					}
				}

			}
		
}
	

//int main()
//{
//	full_screen();
//	HideCursor();
//	Plane a;
//	a.initplane(1);
//	drawplay(a);
//	a.drawplane();
//	while (1)
//	{
//		a.drawfire();
//		Sleep(8);
//
//		if (_kbhit())
//		{
//			char x = _getch();
//			a.move(x);
//			if (x == 'q') return 0;
//		}
//	}
//	return 0;
//}