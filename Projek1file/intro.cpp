#include <ncurses/ncurses.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>

using namespace std;

void playMusic(const char* filePath) {
    PlaySound(TEXT(filePath), NULL, SND_FILENAME | SND_ASYNC);
}
using namespace std;

void textIntro()
{
	initscr();
	int x, y;
	x = 30;
	y = 10;
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
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

}

void loading(int x, int y)
{
	initscr();
	mvprintw(y,x,"L");
	refresh();
		Sleep(50);
	mvprintw(y,x+2,"O");
	refresh();
		Sleep(50);
	mvprintw(y,x+4,"A");
	refresh();
		Sleep(50);
	mvprintw(y,x+6,"D");
	refresh();
		Sleep(50);
	mvprintw(y,x+8,"I");
	refresh();
		Sleep(50);
	mvprintw(y,x+10,"N");
	refresh();
		Sleep(50);
	mvprintw(y,x+12,"G");
	refresh();
		Sleep(50);
	mvprintw(y,x+17,"%%");
	refresh();
		Sleep(50);
	for (int i = 0; i <= 100; i++)
	{
		
		refresh();
		mvprintw( y, x+14,"%d", i); // 13
		Sleep(10);
	}
}


int main(){
	system("cls");
	initscr();
	playMusic("music/gamestart.wav");
	textIntro();
	refresh();
	Sleep(400);
	int x, y;
	x = 80;
	y = 10;
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(25,x, "LET'S START !");
	refresh();
	Sleep(400);
	loading(77, 28);
	attroff(COLOR_PAIR(1));
	getch();
	endwin();
	system("game");
	system("cls");
}

