#pragma once
#ifndef _star_h
#define _star_h
#include<windows.h>
#include<string>
using namespace std;
class star {
public:
	void initstar();
	void removestar();
	void drawstar(COORD pos = { 32,30 });
	void drawstar2(COORD pos2 = { 32,10 });
	void drawstar3(COORD pos3 = { 32,50 });
	std::string shape[7]; 
	std::string shape2[7]; 
	std::string shape3[7];
	COORD position,position3,position2;
	int color=(2|4);
};
#endif

