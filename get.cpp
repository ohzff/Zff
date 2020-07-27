#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

char dir[1000]; 
char lev[1000], bot[1000], usr[1000];
void getdir(){
	//int typeU;
	fstream file;
	file.open("/tmp/zffuser", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>dir;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	//return typeU;
  if (display_log) cout << " >> Getting user config dir\n     " << dir << endl;
}
void getinit()
{
  //strcat(dir, gshell("echo $HOME/.local/share/ohzff-zff/"));
  strcat(dir, "/.local/share/ohzff-zff/");
  strcpy(lev,dir);
  strcpy(bot,dir);
  strcpy(usr,dir);
  strcat(lev,"level");
  strcat(bot,"boot");
  strcat(usr,"user");
  if (display_log){
    cout << " >> Getting config file path\n";
    cout << "   -> Level : " << lev << endl;
    cout << "   -> Boot : " << bot << endl;
    cout << "   -> Username : " << usr << endl;
  } 
}
int getlevel(){
	int typeU;
	fstream file;
	file.open(lev, ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putlevel(int n){
	fstream file;
	file.open(lev, ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
int getboot(){
	int typeU;
	fstream file;
	file.open(bot, ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putboot(int n){
	fstream file;
	file.open(bot, ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
string getuser(){
	string typeU;
	fstream file;
	file.open(usr, ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	getline(cin,typeU);
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putuser(string n){
	fstream file;
	file.open(usr, ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
