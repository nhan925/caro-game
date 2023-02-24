#include "control.h"

void StartGame() {
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
}

//Handle key for the chess board
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: //Enter
			break;
		case VK_ESCAPE: //Esc
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (_X == FIRST_CELL_X) {
				_X += (BOARD_SIZE - 1) * x;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X - x, _Y);
				_X -= x;
			}
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (_X == FIRST_CELL_X + (BOARD_SIZE - 1) * x) {
				_X = FIRST_CELL_X;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X + x, _Y);
				_X += x;
			}
			break;
		case VK_DOWN: case 0x53: //Down arrow
			if (_Y == FIRST_CELL_Y + (BOARD_SIZE - 1) * y) {
				_Y = FIRST_CELL_Y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y + y);
				_Y += y;
			}
			break;
		case VK_UP: case 0x57: //Up arrow
			if (_Y == FIRST_CELL_Y) {
				_Y += (BOARD_SIZE - 1) * y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y - y);
				_Y -= y;
			}
			break;
		default:
			break;
		}
	}
}

//Handle key for the main menu
void HandleKeyForMainMenu(int X, int Y, KEY_EVENT_RECORD key) {
	static int x = X, y = Y;
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: //Enter
			break;
		case VK_DOWN: case 0x53: {//Down arrow
			GotoXY(x, y);
			printf(" ");
			GotoXY(x + 13, y);
			printf(" ");
			if (y == Y + 10)
				y = Y;
			else
				y += 2;
			GotoXY(x, y);
			cout << SELECTED_LEFT;
			GotoXY(x + 13, y);
			cout << SELECTED_RIGHT;
			break; 
		}
		case VK_UP: case 0x57: {//Up arrow
			GotoXY(x, y);
			printf(" ");
			GotoXY(x + 13, y);
			printf(" ");
			if (y == Y)
				y = Y + 10;
			else
				y -= 2;
			GotoXY(x, y);
			cout << SELECTED_LEFT;
			GotoXY(x + 13, y);
			cout << SELECTED_RIGHT;
			break;
		}
		default:
			break;
		}
	}
}

//Handle event
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD)) {
	while (1) {
		DWORD DWNumberOfEvents = 0;
		DWORD DWNumberOfEventsRead = 0; 
		HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); 
		GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents); 
		if (DWNumberOfEvents) {
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];
			ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead);
			for (DWORD i = 0; i < DWNumberOfEvents; ++i) {
				if (IREventBuffer[i].EventType == KEY_EVENT) 
					func(x, y, IREventBuffer[i].Event.KeyEvent);
			}
		}
	}
}