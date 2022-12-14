#pragma once
#ifndef _API_h
#define _API_h
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
typedef struct Frame
{
	COORD position[2];
	int flag;
} Frame;

void SetPos(COORD a);
void SetPos(int i, int j);
void HideCursor();
void drawRow(int y, int x1, int x2, char ch);
void drawRow(COORD a, COORD b, char ch);
void drawCol(int x, int y1, int y2, char ch);
void drawCol(COORD a, COORD b, char ch);
void drawFrame(COORD a, COORD  b, char row, char col);
void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
int random(int a, int b);
COORD random(COORD a, COORD b);
void drawFrame(Frame frame, char row, char col);
void full_screen();
COORD get_font_size();
void SetColor(int color_num);
#endif