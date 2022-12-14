#include "stdafx.h"
#include "Enemy.h"
#include<windows.h>
#include"bullet.h"
#include<string>
#include"API.h"
using namespace std;
void smallEnemy::initenemy(int level)
{
	life += level ; 
	init = 0; cnt = 0;
	drawenemy();
}

void smallEnemy::drawenemy(COORD pos)
{
	if (init == 0)
	{	SetColor(4);
	position = pos;
	for (int i = 0; i < 4; i++)
	{

		if (pos.Y + 1 + i >= 2 && pos.Y + 1 + i <= 64)
		{
			SetPos(pos.X, (pos.Y + 1 + i));
			if (flag >= 3)
				cout << shape2[i];
			else cout << shape1[i];
		}
	}
	SetColor(1 | 2 | 4 | 8);
	flag++;
	if (flag == 5) flag = 0;
	}
}

void smallEnemy::removeenemy()
{
	if(init==0)
	for (int i = 0; i < 4; i++)
	{
		if (position.Y + 1 + i >= 2 && position.Y + 1 + i <= 64)
		{
		SetPos(position.X, (position.Y + 1 + i));
		drawRow(position.Y + 1 + i, position.X, position.X + shape1[i].size(), ' ');
		}
	}
}

void smallEnemy::enemymove()
{
	if (init == 0)
	{
		//removeenemy();
		position.Y += 2;
		if (mflag == 2)
		{
			if (position.X >= 64)
				if (q == 0)
					position.X -= 2;
				else
					position.X -= 4;
			q = 1;
		}
		else if (mflag == 4)
		{
			mflag = 0;
			if (position.X <= 133)
				position.X += 4;
		}
		mflag++;
		drawenemy(position);
		if (position.Y >= 65) init = 1;
	}
}
void smallEnemy::drawenemydeath()
{

	if (init == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (position.Y + 1 + i >= 2 && position.Y + 1 + i <= 64)
			{
				SetPos(position.X, (position.Y + 1 + i));
				cout << shape3[i];
			}
		}
		Sleep(20);
		removeenemy();
		init = 1;
		cnt++;
		//position = { (SHORT)random(60,137) , (SHORT)random(1,4) };
	}
}
void middleEnemy::initenemy(int level)
{
	life += level * 1.5; 
	cnt = 0;
	init = 0;
	a.initbullet(4);
	drawenemy();
	
}

void middleEnemy::drawenemy(COORD pos)
{
	if (init == 0)
	{
		SetColor(1|2);
		position = pos;
		for (int i = 0; i < 4; i++)
		{

			if (pos.Y + 1 + i >= 2 && pos.Y + 1 + i <= 64)
			{
				SetPos(pos.X, (pos.Y + 1 + i));
				if (flag > 3)
					cout << shape2[i];
				else cout << shape1[i];
			}
		}
		SetColor(1 | 2 | 4 | 8);
		flag++;
		if (flag == 7) flag = 0;
	}
}

void middleEnemy::removeenemy()
{
	if (init == 0)
		for (int i = 0; i < 4; i++)
		{
			if (position.Y + 1 + i >= 2 && position.Y + 1 + i <= 64)
			{
				drawRow(position.Y + 1 + i, position.X, position.X + shape1[i].size(), ' ');
			}
		}
}

void middleEnemy::enemymove()
{
	if (init == 0)
	{
		//removeenemy();
		
		if(position.Y<30)
		position.Y += 1;
		else { position.Y -= 2;shoot(); }
		if (mflag == 2)
		{
			if (position.X >= 64)
				if (q == 0)
					position.X -= 2;
				else
					position.X -= 4;
			q = 1;
		}
		else if (mflag == 4)
		{
			mflag = 0;
			if (position.X < 131)
				position.X += 4;
		}
		mflag++;
		drawenemy(position);
		if (position.Y >= 65) init = 1;
	}
}

void middleEnemy::drawenemydeath()
{

	if (init == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (position.Y + 1 + i >= 2 && position.Y + 1 + i <= 64)
			{
				SetPos(position.X, (position.Y + 1 + i));
				cout << shape3[i];
			}
		}
		Sleep(20);
		cnt++;
		removeenemy(); 
		a.removebullet();
		init = 1;
	}
}

void middleEnemy::shoot()
{
		for (int i = 0; i < 300; i++)
		{
				if (a.position[i].Y == 65)
				{
					a.position[i].X = position.X + bpos.X;
					a.position[i].Y = position.Y + bpos.Y;
					break;
				}
		}
}

void highEnemy::initenemy(int leve3)
{
	life += leve3;
	drawenemy();
	init = 1;
}

void highEnemy::drawenemy(COORD pos)
{
	SetColor(2|4|8);
	position = pos;
	for (int i = 0; i < 13; i++)
	{

		SetPos(pos.X, (pos.Y + 1 + i));
			if (flag <= 10)
				cout << shape2[i];
			else cout << shape1[i];
	}
	SetColor(1 | 2 | 4 | 8);
	flag++;
	if (flag == 20) flag = 0;
}

void highEnemy::removeenemy()
{
	if (init == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			drawRow(position.Y + 1 + i, position.X, position.X + shape1[i].size(), ' ');
		}
	}
}

void highEnemy::enemymove()
{
	if (init == 0)
	{
		if ((position.X >= 64) && (broad1 == 0)) position.X -= 1;
		else if (broad1 == 0)
		{
			broad1 = 1;
			broad2 = 0;
		}
		else if ((position.X <= 100) && (broad2 == 0)) position.X += 1;
		else
		{
			broad1 = 0;
			broad2 = 1;
		}
		drawenemy(position);
	}
}