#include <curses.h>
#include <windows.h>
#include <iostream>

/*void loading(){
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	mvprintw(20,20, "Loading...");
	attroff(COLOR_PAIR(1));
	for(int i = 3; i <= 15; i++){
		attron(COLOR_PAIR(2));
		mvprintw(40, i, ">>>");
		refresh();
		Sleep(50);
		attroff(COLOR_PAIR(2));
	}
	getch();
	endwin();
}*/

/*void loading(){
	initscr();
	char load [] = "L O A D I N G";
	for(int i = 0; i<=12; i++ ){
		mvprintw(20, 20, load[i]);
		Sleep(50);
	}

	for(int i = 0 ; i<= 100 ; i++){
		mvprintw(20, 25, " ", i, " %");//13
		Sleep(10);
	}
	getch();
	endwin();
}*/

int main()
{
	initscr();
	mvprintw(8, 10, "           _____                                                                                                         _____ ");
	mvprintw(9, 11, "         ( ___ )-------------------------------------------------------------------------------------------------------( ___ )");
	mvprintw(10, 12, "         |   |                                                                                                         |   | ");
	mvprintw(11, 13, "        |   |     ____    __    ____     _______     __           ______      ______      .___  ___.     _______      |   | ");
	mvprintw(12, 14, "       |   |     \\   \\  /  \\  /   /    |   ____|   |  |         /      |    /  __  \\     |   \\/   |    |   ____|     |   | ");
	mvprintw(13, 15, "      |   |      \\   \\/    \\/   /     |  |__      |  |        |  ,----'   |  |  |  |    |  \\  /  |    |  |__        |   | ");
	mvprintw(14, 16, "     |   |       \\            /      |   __|     |  |        |  |        |  |  |  |    |  |\\/|  |    |   __|       |   | ");
	mvprintw(15, 17, "    |   |        \\    /\\    /       |  |____    |  `----.   |  `----.   |  `--'  |    |  |  |  |    |  |____      |   | ");
	mvprintw(16, 18, "   |   |         \\__/  \\__/        |_______|   |_______|    \\______|    \\______/     |__|  |__|    |_______|     |   | ");
	mvprintw(17, 19, "  |___|                                                                                                         |___| ");
	mvprintw(18, 20, "(_____)-------------------------------------------------------------------------------------------------------(_____)");
	// loading();
	getch();
	endwin();
	system("cls");
	system("game");
}