#pragma once
#ifndef _plane_h
#define _plane_h
#include<windows.h>
#include<string>
#include"bullet.h"
//using namespace std;
class Plane
{
public:
	void initplane(int type);
	void drawfire();
	void drawplane(COORD pos= { 90,56 });
	void move(char x);
	void removeplane(COORD pos);
	void removefire();
	void shoot();
	std::string shape[7];
	int bullettype,fflag;
	COORD position, fpos[2], bpos[2] = { 0};
	bullet a[2];
	int life,bomb;
	int color;
};
#endif