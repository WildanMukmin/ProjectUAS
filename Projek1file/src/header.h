#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <string>
#include <fstream>
#include "mmsystem.h"
// #include "ncurses.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

//-------------------------- Tempat Warna --------------------------//
#define RESET "\033[0m"

// MAKRO WARNA TEKS
#define GRAY "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// MAKRO WARNA TEKS CERAH
#define GRAY_LIGHT "\033[1;30m"
#define RED_LIGHT "\033[1;31m"
#define GREEN_LIGHT "\033[1;32m"
#define YELLOW_LIGHT "\033[1;33m"
#define BLUE_LIGHT "\033[1;34m"
#define MAGENTA_LIGHT "\033[1;35m"
#define CYAN_LIGHT "\033[1;36m"
#define WHITE_LIGHT "\033[1;37m"

// MAKRO WARNA BACKGROUND
#define GRAY_BG "\033[40m"
#define RED_BG "\033[41m"
#define GREEN_BG "\033[42m"
#define YELLOW_BG "\033[43m"
#define BLUE_BG "\033[44m"
#define MAGENTA_BG "\033[45m"
#define CYAN_BG "\033[46m"
#define WHITE_BG "\033[47m"

// MAKRO WARNA BACKGROUND CERAH
#define GRAY_BG_LIGHT "\033[1;40m"
#define RED_BG_LIGHT "\033[1;41m"
#define GREEN_BG_LIGHT "\033[1;42m"
#define YELLOW_BG_LIGHT "\033[1;43m"
#define BLUE_BG_LIGHT "\033[1;44m"
#define MAGENTA_BG_LIGHT "\033[1;45m"
#define CYAN_BG_LIGHT "\033[1;46m"
#define WHITE_BG_LIGHT "\033[1;47m"

//----------------------- Akhir Tempat Warna -----------------------//

// MAKRO GAYA TEKS
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define HIDDEN "\033[8m"
#define CORET "\033[9m"

// set koordinat
void linexy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// loading animation
void loading(int x, int y)
{
	char load[] = "L O A D I N G";

	linexy(x, y);
	for (int i = 0; i <= 12; i++)
	{
		cout << CYAN_LIGHT << load[i] << RESET;
		Sleep(50);
	}

	for (int i = 0; i <= 100; i++)
	{
		linexy(x + 13, y);
		cout << CYAN_LIGHT << " " << i << " %" << RESET; // 13
		Sleep(10);
	}
}

// make a line x (koordinat x = 0-191)
void createLineX(int x, int toX, int y, int tahan = 0, char style = '#')
{

	if (style == '-')
	{
		for (int i = x; i <= toX; i++)
		{
			linexy(i, y);
			printf("-");
			Sleep(tahan);
		}
	}
	else
	{
		for (int i = x; i <= toX; i++)
		{
			linexy(i, y);
			printf("#");
			Sleep(tahan);
		}
	}
}

// make a line y
void createLineY(int y, int toY, int x, int tahan = 0, char style = '#')
{
	if (style == '|')
	{
		for (int i = y; i <= toY; i++)
		{
			linexy(x, i); // 13
			printf("|");
			Sleep(tahan);
		}
	}
	else
	{
		for (int i = y; i <= toY; i++)
		{
			linexy(x, i); // 13
			printf("#");
			Sleep(tahan);
		}
	}
}

// create text
void createText(int x, int y, string text, int tahan = 0)
{
	linexy(x, y);
	for (int i = 0; i <= text.length(); i++)
	{
		cout << text[i];
		Sleep(tahan);
	}
}

// create char
void createCh(int x, int y, char text)
{
	linexy(x, y);
	cout << MAGENTA << text << RESET;
}

// singkatan cout
void print(auto kata)
{
	cout << kata << endl;
}

// move player
void movePlayer()
{
	char player;
	int xx, yy;
	xx = 0;
	yy = 0;
	while (true)
	{
		player = getch();

		if (player == 'w' || player == 'W')
		{
			linexy(xx, --yy);
		}
		else if (player == 's' || player == 'S')
		{
			linexy(xx, ++yy);
		}
		else if (player == 'd' || player == 'D')
		{
			linexy(++xx, yy);
		}
		else if (player == 'a' || player == 'A')
		{
			linexy(--xx, yy);
		}
	}
}

//------------tempat tempat void tampilan------------//

// tulisan findtreasure
void tulisanFindTreasure()
{
	createText(37, 0, "   _________________________________________________________________________________________");
	createText(37, 1, " / \\                                                                                        \\.");
	createText(37, 2, "|   |                                                                                       |.");
	createText(37, 3, " \\_ |                                                                                       |.");
	createText(37, 4, "    |                            _____   ___   _   _   ____                                 |.");
	createText(37, 5, "    |                           |  ___| |_ _| | \\ | | |  _ \\                                |.");
	createText(37, 6, "    |                           | |_     | |  |  \\| | | | | |                               |.");
	createText(37, 7, "    |                           |  _|    | |  | |\\  | | |_| |                               |.");
	createText(37, 8, "    |                           |_|     |___| |_| \\_| |____/                                |.");
	createText(37, 9, "    |                                                                                       |.");
	createText(37, 10, "    |                          __   __   ___    _   _   ____                                |.");
	createText(37, 11, "    |                          \\ \\ / /  / _ \\  | | | | |  _ \\                               |.");
	createText(37, 12, "    |                           \\ V /  | | | | | | | | | |_) |                              |.");
	createText(37, 13, "    |                            | |   | |_| | | |_| | |  _ <                               |.");
	createText(37, 14, "    |                            |_|    \\___/   \\___/  |_| \\_\\                              |.");
	createText(37, 15, "    |                                                                                       |.");
	createText(37, 16, "    |                                                                                       |.");
	createText(37, 17, "    |                    _____ ____  _____    _    ____  _   _ ____  _____                  |.");
	createText(37, 18, "    |                   |_   _|  _ \\| ____|  / \\  / ___|| | | |  _ \\| ____|                 |.");
	createText(37, 19, "    |                     | | | |_) |  _|   / _ \\ \\___ \\| | | | |_) |  _|                   |.");
	createText(37, 20, "    |                     | | |  _ <| |___ / ___ \\ ___) | |_| |  _ <| |___                  |.");
	createText(37, 21, "    |                     |_| |_| \\_\\_____/_/   \\_\\____/ \\___/|_| \\_\\_____|                 |.");
	createText(37, 22, "    |                                                                                       |.");
	createText(37, 23, "    |                                                                                       |.");
	createText(37, 24, "    |                                                                                       |.");
	createText(37, 25, "    |                                                                                       |.");
	createText(37, 26, "    |   ____________________________________________________________________________________|_____");
	createText(37, 27, "    |  /                                                                                         /.");
	createText(37, 28, "    \\_/_________________________________________________________________________________________/.");
}

// tulisan welcome
void textWelcome()
{
	print(CYAN_LIGHT);
	createText(30, 5, " _____                                                                                                         _____ ");
	createText(30, 6, "( ___ )-------------------------------------------------------------------------------------------------------( ___ )");
	createText(30, 7, " |   |                                                                                                         |   | ");
	createText(30, 8, " |   |     ____    __    ____     _______     __           ______      ______      .___  ___.     _______      |   | ");
	createText(30, 9, " |   |     \\   \\  /  \\  /   /    |   ____|   |  |         /      |    /  __  \\     |   \\/   |    |   ____|     |   | ");
	createText(30, 10, " |   |      \\   \\/    \\/   /     |  |__      |  |        |  ,----'   |  |  |  |    |  \\  /  |    |  |__        |   | ");
	createText(30, 11, " |   |       \\            /      |   __|     |  |        |  |        |  |  |  |    |  |\\/|  |    |   __|       |   | ");
	createText(30, 12, " |   |        \\    /\\    /       |  |____    |  `----.   |  `----.   |  `--'  |    |  |  |  |    |  |____      |   | ");
	createText(30, 13, " |   |         \\__/  \\__/        |_______|   |_______|    \\______|    \\______/     |__|  |__|    |_______|     |   | ");
	createText(30, 14, " |___|                                                                                                         |___| ");
	createText(30, 15, "(_____)-------------------------------------------------------------------------------------------------------(_____)");
	print(RESET);
}

// box opsi login
void boxOpsiLogin()
{
	print(CYAN_LIGHT);
	createText(54, 1, "                     ,---.           ,---.");
	createText(54, 2, "                    / /'`.'..''''--./,''\\ \\");
	createText(54, 3, "                    \\ \\    _       _    / /");
	createText(54, 4, "                     `.'  ' __   __ `  `,'");
	createText(54, 5, "                      /    /_O)_(_O\\    \\");
	createText(54, 6, "                      |  .-'  ___  `-.  |");
	createText(54, 7, "                   .--|       \\_/       |--.");
	createText(54, 8, "                 ,'    `   \\   |   /   /    `.");
	createText(54, 9, "                /       `.  `--^--'  ,'       `");
	createText(54, 10, "             .-''''..    ` ...___...'      .-''''-.");
	createText(54, 11, ".-----------/         `------------------/         `--------------.");
	createText(54, 12, "| .---------`         /------------------`         /------------. |");
	createText(54, 13, "| |          `.`..`..'                    `.'...'.'             | |");
	createText(54, 14, "| |                        B E R A N D A                        | |");
	createText(54, 15, "| |                                                             | |");
	createText(54, 16, "| |                                                             | |");
	createText(54, 17, "| |     1. LOGIN                                                | |");
	createText(54, 18, "| |     2. BUAT AKUN                                            | |");
	createText(54, 19, "| |     3. KELUAR                                               | |");
	createText(54, 20, "| |                                                             | |");
	createText(54, 21, "| |                        JAWABAN ANDA :                       | |");
	createText(54, 22, "| |                                                             | |");
	createText(54, 23, "| |                                                             | |");
	createText(54, 24, "| |_____________________________________________________________| |");
	createText(54, 25, "|_________________________________________________________________|");
	createText(54, 26, "                   )__________|__|__________(");
	createText(54, 27, "                  |            ||            |");
	createText(54, 28, "                  |____________||____________|");
	createText(54, 29, "                    ),-----.(      ),-----.(");
	createText(54, 30, "                  ,'   ..   `     '    ..   `.");
	createText(54, 31, "                 /            )  (           '");
	createText(54, 32, "                 `..........'    `...........'");
	print(RESET);
}

// box login
void boxLogin()
{
	print(CYAN_LIGHT);
	createText(60, 10, " __| |____________________________________________| |__ ");
	createText(60, 11, "(__   ____________________________________________   __)");
	createText(60, 12, "   | |                  L O G I N                 | |   ");
	createText(60, 13, "   | |                                            | |   ");
	createText(60, 14, "   | |   Masukan Username :                       | |   ");
	createText(60, 15, "   | |                                            | |   ");
	createText(60, 16, "   | |   Masukan Password :                       | |   ");
	createText(60, 17, " __| |____________________________________________| |__ ");
	createText(60, 18, "(__   ____________________________________________   __)");
	createText(60, 19, "   | |                                            | |   ");
	print(RESET);
}

// box buat akun
void boxCreateAkun()
{
	print(CYAN_LIGHT);
	createText(60, 10, " __| |________________________________________________________| |__ ");
	createText(60, 11, "(__   ________________________________________________________   __)");
	createText(60, 12, "   | |              C R E A T E  A C C O U N T                | |   ");
	createText(60, 13, "   | |                                                        | |   ");
	createText(60, 14, "   | |   Format Username Berupa HURUF Semua*                  | |   ");
	createText(60, 15, "   | |   Masukan Username :                                   | |   ");
	createText(60, 16, "   | |                                                        | |   ");
	createText(60, 17, "   | |   Format Password Berupa ANGKA Semua*                  | |   ");
	createText(60, 18, "   | |   Masukan Password :                                   | |   ");
	createText(60, 19, " __| |________________________________________________________| |__ ");
	createText(60, 20, "(__   ________________________________________________________   __)");
	createText(60, 21, "   | |                                                        | |   ");
	print(RESET);
}

// petunjuk penggunaan game
void boxControlGuide()
{
	print(MAGENTA);
	createText(77, 0, " __________________________________________________________________");
	createText(77, 1, "(__   ________________________________________________________   __)");
	createText(77, 2, "   | |           T O O L S  I N F O R M A T I O N !           | |");
	createText(77, 3, "   | |                                                        | |");
	createText(77, 4, "   | |   W  ==>  A T A S                                      | |");
	createText(77, 5, "   | |   S  ==>  B A W A H                                    | |");
	createText(77, 6, "   | |   D  ==>  K A N A N                                    | |");
	createText(77, 7, "   | |   A  ==>  K I R I                                      | |");
	createText(77, 8, "   | |                                                        | |");
	createText(77, 9, "   | |   P  ==>  K E M B A L I  K E  M E N U                  | |");
	createText(77, 10, "   | |                                                        | |");
	createText(77, 11, "   | |   S C O R E :                                          | |");
	createText(77, 12, "   | |                                                        | |");
	createText(77, 13, "   | |   H I G H  S C O R E :                                 | |");
	createText(77, 14, " __| |________________________________________________________| |__");
	createText(77, 15, "(__   ________________________________________________________   __)");
	createText(77, 16, "   | |                  H O W  T O  P L A Y                   | |");
	createText(77, 17, "   | |                                                        | |");
	createText(77, 18, "   | |   1. KUMPULKAN HARTA MU (X) UNTUK MENINGKATKAN SCORE   | |");
	createText(77, 19, "   | |   2. HINDARI MENABRAK DINDING (#) ATAU GAME AKAN       | |");
	createText(77, 20, "   | |      BERAKHIR DENGAN HASIL SCORE YANG TERAKHIR KAMU    | |");
	createText(77, 21, "   | |      DAPATKAN                                          | |");
	createText(77, 22, "   | |   3. SETIAP HARTA (X) YANG KAMU KUMPULKAN BERNILAI     | |");
	createText(77, 23, "   | |      50 POIN                                           | |");
	createText(77, 24, "   | |   4. KUMPULKAN HARTA SEBANYAKNYA DAN JELAJAHI SETIAP   | |");
	createText(77, 25, "   | |      DAERAH PETUALANGAN NYA                            | |");
	createText(77, 26, "   | |                                                        | |");
	createText(77, 27, "   | |          S E L A M A T  M E N J E L A J A H !          | |");
	createText(77, 28, " __| |________________________________________________________| |__");
	createText(77, 29, "(__________________________________________________________________)");
	print(RESET);
}

// transisi lolos stage
void lolosStage()
{
	print(GREEN);
	createText(60, 5, " _____________________________________________ ");
	createText(60, 6, "|.'',           L E V E L  U P !          ,''.|");
	createText(60, 7, "|.'.'',                                 ,''.'.|");
	createText(60, 8, "|.'.'.'',                             ,''.'.'.|");
	createText(60, 9, "|.'.'.'.'',                         ,''.'.'.'.|");
	createText(60, 10, "|.'.'.'.'.|                         |.'.'.'.'.|");
	createText(60, 11, "|.'.'.'.'.|===;                 ;===|.'.'.'.'.|");
	createText(60, 12, "|.'.'.'.'.|:::|',             ,'|:::|.'.'.'.'.|");
	createText(60, 13, "|.'.'.'.'.|---|'.|, _______ ,|.'|---|.'.'.'.'.|");
	createText(60, 14, "|.'.'.'.'.|:::|'.|'| || || |'|.'|:::|.'.'.'.'.|");
	createText(60, 15, "|,',',',',|---|',|'| || || |'|,'|---|,',',',',|");
	createText(60, 16, "|.'.'.'.'.|:::|'.|'| || || |'|.'|:::|.'.'.'.'.|");
	createText(60, 17, "|.'.'.'.'.|---|','   /%%%\\   ','|---|.'.'.'.'.|");
	createText(60, 18, "|.'.'.'.'.|===:'    /%%%%%\\    ':===|.'.'.'.'.|");
	createText(60, 19, "|.'.'.'.'.|%%%%%%%%%%%%%%%%%%%%%%%%%|.'.'.'.'.|");
	createText(60, 20, "|.'.'.'.','       /%%%%%%%%%\\       ','.'.'.'.|");
	createText(60, 21, "|.'.'.','        /%%%%%%%%%%%\\        ','.'.'.|");
	createText(60, 22, "|.'.','         /%%%%%%%%%%%%%\\         ','.'.|");
	createText(60, 23, "|.','          /%%%%%%%%%%%%%%%\\          ','.|");
	createText(60, 24, "|;____________/%%%%%%%%%%%%%%%%%\\____________;|");
	print(RESET);
	getch();
}

// box game over
void boxGameOver()
{
	print(RED_BG);
	createText(60, 10, " __| |____________________________________________| |__ ");
	createText(60, 11, "(__   ____________________________________________   __)");
	createText(60, 12, "   | |              G A M E  O V E R !            | |   ");
	createText(60, 13, "   | |                                            | |   ");
	createText(60, 14, "   | |                                            | |   ");
	createText(60, 15, "   | |     Kembali ke Home     --> press H <--    | |   ");
	createText(60, 16, "   | |                                            | |   ");
	createText(60, 17, "   | |     Kembali ke Beranda  --> press N <--    | |   ");
	createText(60, 18, " __| |____________________________________________| |__ ");
	createText(60, 19, "(__   ____________________________________________   __)");
	createText(60, 20, "   | |                                            | |   ");
	print(RESET);
}

// tulisan MENANG
void textMenang()
{
	PlaySound(TEXT("music/menang.wav"), NULL, SND_ASYNC | SND_LOOP);
	print(CYAN_LIGHT);
	createText(30, 5, " _____                                                                                     _____ ");
	createText(30, 6, "( ___ )-----------------------------------------------------------------------------------( ___ )");
	createText(30, 7, " |   |                                                                                     |   | ");
	createText(30, 8, " |   |   ____ ___  _   _  ____ ____      _  _____ _   _ _        _  _____ ___ ___  _   _ _ |   | ");
	createText(30, 9, " |   |  / ___/ _ \\| \\ | |/ ___|  _ \\    / \\|_   _| | | | |      / \\|_   _|_ _/ _ \\| \\ | | ||   | ");
	createText(30, 10, " |   | | |  | | | |  \\| | |  _| |_) |  / _ \\ | | | | | | |     / _ \\ | |  | | | | |  \\| | ||   | ");
	createText(30, 11, " |   | | |__| |_| | |\\  | |_| |  _ <  / ___ \\| | | |_| | |___ / ___ \\| |  | | |_| | |\\  |_||   | ");
	createText(30, 12, " |   |  \\____\\___/|_| \\_|\\____|_| \\_\\/_/   \\_\\_|  \\___/|_____/_/   \\_\\_| |___\\___/|_| \\_(_)|   | ");
	createText(30, 13, " |   |                                                                                     |   | ");
	createText(30, 14, " |   |                                                                                     |   | ");
	createText(30, 15, " |   |                                                                                     |   | ");
	createText(30, 16, " |   |                       __   _____  _   _  __        _____ _   _                      |   | ");
	createText(30, 17, " |   |                       \\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | |                     |   | ");
	createText(30, 18, " |   |                        \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| |                     |   | ");
	createText(30, 19, " |   |                         | || |_| | |_| |   \\ V  V /  | || |\\  |                     |   | ");
	createText(30, 20, " |   |                         |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_|                     |   | ");
	createText(30, 21, " |   |                                                                                     |   | ");
	createText(30, 22, " |   |                                 **** *                                              |   | ");
	createText(30, 23, " |   |                               **       *                                            |   | ");
	createText(30, 24, " |   |                              **        ***                                          |   | ");
	createText(30, 25, " |   |                              **         ***                                         |   | ");
	createText(30, 26, " |   |                               **          **     ***                                |   | ");
	createText(30, 27, " |   |                                ***        **   **   ***                             |   | ");
	createText(30, 28, " |   |                                  ***       ****       **                            |   | ");
	createText(30, 29, " |   |                                    ***       ****      **                           |   | ");
	createText(30, 30, " |   |                                     ***     **        * **                          |   | ");
	createText(30, 31, " |   |                                     ***   **       **     **                        |   | ");
	createText(30, 32, " |   |                                  *****    **    **       ***                        |   | ");
	createText(30, 33, " |   |                                  **  *    **  **      *** **                        |   | ");
	createText(30, 34, " |   |                                   ** **     **     ****   ***                       |   | ");
	createText(30, 35, " |   |                                   ***       *******    ******                       |   | ");
	createText(30, 36, " |   |                                    ***         ***  **** ***                        |   | ");
	createText(30, 37, " |   |                                      **   **     *********                          |   | ");
	createText(30, 38, " |   |                                       **   **********                               |   | ");
	createText(30, 39, " |   |                                         ******                                      |   | ");
	createText(30, 40, " |   |                                                                                     |   | ");
	createText(30, 41, " |___|                                                                                     |___| ");
	createText(30, 42, "(_____)-----------------------------------------------------------------------------------(_____)");
	print(RESET);
	getch();
}

// test warna
void testWarna()
{
	cout << GRAY << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << RED << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << GREEN << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << YELLOW << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << BLUE << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << MAGENTA << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << CYAN << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << WHITE << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;

	cout << endl;

	cout << GRAY_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << RED_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << GREEN_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << YELLOW_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << BLUE_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << MAGENTA_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << CYAN_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << WHITE_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;

	cout << endl;

	cout << GRAY_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << RED_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << GREEN_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << YELLOW_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << BLUE_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << MAGENTA_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << CYAN_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << WHITE_BG << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;

	cout << endl;

	cout << GRAY_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << RED_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << GREEN_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << YELLOW_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << BLUE_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << MAGENTA_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << CYAN_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
	cout << WHITE_BG_LIGHT << "TEST WARNA <<<<---->>>> TEST WARNA" << RESET << endl;
}
