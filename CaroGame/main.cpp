#include "view.h"
#include "model.h"
#include "data.h"
#include "control.h"

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	DrawBoard(BOARD_SIZE);
	cin.get();
	return 0;
}