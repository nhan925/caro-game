#include "view.h"
#include "model.h"
#include "data.h"
#include "control.h"

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	//DrawBoard(BOARD_SIZE);
	//while (1) {
	//	HandleEvent(4, 2, HandleKeyForBoard);
	//}
	//LoadingEffect();
	//
	//
	//PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);  //Fix sound delay
	//
	//PlayBackgroundMusic();
	//
	//MainMenu();
	//ControlMenu();
	////cin.get();
	
	LoadingEffect();
	Music_Control();
	MainMenu();
	ControlMenu();

	return 0;
}