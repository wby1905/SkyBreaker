#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
using namespace std;

typedef struct Frame
{
	COORD position[2];
	int flag;
} Frame;

//在[a, b)之间产生一个随机整数
int random(int a, int b)
{
	int c = (rand() % (a - b)) + a;
	return c;
}

//在两个坐标包括的矩形框内随机产生一个坐标
COORD random(COORD a, COORD b)
{
	int x = random(a.X, b.X);
	int y = random(a.Y, b.Y);
	COORD c = { x, y };
	return c;
}
void SetPos(COORD a)// coord结构体表示一个字符在控制台屏幕上的坐标
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}

void SetPos(int i, int j)// set cursor
{
	COORD pos = { i, j };
	SetPos(pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//这个结构包含的是控制台光标的信息 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//把第y行，[x1, x2) 之间的坐标填充为 ch
void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1, y);

	for (int i = 0; i <= (x2 - x1); i++)
		cout << ch;
}

//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawRow(COORD a, COORD b, char ch)
{
	if (a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else
	{
		SetPos(0, 25);
		cout << "error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";
		system("pause");
	}
}

//把第x列，[y1, y2] 之间的坐标填充为 ch
void drawCol(int x, int y1, int y2, char ch)
{
	int y = y1;

	while (y != y2 + 1)
	{
		SetPos(x, y);
		cout << ch;
		y++;
	}
}

//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawCol(COORD a, COORD b, char ch)
{
	if (a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else
	{
		SetPos(0, 25);
		cout << "error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";
		system("pause");
	}
}

//左上角坐标、右下角坐标、用row填充行、用col填充列
void drawFrame(COORD a, COORD  b, char row, char col)
{
	drawRow(a.Y, a.X + 1, b.X - 1, row);
	drawRow(b.Y, a.X + 1, b.X - 1, row);
	drawCol(a.X, a.Y + 1, b.Y - 1, col);
	drawCol(b.X, a.Y + 1, b.Y - 1, col);
}

void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a = { x1, y1 };
	COORD b = { x2, y2 };
	drawFrame(a, b, row, col);
}

void drawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}
void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
														/* 设置窗口信息 最大化 取消标题栏及边框 */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) /*& ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER*/);

	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

COORD get_font_size()
{
	COORD font_size;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	/* 字体信息 */
	struct CONSOLE_FONT
	{
		DWORD index;
		COORD dim;
	} cfi;
	typedef COORD(WINAPI *PROCGETCONSOLEFONTSIZE)(HANDLE, DWORD);
	typedef BOOL(WINAPI *PROCGETCURRENTCONSOLEFONT)(HANDLE, BOOL, struct CONSOLE_FONT*);
	typedef BOOL  (WINAPI*SETCONSOLEFONT)(HANDLE, DWORD);
	HMODULE hKernel32 = GetModuleHandle(L"kernel32");
	PROCGETCONSOLEFONTSIZE GetConsoleFontSize = (PROCGETCONSOLEFONTSIZE)GetProcAddress(hKernel32, "GetConsoleFontSize");
	PROCGETCURRENTCONSOLEFONT GetCurrentConsoleFont = (PROCGETCURRENTCONSOLEFONT)GetProcAddress(hKernel32, "GetCurrentConsoleFont");
	SETCONSOLEFONT SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hKernel32, "SetConsoleFont");
	GetCurrentConsoleFont(handle, FALSE, &cfi);  
	/* 获取当前字体索引信息 */
	font_size = GetConsoleFontSize(handle, cfi.index);      /* 获取当前字体宽高信息[字符宽度及高度所占像素数] */
	HANDLE hSTD = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleFont(hSTD, 2);
	return font_size;
}
void SetColor(int color_num) 
{
	using namespace std;
	HANDLE color; //声明一个句柄
	color = GetStdHandle(STD_OUTPUT_HANDLE); //取得标准输出句柄
	SetConsoleTextAttribute(color, color_num);
	//设置颜色函数SetConsoleTextAttribute有两个参数，第一个为句柄，第二个为颜色代表值 
	//可以使用「|」在第二个参数所填颜色间隔开，实现混色
}

