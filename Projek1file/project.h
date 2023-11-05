#include "header.h"

//----------------------------Prototype------------------------//
void halamanAwal();
void dataBase();
void homeGame();
void transisi();
void createAkun();
void login();
void opsiLogin();
void score(int score);
int readScore();
void alurGame();
void aktifScore(int score);
int readAktifScore();
void resetScore();
void gameOver();


//---------------------------prototype Map----------------------//
void map1();
void map2();
void map3();

//---------------------------prototype Game----------------------//
void stage1();
void stage2();
void stage3();


//---------------------------Menu dan Akun---------------------//

// HALAMAN AWAL DAN LOADING
void halamanAwal(){
	system("cls");
	print(CYAN);
	textWelcome();
	PlaySound(TEXT("soundHalamanAwal.wav"), NULL, SND_ASYNC | SND_LOOP);
	getch();
	loading(78, 16);
	getch();
	PlaySound(0,0,0);
	print(RESET);
}

//tampilan awal login
void opsiLogin(){
	system("cls"); 
	print(YELLOW);
	boxOpsiLogin();

	// pilihan login
	linexy(93,21);
	while (true){
		char jawab = getch();	
		if(jawab == '1'){
			login();
			break;
		}else if (jawab == '2'){
			createAkun();
			login();
			break;
		}else if (jawab == '3'){
			system("cls"); 
			exit(0);
		}
	}

	print(RESET);
}

// pilihan buat akun
void createAkun(){
	system("cls");
	print(GREEN);
	boxCreateAkun();
	dataBase();
	print(RESET);

}

// pilihan dari login
void login(){
	print(GREEN);
	string output;
	system("cls");
	boxLogin();
	linexy(90, 15);
	string id;cin>>id;
	linexy(90, 17);
	string pw;cin>>pw;

	ifstream cekData;
	cekData.open("userAkun.txt");

	print(RESET);
    while(true){
        cekData >> output;
        if(output == id+pw){
			transisi();
            break;
        }
		if(cekData.eof()){
			print(GREEN);
			createText(67, 7, "LOGIN GAGAL COBA LAGI!");
			delay(10000);
			system("cls");
			print(RESET);
			createAkun();
			login();
			break;
		}
    }
	cekData.close();

}

// login berhasil
void transisi(){
	system("cls");
	print(BLUE);
	createLineX(60, 112, 12  , 10, '-');
	createLineX(60, 112, 14  , 10, '-');
	createLineY(12, 14 , 59  , 10, '|' );
	createLineY(12, 14 , 113 , 10, '|' );
	createText(74, 13, "L O G I N  B E R H A S I L ");
	loading(78, 16);
	getch();
	print(RESET);
	homeGame();
}

// data base
void dataBase(){
	ofstream data;
	string id;
	linexy(90, 20);
	cin >> id;
	string pin;
	linexy(90, 23);
	cin >> pin;
	data.open("userAkun.txt", ios::app);
	data << id;
	data << pin <<endl;
	data.close();
	system("cls");
	
}

//halaman awal game
void homeGame(){
	system("cls");
	print(CYAN_LIGHT);
	PlaySound(TEXT("contoh.wav"), NULL, SND_ASYNC | SND_LOOP);
	tulisanFindTreasure();

	// pilihan menu game
	createText(66, 30, "Jawaban anda : y untuk melanjukan");
	createText(66, 31, "Jawaban anda : e untuk ke beranda");
	print(RESET);
		char jawab; 
		while(true){
		jawab = getch();
		if (jawab == 'Y' || jawab == 'y'){
			alurGame();
			system("cls");
			exit(0);
		}else if (jawab == 'E' || jawab == 'e'){
			PlaySound(0,0,0);
			opsiLogin(); 
			break;
		}
		}
}


//---------------------- tempat penyimpanan data high score dan nama user -----------------//

// menyimpan score
void score(int score){
	ofstream buatScore;

	if(score >= readScore()){
		buatScore.open("highScore.txt");
		buatScore << score;
		buatScore.close();
	}
}

//menyimpan score yang sekarang
void aktifScore(int score){
	ofstream aktifScore;
	int showScore = readAktifScore() + score;
	aktifScore.open("aktifScore.txt");
	aktifScore << showScore;
	aktifScore.close();
}

// membaca data base score
int readScore(){
	ifstream cekData;

	int output;

	cekData.open("highScore.txt");
	cekData >> output;
	cekData.close();

	return output;
}

// membaca data base socre yang aktif
int readAktifScore(){
	ifstream cekData;

	int output;

	cekData.open("aktifScore.txt");
	cekData >> output;
	cekData.close();

	return output;
}

//reset score
void resetScore(){
	ofstream resetScore;
	resetScore.open("aktifScore.txt");
	resetScore << 0;
	resetScore.close();
}

//---------------------Map Game----------------------//
void map1(){
	print(YELLOW);
	createText(0,0 ,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
	createText(0,1 ,"# A   #                                                 #           #");
	createText(0,2 ,"#     #                                               X #           #");
	createText(0,3 ,"#     #         #     # # # # # # # # # # # # # # # # # #     #     #");
	createText(0,4 ,"#     #         #                                       #   X #     #");
	createText(0,5 ,"#     #         #                                       # # # #     #");
	createText(0,6 ,"#     #         #                                                   #");
	createText(0,7 ,"#     #         #                                                   #");
	createText(0,8 ,"#     #         #                     #                             #");
	createText(0,9 ,"#     #         #                     #                             #");
	createText(0,10,"#     #         #                     #                             #");
	createText(0,11,"#     #         #                     #                             #");
	createText(0,12,"#     #         #                     #                             #");
	createText(0,13,"#     #         #                     #                             #");
	createText(0,14,"#     #         #                     #                             #");
	createText(0,15,"#     #         #                     #     #                       #");
	createText(0,16,"#     #         #                     #     #                       #");
	createText(0,17,"#     #         #                     #     #                       #");
	createText(0,18,"#     #         #                     #     #                       #");
	createText(0,19,"#     #         #                     #     #                       #");
	createText(0,20,"#     #         #                     #     #                       #");
	createText(0,21,"#     #         #                     #     #                       #");
	createText(0,22,"#     #         #                     #     #                       #");
	createText(0,23,"#     #         #                     #   X #       # # #           #");
	createText(0,24,"#     # # #     #       # # # # # # # # # # #   #       #           #");
	createText(0,25,"#               #                           #   #       #           #");
	createText(0,26,"#               #                           #   #       #     # #   #");
	createText(0,27,"#     # # # # # # # # # # # # # # # # # # # #   #       #       #   #");
	createText(0,28,"#                                         X #   #       #       #   #");
	createText(0,29,"#                                           #   #     X #       #   #");
	createText(0,30,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #     # # #");
	print(RESET);
}

void map2(){
	print(MAGENTA);
	createText(0,0 ,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
	createText(0,1 ,"#                                               # #           # # # #");
	createText(0,2 ,"#                                               # #           # # # #");
	createText(0,3 ,"#     # # # # # # # # # # # # # # #     # #     # #     #     # # # #");
	createText(0,4 ,"#     # # # # # # # # # # # # # # #     # #     # #     #     # # # #");
	createText(0,5 ,"#     # # # # # # # # # # # # # # #     # #     # #     #           #");
	createText(0,6 ,"                              # # #     # #     # #     #           #");
	createText(0,7 ,"                              # # #     # #     # #     #     # # # #");
	createText(0,8 ,"#     # # # # # # # # # # # # # # #     # #     # #     #     # # # #");
	createText(0,9 ,"#     # # # # # # # # # # # # # # #     # #     # #     #     # # # #");
	createText(0,10,"#     # # # # # # # # # # # # # # #     # #   X # #     #           #");
	createText(0,11,"#     # # # # # # # # # # # # # # #     # # # # # #     #           #");
	createText(0,12,"#     # # # # # # # # # # # # # # #     # # # # # #     # # # #     #");
	createText(0,13,"#     # # # # # # # # # # # # # # #                     # # # #     #");
	createText(0,14,"#     # #                                               # # # #     #");
	createText(0,15,"#     # #                               # # # # # #     #           #");
	createText(0,16,"#     # # # # # # # # # # #     # #     # # # # # #     #           #");
	createText(0,17,"#     # # # # # # # # # # #     # #             # #     #     # # # #");
	createText(0,18,"#     # # # # # # # # # # #     # #             # #     #     # # # #");
	createText(0,19,"#     # # # # # # # # # # #     # # # # # #     # #     #     # # # #");
	createText(0,20,"#     # # # # # # # # # # #     # # # # # #     # #     #           #");
	createText(0,21,"#     # # # # # # # # # # #             # #     # #     #           #");
	createText(0,22,"#     # # # # # # # # # # #             # #     # #     # # # #     #");
	createText(0,23,"#     # # # # # # # # # # # # # # #     # #     # #     #   X #     #");
	createText(0,24,"#     # # # # # # # # # # # # # # #     # #     # #     #     #     #");
	createText(0,25,"#     # # # # # # # # # # # # # # #     # #   X # #     #     #     #");
	createText(0,26,"#     # # # # # # # # # # # # # # #     # # # # # #     #     #     #");
	createText(0,27,"#     # # # # # # # # # # # # # # #     # # # # # #           #     #");
	createText(0,28,"#     # #                                       # #           #     #");
	createText(0,29,"#     # # X                                     # #           # A   #");
	createText(0,30,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
	print(RESET);
}

void map3(){
	print(RED_LIGHT);
	createText(0,0 ,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
	createText(0,1 ,"#                       # # A                                       #");
	createText(0,2 ,"#                       # #                                         #");
	createText(0,3 ,"#     # # # #     #     # #     # # #           # # # #     # #     #");
	createText(0,4 ,"#           #     #     # #     # # #           # # # #     # #     #");
	createText(0,5 ,"#           #     #     # #     # #     # #     # # # #     # #     #");
	createText(0,6 ,"# # # #     #     #     # #     # #     # #     # # # #     # #     #");
	createText(0,7 ,"#           #     #             # #     # #         # #     # #     #");
	createText(0,8 ,"#           #     #             # #     # #         # #     # #     #");
	createText(0,9 ,"#     # # # # # # # # # # # # # # # # # # #         # #     # #     #");
	createText(0,10,"#     # # # # # # # # # # # # # # # # # # #     # # # #     # #     #");
	createText(0,11,"#                 #     # #           # X       # #         # #     #");
	createText(0,12,"#               X #     # #           #         # #         # #     #");
	createText(0,13,"#     # # # # # # #     # #           # # # # # # #         # # # # #");
	createText(0,14,"#                 #     # # # # #     #         # #                 #");
	createText(0,15,"#                 #     # # # # #     #         # #                 #");
	createText(0,16,"#     #     # # # #           # #     #     # # # #                 #");
	createText(0,17,"#     #           #           # #               # #                 #");
	createText(0,18,"#     #           # # # #     # #               # # # # # # # #     #");
	createText(0,19,"#     # # # # # # # # # #     # # # # #         # # # # # # # #     #");
	createText(0,20,"#             # #     # #     # # # # #         # # # # # # # #     #");
	createText(0,21,"#             # #     # #     # # # # #         # # # # # # # #     #");
	createText(0,22,"# # # #       # #     # #           # #                   # # #     #");
	createText(0,23,"#             # #     # #           # #                   # # #     #");
	createText(0,24,"#                             # # # # #     # # # # #     # # #     #");
	createText(0,25,"#     #                       # # # # #     #       #     # # #     #");
	createText(0,26,"#     #     # # # # # # # # # # # # # #     #       #     # # #     #");
	createText(0,27,"# # # #               # #     # # #         #             # # #     #");
	createText(0,28,"#                             # # #         #                       #");
	createText(0,29,"#             # #       X     # # #         #   # #                 #");
	createText(0,30,"# # # # # # # # # # # # # # # # # #     # # # # # # # # # # # # # # #");
	print(RESET);
}

//---------------------Coding Game-------------------//
void stage1(){
	system("cls");
    map1();
	char player;
	int xx, yy,koX,koY,highScore;
	xx = 1;
	yy = 1;
    koX = 2;
    koY = 1;
	highScore = 0;
	aktifScore(0);
	boxControlGuide();


	char map [31][35] = {
		//		a    b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z  aa   ab  ac  ad  ae  af  ag  ah  ai  
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#','A',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','#',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','X','#',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','X','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#',
		'#',' ',' ','#','#','#',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',
		'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',
		'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ','#',
		'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',
		'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','X','#',' ',' ',' ','#',' ','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#'
	};
	

	//------------------------awal check Map----------------------//
	/*	
		linexy(0,0);

		for(int i = 0; i<31 ; i++){
			for(int j = 0; j<35; j++){
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
	//------------------------akhir check Map----------------------//

    map [xx][yy] = 'A';
    createCh(koX, koY, 'A');
    while(true){
		
		if(readAktifScore() >= highScore){
			highScore = readAktifScore();
			score(highScore);
		}

	//------------------------------Posisi Score---------------------------//

		linexy(98,11);
		cout<< readAktifScore();
		linexy(107,13);
		cout<<readScore();
		linexy(koX,koY);

	//----------------------------akhir posisi score-----------------------//


	//--------------------------------- Control User ----------------------------//
	player = getch();

	if     (player == 'w' || player == 'W'){
		if(map[xx - 1][yy] == ' '){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx - 1][yy] == 'X'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx - 1][yy] == '.'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx - 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 's' || player == 'S'){
		if(map[xx + 1][yy] == ' '){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx + 1][yy] == 'X'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx + 1][yy] == '.'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx + 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'd' || player == 'D'){
		if(map[xx][yy + 1] == ' '){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy + 1] == 'X'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy + 1] == '.'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy + 1] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'a' || player == 'A'){
		if(map[xx][yy - 1] == ' '){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy - 1] == 'X'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy - 1] == '.'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy - 1] == '#'){	
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'p' || player == 'P'){
		resetScore();
		system("cls");
		homeGame();
		break;
	}
	//-------------------------------- end Control User ----------------------------//
	}
}

void stage2(){
	system("cls");
    map2();
	char player;
	int xx, yy,koX,koY,totalScore, highScore;
	xx = 29; //ini untuk char
	yy = 32; //ini untuk char
    koX = 64; //ini untuk map()
    koY = 29; //ini untuk map()
	highScore = 0;
	boxControlGuide();


	char map [31][35] = {
		//	 a    b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z  aa   ab  ac  ad  ae  af  ag  ah  ai  
			'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ','X','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#',
			'#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#',
			'#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ','X','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#',' ',' ','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#',' ','X','#','#',' ',' ','#',' ',' ','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ','#',' ',' ','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ','#',' ',' ','#',
			'#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ','#',
			'#',' ',' ','#','#','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','A',' ','#',
			'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'
		};
	

	//------------------------awal check Map----------------------//
	/*	
		linexy(0,0);

		for(int i = 0; i<31 ; i++){
			for(int j = 0; j<35; j++){
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
	//------------------------akhir check Map----------------------//

    map [xx][yy] = 'A';
    createCh(koX, koY, 'A');
    while(true){
		
		if(readAktifScore() >= highScore){
			highScore = readAktifScore();
			score(highScore);
		}

	//------------------------------Posisi Score---------------------------//

		linexy(98,11);
		cout<< readAktifScore();
		linexy(107,13);
		cout<<readScore();
		linexy(koX,koY);

	//-------------------------------akhir posisi score-----------------------//


	//--------------------------------- Control User ----------------------------//
	player = getch();

	if     (player == 'w' || player == 'W'){
		if(map[xx - 1][yy] == ' '){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx - 1][yy] == 'X'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx - 1][yy] == '.'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx - 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 's' || player == 'S'){
		if(map[xx + 1][yy] == ' '){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx + 1][yy] == 'X'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx + 1][yy] == '.'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx + 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'd' || player == 'D'){
		if(map[xx][yy + 1] == ' '){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy + 1] == 'X'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy + 1] == '.'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy + 1] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'a' || player == 'A'){
		if(map[xx][yy - 1] == ' '){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy - 1] == 'X'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy - 1] == '.'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy - 1] == '#'){	
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'p' || player == 'P'){
		resetScore();
		system("cls");
		homeGame();
		break;
	}
	//-------------------------------- end Control User ----------------------------//
	}
}

void stage3(){
	system("cls");
    map3();
	char player;
	int xx, yy,koX,koY,totalScore, highScore;
	xx = 1; //ini untuk char
	yy = 14; //ini untuk char
    koX = 28; //ini untuk map()
    koY = 1; //ini untuk map()
	highScore = 0;
	boxControlGuide();


	char map [31][35] = {
		//	 a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z  aa   ab  ac  ad  ae  af  ag  ah  ai  
			'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#',
			'#','#','#','#',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','X',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ','X','#',' ',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#',
			'#',' ',' ','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#',
			'#','#','#','#',' ',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#','#',' ',' ','#',
			'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ','#',' ',' ',' ','#',' ',' ','#','#','#',' ',' ','#',
			'#',' ',' ','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#',' ',' ',' ','#',' ',' ','#','#','#',' ',' ','#',
			'#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','X',' ',' ','#','#','#',' ',' ',' ',' ','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',
			'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'
	};
	

	//------------------------awal check Map----------------------//
	/*	
		linexy(0,0);

		for(int i = 0; i<31 ; i++){
			for(int j = 0; j<35; j++){
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
	//------------------------akhir check Map----------------------//

    map [xx][yy] = 'A';
    createCh(koX, koY, 'A');
    while(true){
		
		if(readAktifScore() >= highScore){
			highScore = readAktifScore();
			score(highScore);
		}

	//------------------------------Posisi Score---------------------------//

		linexy(98,11);
		cout<< readAktifScore();
		linexy(107,13);
		cout<<readScore();
		linexy(koX,koY);

	//-------------------------------akhir posisi score-----------------------//


	//--------------------------------- Control User ----------------------------//
	player = getch();

	if     (player == 'w' || player == 'W'){
		if(map[xx - 1][yy] == ' '){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx - 1][yy] == 'X'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx - 1][yy] == '.'){
			map[xx - 1][yy] = 'A';
			map[xx][yy] = ' ';
			--xx;
            createCh(koX,koY,' ');
            --koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx - 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 's' || player == 'S'){
		if(map[xx + 1][yy] == ' '){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
		}
		else if(map[xx + 1][yy] == 'X'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx + 1][yy] == '.'){
			map[xx + 1][yy] = 'A';
			map[xx][yy] = ' ';
			++xx;
            createCh(koX,koY,' ');
            ++koY;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx + 1][yy] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'd' || player == 'D'){
		if(map[xx][yy + 1] == ' '){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy + 1] == 'X'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy + 1] == '.'){
			map[xx][yy + 1] = 'A';
			map[xx][yy] = ' ';
			++yy;
            createCh(koX,koY,' ');
            koX += 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy + 1] == '#'){
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'a' || player == 'A'){
		if(map[xx][yy - 1] == ' '){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
		}
		else if(map[xx][yy - 1] == 'X'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			aktifScore(50);
		}
		else if(map[xx][yy - 1] == '.'){
			map[xx][yy - 1] = 'A';
			map[xx][yy] = ' ';
			--yy;
            createCh(koX,koY,' ');
            koX -= 2;
            createCh(koX,koY,'A');
			system("cls");
			lolosStage();
			break;
		}
		else if (map[xx][yy - 1] == '#'){	
			resetScore();
			system("cls");
			gameOver();
			break;
		}
	}
	else if(player == 'p' || player == 'P'){
		resetScore();
		system("cls");
		homeGame();
		break;
	}
	//-------------------------------- end Control User ----------------------------//
	}
}

//---------------------Alur Game-------------------//

// plot game
void alurGame(){
	stage1();
	stage2();
	stage3();

}

// game over
void gameOver(){
	boxGameOver();
	char parameter;
	while(true){
	char parameter = getch();
	linexy(100,0);
	if(parameter == 'B' || parameter == 'b'){
		homeGame();
		break;
	}else if(parameter == 'N' || parameter == 'n'){
		system("cls");
		exit(0);
	}
	}

}

