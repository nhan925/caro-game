#ifndef VIEW_H
#define VIEW_H

#pragma once
#include "data.h"

void FixConsoleWindow();
void SetWindowSize(int width, int height);
void CreateConsoleWindow(int width, int height);
void ShowScrollbar(bool Show);
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void SetFont(const wchar_t name[], int size);
void ShowCur(bool CursorVisibility);
void PrintTextColor(const wstring& s, const int& color);
void MainMenu();
void LoadingEffect();
void Help();
void DrawArrow();
void DrawKey();
void DrawEnter();
void Bye();
void DrawChangeSetting(int x, int y);
void Music_Mode(int i);
void Sound_Mode(int i);
void Setting();
void TextColor(int color);
void Info();

#endif