#pragma once
#include "data.h"

void FixConsoleWindow();
void SetWindowSize(int width, int height);
void CreateConsoleWindow(int width, int height);
void ShowScrollbar(bool Show);
void DisableSelection();
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void SetFont(const wchar_t name[], int size);