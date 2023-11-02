#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h> 
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;

//delay eksekusion (int)
void delay(int i){
	int count = 0;
	while( count < i*100000 ){
		count++;
	}
}

// set koordinat
void linexy (int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// loading animation
void loading(int x, int y){
	char load [] = "L O A D I N G";
	
	linexy(x, y);
	for(int i = 0; i<=12; i++ ){
		cout << load[i];
		delay(50);
	}
	
	for(int i = 0 ; i<= 100 ; i++){
		linexy(x+13, y);
		cout << " "<< i << " %";//13
		delay(100);
	}
}

// make a line x (koordinat x = 0-191)
void createLineX (int x, int toX, int y, int tahan = 0, char style = '#'){
	
	if(style == '-'){
		for(int i = x; i <= toX; i++){
			linexy(i, y);
			printf("-");
			delay(tahan);
		}
	}else {
		for(int i = x; i <= toX; i++){
			linexy(i, y);
			printf("#");
			delay(tahan);
		}
	}
	
}

// make a line y
void createLineY (int y, int toY, int x, int tahan = 0, char style = '#'){
	if(style == '|'){
		for(int i = y; i <= toY; i++){
			linexy(x, i);//13 
			printf("|");
			delay(tahan);
		}
	}else {
		for(int i = y; i <= toY; i++){
			linexy(x, i);//13 
			printf("#");
			delay(tahan);
		}
	}
}

// create text
void createText(int x, int y, string text ,int tahan = 0){
	linexy(x, y);
	for(int i = 0; i <= text.length(); i++ ){
		cout << text[i];
		delay(tahan);
	}
}

// create char
void createCh(int x, int y, char text){
	linexy(x, y);
	cout << text;
}

// singkatan cout
void print(auto kata){
	cout << kata <<endl;
}

// move player
void movePlayer(){
	char player;
	int xx, yy;
	xx = 0;
	yy = 0;
	while(true){
	player = getch();

	if(player == 'w' || player == 'W'){
		linexy(xx,--yy);
	}
	else if(player == 's' || player == 'S'){
		linexy(xx,++yy);
	}
	else if(player == 'd' || player == 'D'){
		linexy(++xx, yy);
	}
	else if(player == 'a' || player == 'A'){
		linexy(--xx, yy);
	}

	}
}

//------------tempat tempat void tampilan------------//

//tulisan findtreasure
void tulisanFindTreasure(){
	createText(33,2,"# # #  #  #     #  # #      # # # # # #  # # #    # # # #  # # # #  # # # #  #     #  # # #    # # # #",1);
	createText(33,3,"#      #  # #   #  #   #         #       #     #  #        #     #  #        #     #  #     #  #      ",1);
	createText(33,4,"# # #  #  #  #  #  #    #        #       # # #    # # # #  # # # #  # # # #  #     #  # # #    # # # #",1);
	createText(33,5,"#      #  #   # #  #   #         #       #  #     #        #     #        #  #     #  #  #     #      ",1);
	createText(33,6,"#      #  #     #  # #           #       #   #    # # # #  #     #  # # # #  # # # #  #    #   # # # #",1);
}

//tulisan welcome
void tulisanwelcome(){
	createText(43,8,  "||           ||  |||||||||  ||         ||||||||  |||||||||  ||            ||  |||||||||",50);
	createText(43,9,  "||     ||    ||  ||         ||        ||         ||     ||  || ||      || ||  ||       ",50);
	createText(43,10, "||   ||  ||  ||  |||||||||  ||        ||         ||     ||  ||   ||  ||   ||  |||||||||",50);
	createText(43,11, "|| ||     || ||  ||         ||        ||         ||     ||  ||     ||     ||  ||       ",50);
	createText(43,12, "||           ||  |||||||||  |||||||||  ||||||||  |||||||||  ||            ||  |||||||||",50);
}

//tulisan welcome
void textWelcome(){
createText(30,5 ," _____                                                                                                         _____ ");
createText(30,6 ,"( ___ )-------------------------------------------------------------------------------------------------------( ___ )");
createText(30,7 ," |   |                                                                                                         |   | ");
createText(30,8 ," |   |     ____    __    ____     _______     __           ______      ______      .___  ___.     _______      |   | ");
createText(30,9 ," |   |     '   '  /  '  /   /    |   ____|   |  |         /      |    /  __  '     |   '/   |    |   ____|     |   | ");
createText(30,10," |   |      '   '/    '/   /     |  |__      |  |        |  ,----'   |  |  |  |    |  '  /  |    |  |__        |   | ");
createText(30,11," |   |       '            /      |   __|     |  |        |  |        |  |  |  |    |  |'/|  |    |   __|       |   | ");
createText(30,12," |   |        '    /'    /       |  |____    |  `----.   |  `----.   |  `--'  |    |  |  |  |    |  |____      |   | ");
createText(30,13," |   |         '__/  '__/        |_______|   |_______|    '______|    '______/     |__|  |__|    |_______|     |   | ");
createText(30,14," |___|                                                                                                         |___| ");
createText(30,15,"(_____)-------------------------------------------------------------------------------------------------------(_____)");
getch();
}

// box opsi login
void boxOpsiLogin(){
createText(54,1 ,"                     ,---.           ,---.");
createText(54,2 ,"                    / /'`.'..''''--./,''` `");
createText(54,3 ,"                    ` `    _       _    / /");
createText(54,4 ,"                     `.'  ' __   __ `  `,'");
createText(54,5 ,"                      /    /_O)_(_O`    `");
createText(54,6 ,"                      |  .-'  ___  `-.  |");
createText(54,7 ,"                   .--|       `_/       |--.");
createText(54,8 ,"                 ,'    `   `   |   /   /    `.");
createText(54,9 ,"                /       `.  `--^--'  ,'       `");
createText(54,10 ,"             .-''''..    `...___...'      .-''''-.");
createText(54,11,".-----------/         `------------------/         `--------------.");
createText(54,12,"| .---------`         /------------------`         /------------. |");
createText(54,13,"| |          `.`..`..'                    `.'...'.'             | |");
createText(54,14,"| |                    P I L I H  O P S I                       | |");
createText(54,15,"| |                                                             | |");
createText(54,16,"| |                                                             | |");
createText(54,17,"| |            1. LOGIN   2. BUAT AKUN   3. KELUAR              | |");
createText(54,18,"| |                                                             | |");
createText(54,19,"| |                                                             | |");
createText(54,20,"| |                                                             | |");
createText(54,21,"| |                     JAWABAN ANDA :                          | |");
createText(54,22,"| |                                                             | |");
createText(54,23,"| |                                                             | |");
createText(54,24,"| |                                                             | |");
createText(54,25,"| |                                                             | |");
createText(54,26,"| |_____________________________________________________________| |");
createText(54,27,"|_________________________________________________________________|");
createText(54,28,"                   )__________|__|__________(");
createText(54,29,"                  |            ||            |");
createText(54,30,"                  |____________||____________|");
createText(54,31,"                    ),-----.(      ),-----.(");
createText(54,32,"                  ,'   ..   `    '  ..     `.");
createText(54,33,"                 /            )  (           '");
createText(54,34,"                 `..........'    `...........'");

}

// box login
void boxLogin(){
createText(60,10," __| |____________________________________________| |__"	);
createText(60,11,"(__   ____________________________________________   __)"	);
createText(60,12,"   | |              F O R M  L O G I N            | |"	);
createText(60,13,"   | |                                            | |"	);
createText(60,14,"   | |                                            | |"	);
createText(60,15,"   | |     Masukan Username :                     | |"	);
createText(60,16,"   | |                                            | |"	);
createText(60,17,"   | |     Masukan Password :                     | |"	);
createText(60,18," __| |____________________________________________| |__"	);
createText(60,19,"(__   ____________________________________________   __)"	);
createText(60,20,"   | |                                            | |"	);
}

// box buat akun
void boxCreateAkun(){
createText(60,10," __| |________________________________________________________| |__"	);
createText(60,11,"(__   ________________________________________________________   __)"	);
createText(60,12,"   | |                   C R E A T E  A K U N                 | |"	);
createText(60,13,"   | |                                                        | |"	);
createText(60,14,"   | |                                                        | |"	);
createText(60,15,"   | |                                                        | |"	);
createText(60,16,"   | |                                                        | |"	);
createText(60,17,"   | |                                                        | |"	);
createText(60,18,"   | |                                                        | |"	);
createText(60,19,"   | |     Format Username Berupa HURUF Semua *               | |"	);
createText(60,20,"   | |     Masukan Username :                                 | |"	);
createText(60,21,"   | |                                                        | |"	);
createText(60,22,"   | |     Format Password Berupa ANGKA Semua *               | |"	);
createText(60,23,"   | |     Masukan Password :                                 | |"	);
createText(60,24," __| |________________________________________________________| |__"	);
createText(60,25,"(__   ________________________________________________________   __)"	);
createText(60,26,"   | |                                                        | |"	);
}

// petunjuk penggunaan game
void boxControlGuide(){
createText(77,0 ," __________________________________________________________________"	);
createText(77,1 ,"(__   ________________________________________________________   __)"	);
createText(77,2 ,"   | |                    TOOLS INFORMATION !!                | |"	);
createText(77,3 ,"   | |                                                        | |"	);
createText(77,4 ,"   | |   W  ==>  M O V E  U P                                 | |"	);
createText(77,5 ,"   | |   S  ==>  M O V E  D O W N                             | |"	);
createText(77,6 ,"   | |   D  ==>  M O V E  R I G H T                           | |"	);
createText(77,7 ,"   | |   A  ==>  M O V E  L E F T                             | |"	);
createText(77,8 ,"   | |                                                        | |"	);
createText(77,9 ,"   | |   P  ==>  B A C K  T O  L O B B Y                      | |"	);
createText(77,10,"   | |                                                        | |"	);
createText(77,11,"   | |   S C O R E :                                          | |"	);
createText(77,12,"   | |                                                        | |"	);
createText(77,13,"   | |   H I G H  S C O R E :                                 | |"	);
createText(77,14," __| |________________________________________________________| |__"	);
createText(77,15,"(__   ________________________________________________________   __)"	);
createText(77,16,"   | |                    G A M E  G U I D E                  | |"	);
createText(77,17,"   | |                                                        | |"	);
createText(77,18,"   | |   RULES !!                                             | |"	);
createText(77,19,"   | |                                                        | |"	);
createText(77,20,"   | |   1. DILARANG MENABRAK TEMBOK!!                        | |"	);
createText(77,21,"   | |   2. UNTUK MENAMBAH POIN DI DAPAT DENGAN :             | |"	);
createText(77,22,"   | |      a. MENEMUKAN HARTA KARUN                          | |"	);
createText(77,23,"   | |      B. MENEMUKAN JALAN KELUAR                         | |"	);
createText(77,24,"   | |         DAN MELANJUTKAN KE STAGE BERIKUTNYA!           | |"	);
createText(77,25,"   | |   3. PENCAPAIAN MU AKAN DI REKAM DAN DI TAMPILKAN.     | |"	);
createText(77,26,"   | |                                                        | |"	);
createText(77,27,"   | |                   SEMOGA BERHASIL :)                   | |"	);
createText(77,28," __| |________________________________________________________| |__"	);
createText(77,29,"(__________________________________________________________________)"	);
}

//transisi lolos stage
void lolosStage(){
createText(60,5 ," _____________________________________________ ");
createText(60,6 ,"|.'',       LANJUT STAGE BERIKUTNYA       ,''.|");
createText(60,7 ,"|.'.'',                                 ,''.'.|");
createText(60,8 ,"|.'.'.'',                             ,''.'.'.|");
createText(60,9 ,"|.'.'.'.'',                         ,''.'.'.'.|");
createText(60,10,"|.'.'.'.'.|                         |.'.'.'.'.|");
createText(60,11,"|.'.'.'.'.|===;                 ;===|.'.'.'.'.|");
createText(60,12,"|.'.'.'.'.|:::|',             ,'|:::|.'.'.'.'.|");
createText(60,13,"|.'.'.'.'.|---|'.|, _______ ,|.'|---|.'.'.'.'.|");
createText(60,14,"|.'.'.'.'.|:::|'.|'| || || |'|.'|:::|.'.'.'.'.|");
createText(60,15,"|,',',',',|---|',|'| || || |'|,'|---|,',',',',|");
createText(60,16,"|.'.'.'.'.|:::|'.|'| || || |'|.'|:::|.'.'.'.'.|");
createText(60,17,"|.'.'.'.'.|---|','   l%%%l   ','|---|.'.'.'.'.|");
createText(60,18,"|.'.'.'.'.|===:'    l%%%%%l    ':===|.'.'.'.'.|");
createText(60,19,"|.'.'.'.'.|%%%%%%%%%%%%%%%%%%%%%%%%%|.'.'.'.'.|");
createText(60,20,"|.'.'.'.','       l%%%%%%%%%l       ','.'.'.'.|");
createText(60,21,"|.'.'.','        l%%%%%%%%%%%l        ','.'.'.|");
createText(60,22,"|.'.','         l%%%%%%%%%%%%%l         ','.'.|");
createText(60,23,"|.','          l%%%%%%%%%%%%%%%l          ','.|");
createText(60,24,"|;____________l%%%%%%%%%%%%%%%%%l____________;|");
getch();
}

// animasi orang joget
void joget(){
	for(int i  = 0 ; i<=2; i++){
createText(10,10," o       ");
createText(10,11,"/|l      ");
createText(10,12,"/ l      ");
delay(800);

createText(10,10,"l o /    ");
createText(10,11,"  |      ");
createText(10,12," / l     ");
delay(800);

createText(10,10,"_ o      ");
createText(10,11," /l      ");
createText(10,12,"| l      ");
delay(800);
       
createText(10,10,"___lo    ");
createText(10,11,"/)  |    ");
createText(10,12,"         ");
delay(800);

createText(10,10," __|     ");
createText(10,11,"   lo    ");
createText(10,12,"   ( l   ");
delay(800);

createText(10,10,"l /      ");
createText(10,11," |       ");
createText(10,12,"/ol      ");
delay(800);

createText(10,10,"     |__ ");
createText(10,11,"   o/    ");
createText(10,12," / )     ");
delay(800);

createText(10,10,"   o _   ");
createText(10,11,"   /l    ");
createText(10,12,"   / |   ");
delay(800);

createText(10,10,"l o /    ");
createText(10,11,"  |      ");
createText(10,12," / l     ");
delay(800);

createText(10,10," o       ");
createText(10,11,"/|l	  ");
createText(10,12,"/ l	  ");
delay(800);

createText(10,10,"o/__	  ");
createText(10,11," |  (l	  ");
createText(10,12,"      	  ");
delay(800);
	}
}
