#include "view.h"
#include "model.h"
#include "data.h"
#include "control.h"

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	//ShowCur(0);
	//DrawBoard(BOARD_SIZE);
	//ShowCur(1);
	//HandleEvent(4, 2, HandleKeyForBoard);
	LoadingEffect();
	MainMenu();
	HandleEvent(80, 22, HandleKeyForMainMenu);
	//Sleep(1000);
	//system("cls");
	//DrawBoard(BOARD_SIZE);
	//cin.get();
	return 0;
}