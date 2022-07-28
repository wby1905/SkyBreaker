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
bool judge_m_bullet(Plane &a, middleEnemy &b)
{
	for (int i = 0; i < 300; i++)
	{
		COORD x = b.a.position[i];
		if (abs(x.X - a.position.X) >= (int)(a.shape[5].size() + 1) || x.Y<a.position.Y || x.Y>a.position.Y + 7)return 0;
		for (int p = 0; p < 7; p++)
			for (int q = 0; q < (int)a.shape[p].size(); q++)
			{
				int xx = a.position.X, yy = a.position.Y;
				if (xx + q == x.X&&yy + p == x.Y)
				{
					SetPos(x);
					cout << " ";
					b.a.position[i].Y = 65;
					return 1;
				}
			}
	}
	return 0;
}
void Game::judgeenemybullet()
{
	
	for (int j = 0; j <= 19; j++)
		for (int i = 0; i <= 2; i++)
			if (b[i][j].init == 0 && judge_m_bullet(plane, b[i][j]))
			{
				if (plane.life > 0) { plane.life--; plane.bomb = 2; }
				else {
					over = 1; return;
				}
				SetPos(167, 52);
				cout << plane.life;
				SetPos(167, 58);
				cout << plane.bomb;
			}
}
bool judge_p_bullet1(Plane &a, smallEnemy &b)
{
	if (a.bullettype == 1)
	{
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 300; i++)
			{
				COORD x = a.a[j].position[i];
				if (abs(x.X - b.position.X) >= (int)(b.shape1[1].size() + 1) || x.Y<b.position.Y || x.Y>b.position.Y + 4)continue;
				for (int p = 0; p < 4; p++)
					for (int q = 0; q < (int)b.shape1[p].size(); q++)
					{
						int xx = b.position.X, yy = b.position.Y;

						if (xx + q == x.X&&yy + p == x.Y)
						{
							SetPos(x);
							cout << " ";
							a.a[j].position[i].Y = 65;
							return 1;
						}
					}
			}
		return 0;
	}
	if (a.bullettype == 2)
	{
		for (int i = 0; i < 300; i++)
			for (int p = 0; p < 4; p++)
				for (int q = 0; q < (int)b.shape1[p].size(); q++)
				{
					int xx = b.position.X, yy = b.position.Y;
					COORD x = a.a[0].position[i];
					int xa = (int)((a.a[0].origin[i].Y - a.a[0].position[i].Y) * 2) + a.a[0].position[i].X,
						xb = (int)((a.a[0].position[i].X - (a.a[0].origin[i].Y - a.a[0].position[i].Y) * 2));
					if ((xx + q == xa && yy + p == x.Y) && a.a[0].flag[0][i] != true)
					{
						SetPos(xa, x.Y);
						cout << " ";
						a.a[0].flag[0][i] = 1;
						return 1;
					}
					if ((xx + q == x.X&&yy + p == x.Y) && a.a[0].flag[1][i] != true)
					{
						SetPos(x);
						cout << " ";
						a.a[0].flag[1][i] = 1;
						return 1;
					}
					if ((xx + q == xb && yy + p == x.Y) && a.a[0].flag[12][i] != true)
					{
						SetPos(xb, x.Y);
						cout << " ";
						a.a[0].flag[2][i] = 1;
						return 1;
					}


				}
		return 0;
	}
	if (a.bullettype == 3)
	{
		for (int i = 0; i < 2; i++)
		if ((b.position.X < a.position.X + a.bpos[i].X) && (b.position.X + b.shape1[2].size() > a.position.X + a.bpos[i].X)) {
			return 1;
		}
		return 0;
	}

}
bool judge_p_bullet2(Plane &a, middleEnemy &b)
{
	if (a.bullettype == 1)
	{
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 300; i++)
			{
				COORD x = a.a[j].position[i];
				if (abs(x.X - b.position.X) >= (int)(b.shape1[1].size() + 1) || x.Y<b.position.Y || x.Y>b.position.Y + 4)continue;
				for (int p = 0; p < 4; p++)
					for (int q = 0; q < (int)b.shape1[p].size(); q++)
					{
						int xx = b.position.X, yy = b.position.Y;
						if (xx + q == x.X&&yy + p == x.Y)
						{
							SetPos(x);
							cout << " ";
							a.a[j].position[i].Y = 65;
							return 1;
						}
					}
			}
		return 0;
	}
	if (a.bullettype == 2)
	{
		for (int i = 0; i < 300; i++)
			for (int p = 0; p < 4; p++)
				for (int q = 0; q < (int)b.shape1[p].size(); q++)
				{
					int xx = b.position.X, yy = b.position.Y;
					COORD x = a.a[0].position[i];
					int xa = (int)((a.a[0].origin[i].Y - a.a[0].position[i].Y) * 2) + a.a[0].position[i].X,
						xb = (int)((a.a[0].position[i].X - (a.a[0].origin[i].Y - a.a[0].position[i].Y) * 2));
					if ((xx + q == xa && yy + p == x.Y)&&a.a[0].flag[0][i]!=true)
					{
						SetPos(xa, x.Y);
						cout << " ";
						a.a[0].flag[0][i] = 1;
						return 1;
					}
					if ((xx + q == x.X&&yy + p == x.Y) && a.a[0].flag[1][i] != true)
					{
						SetPos(x);
						cout << " ";
						a.a[0].flag[1][i] = 1;
						return 1;
					}
					if ((xx + q == xb && yy + p == x.Y) && a.a[0].flag[2][i] != true)
					{
						SetPos(xb, x.Y);
						cout << " ";
						a.a[0].flag[2][i] = 1;
						return 1;
					}


				}
		return 0;
	}
	if (a.bullettype == 3)
	{
		for (int i = 0; i < 2; i++)
			if ((b.position.X < a.position.X + a.bpos[i].X) && (b.position.X + b.shape1[2].size() > a.position.X + a.bpos[i].X)) {
				return 1;
			}
		return 0;
	}

}
void Game::judgeplanebullet()
{
	for (int j = 0; j <= 19; j++)
	{
		for (int i = 0; i <= 3 + level; i++)
			if (a[i][j].init == 0 && judge_p_bullet1(plane, a[i][j]))
				if (a[i][j].life > 1) { a[i][j].life--; }
				else {
					a[i][j].drawenemydeath(); printScore();
				}
		for (int i = 0; i <= 2; i++)
			if (b[i][j].init == 0 && judge_p_bullet2(plane, b[i][j]))
				if (b[i][j].life > 1) { b[i][j].life--;}
				else {
					b[i][j].drawenemydeath();  printScore();
				}
	}
}
bool judge1(Plane &a, smallEnemy &b) 
{
	if (abs(a.position.X - b.position.X) >= (int)(a.shape[5].size() + b.shape1[2].size()) || a.position.Y - b.position.Y >= 4 || b.position.Y - a.position.Y >= 8) return 0;
	for (int p = 0; p < 7; p++)
		for (int q = 0; q < (int)a.shape[p].size(); q++) 
			for (int i = 0; i < 4; i++)
			{
				int x = a.position.X, y = a.position.Y, xx = b.position.X, yy = b.position.Y;
				if (x + q > xx + 1 && x + q < (int)(xx + b.shape1[i].size() - 1))
					if (y + p > yy  && y + p < yy + 2)
						return 1;
			}
	return 0;
}
bool judge2(Plane &a, middleEnemy &b)
{
	if (abs(a.position.X - b.position.X) >= (int)(a.shape[5].size() + b.shape1[2].size() )|| a.position.Y - b.position.Y >= 4 || b.position.Y - a.position.Y >= 8) return 0;
	for (int p = 0; p < 7; p++)
		for (int q = 0; q < (int)a.shape[p].size(); q++)
			for (int i = 0; i < 4; i++)
				//for (int j = 0; j <= b.shape1[i].size(); j++)
			{
				int x = a.position.X, y = a.position.Y, xx = b.position.X, yy = b.position.Y;
				if (x + q > xx + 1 && x + q < xx + (int)b.shape1[i].size() - 1)
					if (y + p > yy + 1 && y + p < yy + 3)
						return 1;
			}
	return 0;
}
void Game::judgeplane1()
{
	for (int j = 0; j <= 19; j++)
		for (int i = 0; i <= 3 + level; i++)
			if (a[i][j].init == 0 && judge1(plane, a[i][j]))
			{
				if (plane.life > 0) { plane.life--; plane.bomb = 2;	}
				else {
					over = 1; return;
				}
				SetPos(167, 52);
				cout << plane.life;
				SetPos(167, 58);
				cout << plane.bomb;
				for (int q = 0; q <= 3 + level; q++)
				{
					a[q][j].drawenemydeath(); a[q][j].cnt = 0;
				}
			}
}
void Game::judgeplane2()
{
	for (int j = 0; j <= 19; j++)
		for (int i = 0; i <= 2; i++)
			if (b[i][j].init==0&&judge2(plane, b[i][j]))
			{
				if (plane.life > 0) { plane.life--; plane.bomb = 2; }
				else {
					over = 1; return;
				}
				SetPos(167, 52);
				cout << plane.life;
				SetPos(167, 58);
				cout << plane.bomb;
				for (int q = 0; q <= 2; q++)
				{
					b[q][j].drawenemydeath(); 
					b[q][j].cnt = 0;
				}
			}
}
