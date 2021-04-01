/*

   Made By LanGong Development Team,
   2020

*/




/*
 * LanGong OhZff Zff game is undered MIT-License
 *
 * MIT License
 *
 * Copyright (c) 2020 LanGongDEV
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
*/




/*
* Main Zff file (for Linux and MacOS)
*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>

#include<curses.h>
#include <unistd.h>
// #include <signal.h>
// #include <termios.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
#include "getkeyboard.cpp"
#include "defines.hpp"
using namespace std;

int display_log = 0;
//#include "getshell.hpp"
#include "get.cpp"
#include "type.cpp"
typedef const int ci;
typedef const char cc;
typedef const double cd;


void printlogo()
{
  printf ("  __________    _________    _________\n /          \\  /         \\  /         \\\n \\_______   /  |   ______/  |   ______/\n        /  /   |  /         |  /\n       /  /    |  \\______   |  \\______\n      /  /     |         \\  |         \\\n     /  /      |   ______/  |   ______/\n    /  /       |  /         |  /\n   /  /        |  |         |  |\n  /  /         |  |         |  |\n /   \\______   |  |         |  |\n |          \\  |  |         |  |\n \\__________/  \\__/         \\__/\n\n Zff game is made by LanGong Development Team.\n");
}



cc fu='F',you='H';
cc winok[10][100] = {
  "Excellent",
  "Great",
  "Well done",
  "Good",
  "Wonderful",
  "Perfect"
};
cc ebox[20][250] = {
  "",
  " ---------- Error 1: Out ----------",
  " ---------- Error 2: Install error ----------",
  " ---------- Error 3: Start game error ----------",
  " ---------- Error 4: Input error ----------",
  " ---------- Error 5: User not found ----------\n run 'zff init' to fix.\n"
};
int tr,kd,fx,fy,hx,hy,s=0;
int sysE;

int keyboard()
{
	// return getchar();
	// if(read(kfd, &c, 1) < 0)
	// {
	// 	perror("read():");
	// 	exit(-1);
	// }
	//
	// switch(c)
	// {
	// 	case KEYCODE_L:
	// 		// printf("LEFT\n");
	// 		return 75;
	// 		break;
	// 	case KEYCODE_R:
	// 		// printf("RIGHT\n");
	// 		return 77;
	// 		break;
	// 	case KEYCODE_U:
	// 		// printf("UP\n");
	// 		return 72;
	// 		break;
	// 	case KEYCODE_D:
	// 		// printf("DOWN\n");
	// 		return 80;
	// 		break;
	// 			default:
	// 						// printf("value: %c = 0x%02X = %d\n", c, c, c);
	// }
	return key::getkey();
}
void syscls()
{
	system("clear");
}
int check(int num){
	if(num==72||num=='w'||num=='W')return 1;
	if(num==80||num=='s'||num=='S')return 2;
	if(num==75||num=='a'||num=='A')return 3;
	if(num==77||num=='d'||num=='D')return 4;
	if(num==10)return 13;
	if(num==114)return 7;
	if(num==112)return 8;
	if(num==113)return 9;
	if(num==27)return 27;
  if(num==224||num==-32)return -1;
	else return 0;
}
ci nx[5]={0,-1,1,0,0};//sxzy
ci ny[5]={0,0,0,-1,1};
int n,field[10005][10005];
int level;
string name;

int win ()
{
  //SHOW_CURSOR();
  putlevel(level+1);
  system("clear");
  int rcc = rand() % 6;
  printf(" %s! Your new level is: %d\n Play again? [Again : Enter / quit : q ]\n",winok[rcc],level+1);
  while(1){
    int r=check(keyboard());
    if(r==9){
      SHOW_CURSOR();
      return 0;
    }
    else if (r==1||r==2||r==3||r==4||r==27||r==-1)continue;
    else if(r==13)return 1;
    else{
      //printf("------ERR4: Input Error, Pleese Input Again------\n");
    }
  }
}

/*

//This is for pause

bool getpalse(){
	int typeU;
	fstream file;
	file.open("palseZ.dll", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	if(typeU==1){
		fstream file;
		file.open("palseF.dll", ios::in);
		streambuf* stream_buffer_cout = cout.rdbuf();
		streambuf* stream_buffer_cin = cin.rdbuf();
		streambuf* stream_buffer_file = file.rdbuf();
		cin.rdbuf(stream_buffer_file);
		cin>>n>>hx>>hy>>fx>>fy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>field[i][j];
			}
		}
		cin.rdbuf(stream_buffer_cin);
		file.close();
		return true;
	}
	return false;
}
void putpalse(){
	fstream file;
	file.open("palseZ.dll", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	syscls();
	cout<<1;
	cout.rdbuf(stream_buffer_cout);
	file.close();
	if(1==1){
		fstream file;
		file.open("palseF.dll", ios::out);
		streambuf* stream_buffer_cout = cout.rdbuf();
		streambuf* stream_buffer_cin = cin.rdbuf();
		streambuf* stream_buffer_file = file.rdbuf();
		cout.rdbuf(stream_buffer_file);
		syscls();
		cout<<n<<hx<<hy<<fx<<hy<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<field[i][j]<<" ";
			}
			cout<<endl;
		}
		cout.rdbuf(stream_buffer_cout);
		file.close();
	}
}

//This is for pause

*/
void maken(){
	putlevel(0);
	level=getlevel();
	putboot(1);
	printf("Welcome to Zff Game, Made by LanGongDEV\n");
	sleep(1);
	printf("Pleese set a username: \n");
	string UserNameSET;
	getline(cin,UserNameSET);
	putuser(UserNameSET);
	printf("Setting successfully\n");
	sleep(1);
	syscls();
	sleep(1);
}
int start(){
	// system("color F0");
	system("echo $HOME > /tmp/zffuser; clear");
  //system ("cp -r ~/.local/share/ohzff-zff ./zffcc");
  getdir();
  getinit();
  /*
	printf("\n\n\n              LanGongINC \n              LanGongDEV \n");
	sleep(3);
	system("clear");
	printf("Welcome\n");
	*/
  if (display_log) printf (" >> Starting Zff Game...\n");
  //printf (" >> Copy config files\n");
  //system ("cp ")
  level=getlevel();
  //if (display_log) sleep (5);
	//system("clear");
	//printf("                Zff \n\n\n\n\n\n\n\n\n\n         Welcome!\n");
	//sleep(3);
  printlogo();
	if(level==-1||getboot()!=1){
		//maken();
    printf ("%s\n", ebox[5]);
    exit (-5);
	}
	//system("clear");
	level=getlevel();
	name=getuser();
	cout<<endl<<" Login as "<<name<<endl;
	printf(" Your level is: %d\n",level);
	sleep(1);
	if(level==-1){
		return 1;
	}
	else return 0;
}
int game(){
	s=0;
  char rce[300]="";
	while(true){
		if(fx==hx&&fy==hy){
			return win();
		}
		//system("clear");
    MOVETO(1,1);
    //printf ("  User %s, level %d", name, level);
    cout << "  Login as " << name << ", level is " << level << ". Good luck!\n";
    printf ("  %s\n", rce);
    strcpy(rce,"                                                  ");
		for(int i=1;i<=n;i++){
			for(int j=0;j<27-n;j++){
				cout<<" ";
			}
			for(int j=1;j<=n;j++){
				if(field[i][j]==0)cout<<" ";
				if(field[i][j]==1)cout<<"-";
				if(field[i][j]==2)cout<<"|";
				if(field[i][j]==5)cout<<"H";
				if(field[i][j]==6)cout<<"F";
			}
			cout<<endl;
		}
		printf("\n Use 'UP''DOWN''LEFT''RIGHT' to contral 'H' to catch 'F'\n Press 'R' to restart game\n Press 'Q' to quit game\n");
    MOVETO(1,1);
		int r=check(keyboard());
		// printf("%d\n",r);
		// sleep(1);
		if(r==224||r==-32)continue;
		if(r==7){
			syscls();
			return 1;
		}
		if(r==9){
			syscls();
			return 0;
		}
		if(r!=1 && r!=2 && r!=3 && r!=4 && r!=0 && r!=27){
			//system("clear");
			//printf("%s",ebox[4]);
      strcpy(rce,ebox[4]);
			//printf("%d",r);
			//sleep(0.1);
			//syscls();
			continue;
		}
		if(r>0&&r<5){
			//move
			//system("clear");
			if(hx+nx[r]<=1||hx+nx[r]>n-1||hy+ny[r]<=1||hy+ny[r]>n-1){
				//printf("%s", ebox[1]);
        strcpy(rce,ebox[1]);
				//sleep(0.1);
				continue;
			}
			if(field[hx+nx[r]][hy+ny[r]]==6){
        return win ();
			}
			if(field[hx+nx[r]][hy+ny[r]]==0){
				hx=hx+nx[r];
				hy=hy+ny[r];
				field[hx][hy]=5;
				field[hx-nx[r]][hy-ny[r]]=0;
			}
		}
		if(s>=level+5){
			s=0;
			continue;
		}
		int but[5];
		memset(but,0,sizeof(but));
		for(int i=1;i<=4;i++){
			if(fx+nx[i]<=1||fx+nx[i]>n-1||fy+ny[i]<=1||fy+ny[i]>n-1){
				but[i]=1;
			}
			if(field[fx+nx[i]][fy+ny[i]]!=0){
				but[i]=1;
			}
		}
		int tx=fx,ty=fy;
		if(hx<fx&&but[2]==0){
			fx+=nx[2];
			fy+=ny[2];
		}
		else if(hx>fx&&but[1]==0){
			fx+=nx[1];
			fy+=ny[1];
		}
		else if(hy<fy&&but[4]==0){
			fx+=nx[4];
			fy+=ny[4];
		}
		else if(hy>fy&&but[3]==0){
			fx+=nx[3];
			fy+=ny[3];
		}
		else{
			if(but[1]==0){
				fx+=nx[1];
				fy+=ny[1];
			}
			else if(but[2]==0){
				fx+=nx[2];
				fy+=ny[2];
			}
			else if(but[3]==0){
				fx+=nx[3];
				fy+=ny[3];
			}
			else if(but[4]==0){
				fx+=nx[4];
				fy+=ny[4];
			}
		}
		field[fx][fy]=6;
		field[tx][ty]=0;
		s++;
	}
}
void start_game(){
	syscls();
	memset(field,0,sizeof(field));
	if(level<=10){
		n=10,tr=24,kd=40;
	}
	else if(level<=20){
		n=12,tr=34,kd=66;
	}
	else if(level>20){
		n=15,tr=50,kd=119;
	}
	/*
	0:_
	1:-
	2:|
	5:H
	6:F
	*/
	field[1][1]=field[n][n]=1;
	field[1][n]=field[n][1]=1;
	for(int i=2;i<=n-1;i++){
		field[1][i]=field[n][i]=1;
		field[i][1]=field[i][n]=2;
	}
	// for(int i=2;i<=n-1;i++){
	// 	for(int j=2;j<=n-1;j++){
	// 		while(true){
	// 			int k=rand();
	// 			if(k==0&&kd>0){
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	//printf("NIHAO\n");
	level=getlevel();
	fx=n-1,fy=n-1,hx=2,hy=2;
	field[2][2]=5,field[n-1][n-1]=6;
  HIDE_CURSOR();
	if(game()==1)start_game();
  RESET_CURSOR();
  SHOW_CURSOR();
}
/*

//This is for pause

void findpalse(){
	if(getpalse()){
		game();
	}
	else{
		start_game();
	}
}

//This is for pause

*/
//This is for not pause

void findpalse(){
	start_game();
}

//This is for not pause

void goodbye(){
	system("clear");
  SHOW_CURSOR();
  //system ("rm -rf ~/.local/share/ohzff-zff && mv zffcc ~/.local/share/ohzff-zff");
  printlogo();
  printf("\n Exit Zff game.\n");
  sleep(1);
	system("clear");
}

void ready ()
{
  if(start()){
    printf("%s", ebox[3]);
    //return 3;
    exit(3);
  }
}

int main(int argc, char* argv[]){
  if(argv[1] == NULL)
  {
    ready();
  }
  else if (strcmp (argv[1], "log") == 0)
  {
    display_log = 1;
    ready();
  }
	else if (strcmp(argv[1], "init") == 0)
  {
    if (display_log) printf (" >> Waiting 'init.sh'\n");
    system ("bash /usr/share/ohzff-zff/init.sh || bash ./init.sh");
    return 0;
  }
  else if (strcmp(argv[1], "update") == 0)
  {
    //system ("cd /usr/share/ohzff-zff && git pull && g++ zff_main_en.cpp -o /usr/bin/zff");
    if (display_log) printf (" >> You cannot use this via to update the game. Try to use git\n");
    return 0;
  }
  else if (strcmp(argv[1], "debug") == 0)
  {
    //printf ("%d\n", win());
    if (display_log) printf (" >> Debug mod and exit with %d\n", 6);
    return 6;
  }
  else if (strcmp(argv[1], "license") == 0)
  {
    printf (" LanGong OhZff Zff game is undered MIT License.\n\n\n");
    printf ("MIT License\n\nCopyright (c) 2020 LanGongDEV\n\nPermission is hereby granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files (the \"Software\"), to deal\nin the Software without restriction, including without limitation the rights\nto use, copy, modify, merge, publish, distribute, sublicense, and/or sell\ncopies of the Software, and to permit persons to whom the Software is\nfurnished to do so, subject to the following conditions:\n\n  The above copyright notice and this permission notice shall be included in all\n  copies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\nAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\nOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\nSOFTWARE.\n");
    return 0;
  }
  else
  {
    printf ("%s\n", ebox[4]);
    return 4;
  }
	sleep(1);
	findpalse();
	goodbye();
	return 0;
}
