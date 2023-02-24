#pragma once
#include "data.h"
#include "view.h"
#include "model.h"

void StartGame();
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key);
void HandleKeyForMainMenu(int X, int Y, KEY_EVENT_RECORD key);
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD));