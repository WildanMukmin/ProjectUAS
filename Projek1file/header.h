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
	createText(33,2,"# # #  #  #     #  # #      # # # # # #  # # #    # # # #  # # # #  # # # #  #     #  # # #    # # # #",50);
	createText(33,3,"#      #  # #   #  #   #         #       #     #  #        #     #  #        #     #  #     #  #      ",50);
	createText(33,4,"# # #  #  #  #  #  #    #        #       # # #    # # # #  # # # #  # # # #  #     #  # # #    # # # #",50);
	createText(33,5,"#      #  #   # #  #   #         #       #  #     #        #     #        #  #     #  #  #     #      ",50);
	createText(33,6,"#      #  #     #  # #           #       #   #    # # # #  #     #  # # # #  # # # #  #    #   # # # #",50);
}

//tulisan welcome
void tulisanwelcome(){
	createText(43,8,  "||           ||  |||||||||  ||         ||||||||  |||||||||  ||            ||  |||||||||",50);
	createText(43,9,  "||     ||    ||  ||         ||        ||         ||     ||  || ||      || ||  ||       ",50);
	createText(43,10, "||   ||  ||  ||  |||||||||  ||        ||         ||     ||  ||   ||  ||   ||  |||||||||",50);
	createText(43,11, "|| ||     || ||  ||         ||        ||         ||     ||  ||     ||     ||  ||       ",50);
	createText(43,12, "||           ||  |||||||||  |||||||||  ||||||||  |||||||||  ||            ||  |||||||||",50);
}

