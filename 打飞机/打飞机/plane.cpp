#include "stdafx.h"
#include "plane.h"
#include "API.h"
#include<string>
using namespace std;
void Plane::initplane(int type)
{
	position = { 90,57 };
	fflag = 1;
	bomb = 2;
	life = 3;
	if (type == 1)
	{
		
		//type1
		bullettype = 1;
		shape[0] = "";
		shape[1] = "";
		shape[2] = R"(      /\)";
		shape[3] = R"(  o  /<>\  o)";
		shape[4] = R"( / \/ __ \/ \)";
		shape[5] = R"(/   \/__\/   \)";
		shape[6] = R"(\_ _/    \_ _/)";
		fpos[0] = { 2,8 };
		fpos[1] = { 11,8 };
		bpos[0] = { 2,3 };
		bpos[1] = { 11,3 };
		color = (1 | 2 | 8);
		a[0].initbullet(1);
		a[1].initbullet(1);
	}
	//type2
	if (type == 2)
	{
		
		//type2
		bullettype = 3;
		shape[1] = R"(    I)";
		shape[2] = R"(  / I \)";
		shape[3] = R"( /|   |\)";
		shape[4] = R"(/<|* *|>\)";
		shape[5] = R"(\( _^_ )/)";
		shape[6] = R"( \ / \ /)";
		shape[0] = "";
		fpos[0] = { 2,8 };
		fpos[1] = { 6,8 };
		bpos[0] = { 1,2 };
		bpos[1] = { 7,2 };
		color = (2);
		a[0].initbullet(3);
		a[1].initbullet(3);
	}
	//type3
	if (type == 3)
	{
		
		bullettype = 2;
		shape[0] = R"(      /B\)";
		shape[1] = R"(     /@ @\)";
		shape[2] = R"(   (< / \ >))";
		shape[3] = R"( /\/\/ 0 \/\/\)";
		shape[4] = R"(/ * Y__^__L  *\)";
		shape[5] = R"(\ ^ /     \ ^ /)";
		shape[6] = R"( \0/       \0/)";
		fpos[0] = { 2,8 };
		fpos[1] = { 12,8 };
		color = (1 | 8);
		bpos[0] = { 7, 2 };
		bpos[1] = {0,0};
		a[0].initbullet(2);
		a[1].initbullet(2);
	}
	if (type == 4)
	{
		life = 999;

		bullettype = 0;
		shape[0] = "";
		shape[1] = "";
		shape[2] = "";
		shape[3] = "";
		shape[4] = R"( /\)";
		shape[5] = R"(/■\)";
		shape[6] = "";
		fpos[0] = { 1,7 };
		fpos[1] = { 2,7 };
		color = (1 | 8);
		bpos[0] = { 0,0};
		bpos[1] = { 0,0 };
	}

}

void Plane::drawfire()
{
	for (int i = 0; i < 2; i++)
	{
		COORD pos = { position.X + fpos[i].X,position.Y + fpos[i].Y };
		if (fflag == 5)
		{
			SetPos(pos);
			cout << " ";
		}
		else
		{
			SetColor(4|8);
			SetPos(pos); 
			cout << "V";
			SetColor(1|2|4);
		}
	}
	if (fflag == 5)  fflag = 0;
	else fflag ++;
}

void Plane::drawplane(COORD pos)
{
	position = pos;
	for (int i = 0; i < 7; i++)
	{
		SetColor(color);
		SetPos(pos.X, (pos.Y + 1 + i));
		cout << shape[i] ;
		SetColor(1 | 2 | 4);
		;
	}
}


void Plane::move(char x)
{
	
	switch (x)
	{
	case 'w':
		if (position.Y > 15)
		{		
			removefire();
			removeplane(position);
			position.Y-=2;
			drawplane(position);
			
		}
		break;
	case 's':
		if (position.Y <= 55)
		{
			removefire();
			removeplane(position);
			position.Y++;
			drawplane(position);
		}
		break;
	case 'a':
		if (position.X >  60)
		{
			removefire();
			removeplane(position);
			position.X-=3;
			drawplane(position);
		}
		break;
	case 'd':
		if (position.X < 126)
		{
			removefire();
			removeplane(position);
			position.X+=3;
			drawplane(position);
		}
		break;
	}
}

void Plane::removeplane(COORD pos)
{
	for (int i = 0; i < 7; i++)
	{
		SetPos(pos.X,pos.Y+i+1 );
		drawRow(position.Y + 1 + i, position.X, position.X + shape[i].size(), ' ');
		
	}
}

void Plane::removefire()
{
	for (int i = 0; i < 2; i++)
	{
		COORD pos = { position.X + fpos[i].X,position.Y + fpos[i].Y };
		SetPos(pos); fflag = 1;
		cout << " ";
		
	}
}

void Plane::shoot()
{
	
	for (int j = 0; j <= 1; j++)
		for (int i = 0; i < 300; i++)
		{
			if (0 != bpos[j].Y && bpos[j].X != 0)
				if (a[j].position[i].Y == 65)
				{
					a[j].position[i].X = position.X + bpos[j].X;


					a[j].position[i].Y = position.Y + bpos[j].Y;
					for (int k = 0; k < 3; k++) a[j].flag[k][i] = 0;
					a[j].origin[i].X = position.X;
					a[j].origin[i].Y = position.Y;
					break;
				}
		}

	if (bullettype == 3)
	{
		for (int j = 0; j <= 1; j++)
		{
			SetColor(1 | 2 | 8);
			if (0 != bpos[j].Y && bpos[j].X != 0)
				drawCol({ position.X + bpos[j].X,2 }, { position.X + bpos[j].X,position.Y + bpos[j].Y }, 'I');
			SetColor(1 | 2 | 4 | 8);
		}
	}

}