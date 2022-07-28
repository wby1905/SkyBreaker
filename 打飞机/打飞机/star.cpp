#include<iostream>
#include "stdafx.h"
#include"star.h"
#include "API.h"
using namespace std;
void star::initstar() {
	//TYPE 1
position = { 35,10 };
shape[0] = R"(     __          __)";
shape[1] = R"(    /  \        /  \)";
shape[2] = R"(   /    \      /    \)";
shape[3] = R"(  /      \    /      \)";
shape[4] = R"( /   бя   \  /    бя  \)";
shape[5] = R"(/          \/          \)";
shape[6] = "";
position2 = { 35,2 };
shape2[0] = R"(\          /\          /)";
shape2[1] = R"( \    бя  /  \    бя  /)";
shape2[2] = R"(  \      /    \      /)";
shape2[3] = R"(   \    /      \    /)";
shape2[4] = R"(    \  /        \  /)";
shape2[5] = R"(     \/          \/)";
shape2[6] = "";
position3 = { 35,20 };
shape3[0] = R"( _____________________   )";
shape3[1] = R"(|  / \__      __/  \  |  )";
shape3[2] = R"(| /   \/      \/    \ |  )";
shape3[3] = R"(|/                   \|  )";
shape3[4] = R"(| бя   /        \   бя |  )";
shape3[5] = R"(|    /          \     |  )";
shape3[6] = R"(|___/            \____|  )";
}
void star::drawstar(COORD pos) {
	position = pos;SetColor(color);
	for (int i = 0; i < 7; i++) {
		
		SetPos(pos.X, (pos.Y + i + 1));
		cout << shape[i];
		
	}SetColor(1 |2| 4|8);
}
	void star::drawstar2(COORD pos2) {
		position2 = pos2;SetColor(color);
		for (int i = 0; i < 7; i++) {
			
			SetPos(pos2.X, (pos2.Y + i + 1));
			cout << shape2[i];
			
		}
	SetColor(1 | 2 | 4 | 8);}
	void star::drawstar3(COORD pos3) {
		position3 = pos3;SetColor(color);
		for (int i = 0; i < 7; i++) {
			
			SetPos(pos3.X, (pos3.Y + i + 1));
			cout << shape3[i];
			
		}SetColor(1 | 2 | 4 | 8);
	}
