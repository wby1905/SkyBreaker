#pragma once
#ifndef _bullet_h
#define bullet_h
#include"API.h"
#include<windows.h>
#include<string>
using namespace std;
class bullet
{
public:
	void initbullet(int type);
	void drawbullet();
	void removebullet();
	void movebullet();
	bool flag[3][300];
	int btype,init=1;
	COORD position[300],origin[300],lpos;
	string b = "☆";
};
#endif // !_bullet_h