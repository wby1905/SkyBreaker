#pragma once
#ifndef _GAME_h
#define _GAME_h 
#include"plane.h"
#include"Enemy.h"
class Game 
{

public:
	void initgame();
	void Pause();
	void Gameover();
	void printScore();
	void Playing();
	void judgeplane1();
	void judgeplane2();
	void judgeenemybullet();
	void judgeplanebullet();
	void makebomb();
	void help();
	void drawmenu();
	void drawplay();
	void drawjiku();//drawplay.cpp中定义
	int score, arank, rank = 0, level = 0, over = 0, play = 1, rank1 = 0, rank2 = 0;
	Plane plane;
	smallEnemy a[40][50];
	middleEnemy b[20][20];
	const std::string title[6] = {
	"初级飞行员",
	"中级飞行员",
	"高级飞行员",
	"超级飞行员",
	"顶级飞行员",
	"wmg真传    ",
	};
};
#endif