#pragma once
#include<windows.h>
#include"bullet.h"
#include"plane.h"
#include"API.h"
#include<string>
using namespace std;
class smallEnemy 
{
public:
	void initenemy(int level);
	void drawenemy(COORD pos = { (SHORT)random(60,137) , (SHORT)random(1,4) });
	void removeenemy();
	void enemymove();
	void drawenemydeath();

	string shape1[4] = {
		R"( __/_)",
		R"(/ OO \)",
		R"(\_VV_/)",
		""
	}
		,shape3[4] = {
		R"( _\/_)",
		R"(/ >< \)",
		R"(\_VV_/)",
		""
	}, shape2[4] = {
		R"( _\__)",
		R"(/ -- \)",
		R"(\_VV_/)",
		""
	}
		;
	COORD position;
	int init=1,etype,mflag=0,q=0,flag=0;
	int life = 1;
	int cnt=0;

};

class middleEnemy
{
public:
	void initenemy(int level);
	void drawenemy(COORD pos = { (SHORT)random(60,137) , (SHORT)random(1,4) });
	void removeenemy();
	void enemymove();
	void drawenemydeath();
	void shoot();
	string shape1[4] = {
		R"( \  W  /)",
		R"(( | M | ))",
		R"( \ G G /)",
		R"(  \ | /)"
	},
		 shape3[4] = {
		R"( \  |  /)",
		R"((_  G  _))",
		R"( _  G   _)",
		R"(  / | \)" 
	}, shape2[4] = {
		R"( \ V V /)",
		R"(( | M | ))",
		R"( \ 6 6 /)",
		R"(  \ | /)"
	}
	;
	COORD position, bpos = { 5,3 };
	bullet a;
	int init = 1, etype, mflag = 0, q = 0, flag = 0;
	int life = 1;
	int cnt = 0;
};
class highEnemy //:public Enemy
{
public:
	void initenemy(int leve2);
	void drawenemy(COORD pos = { (SHORT)76 , (SHORT)2 });
	void removeenemy();
	void enemymove();
	void drawenemydeath();

	string shape1[13] = {
		R"(      /\                /\)",
		R"(     /  \<   ★   ☆ >/  \)",
		R"(    /                      \)",
		R"(   /     O             X    \)",
		R"(  /                          \)",
		R"( /     _\       W       /_    \)",
		R"(/       /               \      \)",
		R"(\      __      /\      __      /)",
		R"( \    |VV|    /  \    |VV|    /)",
		R"(  \   |/    /    \    |/     /)",
		R"(   \        /      \        /)",
		R"(    \      /        \      /)",
		R"(     \ 0  /          \  1 /)",
	};

	string shape2[13] = {
		R"(      /\                /\)",
		R"(     /  \<   ☆  ★  >/  \)",
		R"(    /                      \)",
		R"(   /     X             O    \)",
		R"(  /                          \)",
		R"( /     _\       V       /_    \)",
		R"(/       /               \      \)",
		R"(\      __      /\      __      /)",
		R"( \    |VV|    /  \    |VV|    /)",
		R"(  \     \|   /    \     \|   /)",
		R"(   \        /      \        /)",
		R"(    \      /        \      /)",
		R"(     \ 1  /          \  0 /)",
	};
	COORD position;
	int init = 1, etype, mflag = 0, q = 0, flag = 0;
	int life = 1;
	int broad1 = 0, broad2 = 1;//边界

};
