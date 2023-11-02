#include "header.h"

//----------------------------Prototype------------------------//
void halamanAwal();
void dataBase();
void homeGame();
void transisi();
void createAkun();
void login();
void opsiGame();
void opsiLogin();
void score(int score);
int readScore();


//---------------------------prototype Map----------------------//
void map1();



//---------------------------prototype Game----------------------//
void stage1();



//---------------------------Menu dan Akun---------------------//

// HALAMAN AWAL DAN LOADING
void halamanAwal(){
	system("cls");
	system("color B");
	tulisanwelcome();

	loading(78, 16);
}

// data base
void dataBase(){
	ofstream data;
	string id;
	linexy(80, 15);
	cin >> id;
	string pin;
	linexy(80, 18);
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
	system("color 3");
	tulisanFindTreasure();
	createLineX(60, 112, 12  , 10, '-');
	createLineX(60, 112, 14  , 10, '-');
	createLineY(12, 14 , 59  , 10, '|' );
	createLineY(12, 14 , 113 , 10, '|' );
	createText(78, 13, "A Y O  M U L A I !");
	createText(77,14, "P I L I H  O P S I");
	createText(62,16, "1. Mulai");
	createText(62,17, "2. Beranda");

	// pilihan menu game
	createText(62, 20, "Jawaban anda (pilih nomor) : ");
	while(true){
		int jawab; cin >> jawab;
		switch(jawab){
			case 1 :
			stage1();
			system("cls");
			exit(0);

			case 2 :
			opsiLogin(); 
			break;

			default :
			createText(0,0, "tolong masukan opsi yang benar kon"); 
			break;

		}

	}
}

// login berhasil
void transisi(){
	system("cls");
	system("color A");
	createLineX(60, 112, 12  , 10, '-');
	createLineX(60, 112, 14  , 10, '-');
	createLineY(12, 14 , 59  , 10, '|' );
	createLineY(12, 14 , 113 , 10, '|' );
	createText(74, 13, "L O G I N  B E R H A S I L ");
	loading(78, 16);
	homeGame();
}

// pilihan buat akun
void createAkun(){
	system("cls");
	system("color 3e");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(62, 10, "F O R M  M E M B U A T  A K U N");
	createText(62, 14, "Format Username Berupa HURUF Semua");
	createText(62, 15, "Masukan Username : ");
	createText(62, 17, "Format Password Berupa ANGKA Semua");
	createText(62, 18, "Masukan Password : ");
	dataBase();

}

// pilihan dari login
void login(){
	string output;
	system("cls");
	system("color 3e");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(62, 10, "F O R M  L O G I N ");
	createText(62, 15, "Masukan Username :");
	createText(62, 18, "Masukan Password :");
	linexy(80, 15);
	string id;cin>>id;
	linexy(80, 18);
	string pw;cin>>pw;

	ifstream cekData;
	cekData.open("userAkun.txt");

    while(true){
        cekData >> output;
        if(output == id+pw){
			transisi();
            break;
        }
		if(cekData.eof()){
			createText(60, 10, "LOGIN GAGAL COBA LAGI!");
			delay(10000);
			system("cls");
			createAkun();
			login();
			break;
		}
    }
	cekData.close();

}

//tampilan awal game
void opsiGame(){
	system("cls"); 
	system("color c");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(77,14, "P I L I H  O P S I");
	createText(62,16, "1. Mulai");
	createText(62,17, "2. Beranda");

	// pilihan login
	createText(62, 20, "Jawaban anda (pilih nomor) : ");
	int jawab; cin >> jawab;
	switch(jawab){
		case 1 :
		stage1();
		break;

		case 2 :
		system("cls"); 
		break;

		default :
		system("cls"); 
		return;

	}

}

//tampilan awal login
void opsiLogin(){
	system("cls"); 
	system("color c");
	createLineY(12, 21 , 59  , 1);
	createLineY(12, 21 , 113 , 1);
	createLineX(60, 112, 21, 1);
	createLineX(60, 112, 12, 1);
	createText(77,14, "P I L I H  O P S I");
	createText(62,16, "1. Login");
	createText(62,17, "2. Buat Akun");
	createText(62,18, "3. Keluar");

	// pilihan login
	createText(62, 20, "Jawaban anda (pilih nomor) : ");
	int jawab; cin >> jawab;
	switch(jawab){
		case 1 :
		login();
		break;

		case 2 :
		createAkun();
		login();
		break;

		default :
		system("cls"); 
		exit(0);

	}

}

// tempat penyimpanan data high score dan nama user
void score(int score){
	ofstream buatScore;

	if(score >= readScore()){
		buatScore.open("highScore.txt");
		buatScore << score;
		buatScore.close();
	}
}

int readScore(){
	ifstream cekData;

	int output;

	cekData.open("highScore.txt");
	cekData >> output;
	cekData.close();

	return output;
}



//---------------------Map Game----------------------//
void map1(){
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
	createText(0,30,"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # . . # # #");
}

//---------------------Coding Game-------------------//
void stage1(){
	system("cls");
	system("color c");
    map1();
	char player;
	int xx, yy,koX,koY,totalScore, highScore;
	xx = 1;
	yy = 1;
    koX = 2;
    koY = 1;
	totalScore = 0;
	highScore = 0;


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
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.',' ','#','#','#'
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
		
		if(totalScore >= highScore){
			highScore = totalScore;
			score(highScore);
		}

		linexy(100,5);
		cout<<"Score Anda Sekarang : "<< totalScore;
		linexy(100,7);
		cout<< "High Score : "<<readScore();
		linexy(120,36);

//------------------------ Control User ------------------//
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
			totalScore += 50;
		}
		else if (map[xx - 1][yy] == '#'){
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
			totalScore += 50;
		}
		else if (map[xx + 1][yy] == '#'){
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
			totalScore += 50;
		}
		else if (map[xx][yy + 1] == '#'){
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
			totalScore += 50;
		}
		else if (map[xx][yy - 1] == '#'){	
			break;
		}
	}
	else if(player == 'p' || player == 'P'){
		system("cls");
		break;
	}
//------------------------ end Control User ------------------//
}
}
