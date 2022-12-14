#pragma once
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
#include"star.h"
using namespace std;

void Game::initgame()
{
	score = 0;
	arank = 0;
	level = 1;
	rank = 0;
	rank2 = 0; play = 1; rank1 = 0;
	over = 0;
	//plane.initplane(1);
	plane.initplane((rand() % 3)+1 );
}
void Game::Pause()
{
	drawFrame(148, 15, 169, 21, '-', '|');
	SetPos(153, 18);
	cout << "暂停中...";
	char c = _getch();

	while (c != 'p')
		c = _getch();
	drawFrame(148, 15, 169, 21, ' ', ' ');
	SetPos(153, 18);
	cout << "         ";
}

void Game::Gameover()
{
	COORD p1 = { 90, 27 };
	COORD p2 = { 120, 33 };
	drawFrame(p1, p2, '=', '|');
	for(int i=0;i<5;i++)
	drawRow(28+i, 91, 119, ' ');
	SetPos(101, 30);
	string str = "Game Over!";

	for (int i = 0; i < (int)str.size(); i++)
	{
		Sleep(80);
		cout << str[i];
	}
	Sleep(200);
	SetPos(101, 30);
	for (int i = 0; i < (int)str.size(); i++)
	{
		Sleep(80);
		cout <<" ";
	}
	Sleep(200);
	SetPos(94, 29);
	cout << "得　　分：" << score;
	SetPos(94, 30);
	cout << "获得称号：" << title[level-1];
	SetPos(93, 31);
	Sleep(500);
	cout << "继续？ 是（y）| 否（n）";
		SetPos(93, 32);
	cout<<"制作：wby bzy lyf ga";
	while (1)
	{
		char x = _getch();

		if (x == 'n')
			exit(0) ;
		else if (x == 'y')
		{
		
			over = 0;
			system("cls");
			Game game; game.initgame();
			game.drawmenu();
			return;
		}
	}
}

void Game::printScore()
{
	for (int j = 0; j <= 19; j++)
		for (int i = 0; i <= 2; i++)
			if (b[i][j].init == 1) { score += b[i][j].cnt * 10; b[i][j].cnt = 0; }
	for (int j = 0; j <= 19; j++)
		for (int i = 0; i <= 3 + level; i++)
			if (a[i][j].init == 1) { score += a[i][j].cnt * 5; a[i][j].cnt = 0; }
	if ((rank + 1) == score / 500)
	{
		plane.bomb += 2;
		rank++;
	}
	SetPos(153, 6);
	cout << score;
	if (rank2 + 1 == score / 500&&level<6) { level++; rank2++; }
	SetPos(153, 10);
	cout << title[level - 1];
	SetPos(153, 8);
	cout << "LEVEL   " << level;
	SetPos(167, 58);
	cout << plane.bomb;
	return;
}

void Game::makebomb()
{
	if (plane.bomb > 0)
	{
		SetColor(2 | 4 | 8);
		for (int i = 64; i > 1; i--)
		{

			drawRow(i, 60, 145, '=');
		}
		for (int i = 64; i > 1; i--)
		drawRow(i, 60, 145, ' ');
		plane.drawplane(plane.position);
		for (int j = 0; j <= 19; j++)
			for (int i = 0; i <= 2; i++)
			{
				if (b[i][j].init == 0) 
				{
					b[i][j].drawenemydeath();
					b[i][j].life = 1+level * 1.5;
				}
			}
		for (int j = 0; j <= 19; j++)
			for (int i = 0; i <= 3 + level; i++)
			{
				if (a[i][j].init == 0)
				{
					a[i][j].drawenemydeath();	
					a[i][j].life = 1+level;
				}
			}
		printScore();
		plane.bomb--;
		SetPos(167, 58);
		cout << plane.bomb;
	}

}
void Game::Playing()
{
	system("color 0F");
	star wmg;
	wmg.initstar();
	wmg.drawstar();
	wmg.drawstar2();
	wmg.drawstar3();
	int shootflag=0,mcnt = 0, cnt = 0, r[3] = { 0 };
	SetPos(153, 10);
	cout << title[level-1];
	SetPos(153, 8);
	cout <<"LEVEL   "<<level ;
	//plane.initplane(4);
	
	plane.drawplane();
	for (int i = 0; i <= 3 + level; i++)
	{
		a[i][0].initenemy(level);
	}
	while (1)
	{
		
		if (over == 1) { Gameover();break; }
		plane.drawfire();
		Sleep(8);
		shootflag++;arank++;cnt++; mcnt++;
		if (_kbhit())
		{
			char x = _getch();
			plane.move(x); 
			judgeplane1();
			judgeplane2();
			judgeenemybullet();
			if (x == 'p') Pause();
			if (x == 'q') Gameover(); 
			if (x == 'k') {
				plane.shoot();
				if (plane.bullettype == 3) judgeplanebullet();
			}
			if (x == ' ') makebomb();
		}
		if ((cnt==120-level*50&&(level==1||level==2))||cnt == 600-level*50)
		{
			r[0]++;
			r[0] = r[0] % 20;
			
			for (int i = 0; i <= 3+level; i++)
				if(a[i][r[0]].init==1)
					a[i][r[0]].initenemy(level);
			cnt = 0;
		}
		if (mcnt == 820 - level * 100 )
		{
			r[1]++;
			r[1] = r[1] % 20;
			if (level >= 3)
				for (int i = 0; i <= 2; i++)
					if (b[i][r[1]].init == 1 )
						b[i][r[1]].initenemy(level);
			mcnt = 0;

		}
	
		if (shootflag == 5 )
		{
			if (plane.bullettype != 3) judgeplanebullet();

			plane.a[0].movebullet();
			plane.a[1].movebullet();
			shootflag = 0;
		}
		if (arank == 70-level*8)
		{
		
			
			
			for (int j = 0; j <= 19; j++)
				for (int i = 0; i <= 3+level; i++)
					a[i][j].removeenemy();

			for (int j = 0; j <= 19; j++)
				for (int i = 0; i <= 3+level; i++)
				{
					a[i][j].enemymove();	
					judgeplane1();
				}
			if (level >= 3)
			{
				for (int j = 0; j <= 19; j++)
					for (int i = 0; i <= 2; i++)
						b[i][j].removeenemy();

				for (int j = 0; j <=19; j++)
					for (int i = 0; i <= 2; i++)
					{
						b[i][j].enemymove();
						b[i][j].a.movebullet();
						judgeenemybullet();
						judgeplane2();
					}
			}

			arank = 0;	
		}
	}
}