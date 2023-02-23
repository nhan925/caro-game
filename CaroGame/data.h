#pragma once

//Library
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

//Namespace
using std::cout;
using std::cin;
using std::string;

//Game Data
#define BOARD_SIZE 15
#define LEFT 5 
#define TOP 5 
#define FIRST_CELL_X LEFT + 2
#define FIRST_CELL_Y TOP + 1

//Console size
#define HEIGHT 720
#define WIDTH 1280

//ASCII Code For Board (Single Line)
//#define VERTICAL_LINE char(179)
//#define HORIZONTAL_LINE char(196)
//#define RIGHT_TOP char(191)
//#define RIGHT_BOTTOM char(217)
//#define LEFT_TOP char(218)
//#define LEFT_BOTTOM char(192)
//#define T_SHAPE_UP char(193)
//#define T_SHAPE_DOWN char(194)
//#define T_SHAPE_RIGHT char(195)
//#define T_SHAPE_LEFT char(180)
//#define CROSS char(197)

//ASCII Code For Board (Double Line)
#define VERTICAL_LINE char(186)
#define HORIZONTAL_LINE char(205)
#define RIGHT_TOP char(187)
#define RIGHT_BOTTOM char(188)
#define LEFT_TOP char(201)
#define LEFT_BOTTOM char(200)
#define T_SHAPE_UP char(202)
#define T_SHAPE_DOWN char(203)
#define T_SHAPE_RIGHT char(204)
#define T_SHAPE_LEFT char(185)
#define CROSS char(206)

struct _POINT { 
	int x, y, c; 
};

//Global Variables
static _POINT _A[BOARD_SIZE][BOARD_SIZE];
static bool _TURN;
static int _COMMAND;
static int _X = FIRST_CELL_X, _Y = FIRST_CELL_Y;
