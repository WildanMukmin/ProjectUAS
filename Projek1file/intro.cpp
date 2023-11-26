#include <ncurses/ncurses.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

void playMusic(const char* filePath) {
    PlaySound(TEXT("music/gamestart.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
using namespace std;

void textIntro()
{
	initscr();
	int x, y;
	x = 15;
	y = 10;
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	//init_pair(2, COLOR_WHITE, COLOR_GREEN);
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
	Sleep(50);
	getch();
}


int main(){
	initscr();
	playMusic("music/gamestart.wav");
	textIntro();
	Sleep(50);
	int x, y;
	x = 60;
	y = 10;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvprintw(25,x, "LET'S START !");
	Sleep(50);
	attroff(COLOR_PAIR(1));
	for(int i = 74; i <= 100; i++){
		attron(COLOR_PAIR(2));
		mvprintw(25, i, ">>>");
		refresh();
		Sleep(100);
		attroff(COLOR_PAIR(2));
	}
	getch();
	endwin();
	system("game");
	system("cls");
}

