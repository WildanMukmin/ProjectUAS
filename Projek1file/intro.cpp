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
	int x, y;
	x = 15;
	y = 10;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " _____                                                                                                         _____  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, "( ___ )-------------------------------------------------------------------------------------------------------( ___ ) ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |                                                                                                         |   |  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |            _____ ____  _____    _    ____  _   _ ____  _____      _   _ _   _ _   _ _____               |   |  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |           |_   _|  _ \\| ____|  / \\  / ___|| | | |  _ \\| ____|    | | | | | | | \\ | |_   _|              |   |  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |             | | | |_) |  _|   / _ \\ \\___ \\| | | | |_) |  _|      | |_| | | | |  \\| | | |                |   |  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |             | | |  _ <| |___ / ___ \\ ___) | |_| |  _ <| |___     |  _  | |_| | |\\  | | |                |   |  ");y++;
	mvprintw(y,x, " |   |             |_| |_| \\_\\_____/_/   \\_\\____/ \\___/|_| \\_\\_____|    |_| |_|\\___/|_| \\_| |_|                |   |  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, " |   |                                                                                                         |   |  ");y++;
	mvprintw(y,x, " |___|                                                                                                         |___|  ");y++;
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	mvprintw(y,x, "(_____)-------------------------------------------------------------------------------------------------------(_____) ");y++;
	attroff(COLOR_PAIR(1));
	getch();
	endwin();
	system("cls");
	system("game");
}

