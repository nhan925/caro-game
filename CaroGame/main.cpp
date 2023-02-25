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
	//LoadingEffect();
	MainMenu();
	ControlMenu();
	//Help();
	//cin.get();
	

	return 0;
}