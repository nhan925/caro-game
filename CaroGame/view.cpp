#include "view.h"

//Fix the size of the console window
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Set the size of the console window
void SetWindowSize(int width, int height) {
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, width, height, TRUE);
}

//Hide scrollbar of the console window
void ShowScrollbar(bool Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

//Set font size & font
void SetFont(const wchar_t name[], int size) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size; //Font size
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, name);
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//Create the console window
void CreateConsoleWindow(int width, int height) {
	system("color 70");
	SetConsoleTitle(L"Caro Game");
	SetWindowSize(width, height);
	ShowScrollbar(0);
	FixConsoleWindow();
}

//Go to position (x, y)
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Show/Hide Cursor on the console window
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}

//Draw the Caro board
void DrawBoard(int pSize) {
	int Max_i = pSize * 2;
	int Max_j = pSize * 4;
	//Effect
	GotoXY(LEFT, TOP);
	cout << LEFT_TOP << HORIZONTAL_LINE;
	GotoXY(LEFT + Max_j, TOP + Max_i);
	cout << RIGHT_BOTTOM;
	int j = 1;
	for (int i = 1; j < Max_j / 2; i++, j++) {

		GotoXY(LEFT + 2 * j, TOP);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		GotoXY(LEFT, TOP + i);
		cout << VERTICAL_LINE;

		GotoXY(LEFT + Max_j - 2 * j, TOP + Max_i);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		GotoXY(LEFT + Max_j, TOP + Max_i - i);
		cout << VERTICAL_LINE;

		Sleep(50);
	}
	//Draw board
	for (int i = 0; i <= Max_i; i++) {
		GotoXY(LEFT, TOP + i);
		for (int j = 0; j <= Max_j; j++) {
			if (i == 0) {
				if (j == 0) cout << LEFT_TOP;
				else if (j == Max_j) cout << RIGHT_TOP;
				else if (j % 4 == 0) cout << T_SHAPE_DOWN;
				else cout << HORIZONTAL_LINE;
			}
			else if (i == Max_i) {
				if (j == 0) cout << LEFT_BOTTOM;
				else if (j == Max_j) cout << RIGHT_BOTTOM;
				else if (j % 4 == 0) cout << T_SHAPE_UP;
				else cout << HORIZONTAL_LINE;
			}
			else if (i % 2 == 0) {
				if (j == 0) cout << T_SHAPE_RIGHT;
				else if (j == Max_j) cout << T_SHAPE_LEFT;
				else if (j % 4 == 0) cout << CROSS;
				else cout << HORIZONTAL_LINE;
			}
			else {
				if (j % 4 == 0) cout << VERTICAL_LINE;
				else cout << " ";
			}
		}
	}
	GotoXY(FIRST_CELL_X, FIRST_CELL_Y); //Move pointer to the first cell
}