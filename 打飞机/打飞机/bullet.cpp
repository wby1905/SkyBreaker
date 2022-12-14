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

void bullet::initbullet(int type)
{
	btype = type; 
	for (int i = 0; i < 300; i++) 
		position[i].Y = 65;
	if (type == 2)
	{
		for (int i = 0; i < 300; i++)
		{
			for (int j = 0; j < 3; j++)
				flag[j][i] = 0;
			origin[i].Y = 65;
		}
	}
	if (type == 3)
	{
		lpos.Y = 65;
	}
	
}

void bullet::drawbullet()
{
		for (int i = 0; i < 300; i++)
		{
			if (position[i].Y != 65)
			{
				if (btype == 1)
				{
					SetColor(2 | 4 | 8);
					SetPos(position[i]);
					cout << "o";
					SetColor(1 | 2 | 4 | 8);
				}
				if (btype == 4)
				{
					SetColor( 4 | 8);
					SetPos(position[i]);
					cout << "◆";
					SetColor(1 | 2 | 4 | 8);
				}
				if (btype == 2)
				{
					SetColor(2 | 4 | 8);
					SetPos(position[i]);
					int xa = (int)((origin[i].Y - position[i].Y) *2) + position[i].X,
						xb = (int)((position[i].X - (origin[i].Y - position[i].Y)*2));
					if (flag[1][i] == 0)cout << b;
					if (xa <= 145 && flag[0][i] == 0)
					{
						SetPos(xa, position[i].Y);
						cout << b;
					}
					if (xb >= 60 && flag[2][i] == 0)
					{
						SetPos(xb, position[i].Y);
						cout << b;
					}
					SetColor(1 | 2 | 4 | 8);
				}
				if (btype == 3)
				{
					SetColor(2 | 4 | 8);
					drawCol({ position[i].X,2 }, position[i],'|');
					SetColor(1 | 2 | 4 | 8);
				}
				
			}
		}
}


void bullet::removebullet()
{
	
		for (int i = 0; i < 300; i++)
		{
			if (position[i].Y != 65)
			{
				if (btype == 1||btype==4)
				{
					SetPos(position[i]);
					cout << ' ';
				}
				if (btype == 2)
				{

					SetPos(position[i]);
					int xa = (int)((origin[i].Y - position[i].Y) *2 ) + position[i].X,
						xb = (int)((position[i].X - (origin[i].Y - position[i].Y) *2));
					cout << ' ';
					if (xa <= 145)
					{
						SetPos(xa, position[i].Y);
						cout << ' ';
					}
					if (xb >= 60)
					{
						SetPos(xb, position[i].Y);
						cout << ' ';
					}

				}
				if (btype == 3)
				{
					SetColor(2 | 4 | 8);
					drawCol({ position[i].X,2 }, position[i], ' ');
					SetColor(1 | 2 | 4 | 8);
				}

			}
		}

}

void bullet::movebullet()
{
	
	removebullet();
	if (btype == 1||btype==2)
	{
		for (int i = 0; i < 300; i++)
			if (position[i].Y != 65)
			{
				position[i].Y--;
				if (position[i].Y == 1)
				{
					COORD pos = { position[i].X, position[i].Y + 1 };
					SetPos(pos);
					cout << " ";
					position[i].Y = 65;

				}
			}
	}
	if(btype==3)
	{
		for (int i = 0; i < 300; i++)
		{
			if (position[i].Y != 65)position[i].Y = 65;
		}
	}
	if (btype == 4)
	{
		for (int i = 0; i < 300; i++)
			if (position[i].Y != 65)
			{
				position[i].Y++;
				if (position[i].Y == 64)
				{
					COORD pos = { position[i].X, position[i].Y -1  };
					SetPos(pos);
					cout << " ";
					position[i].Y = 65;
				}
			}
	}
	drawbullet();
	
}

