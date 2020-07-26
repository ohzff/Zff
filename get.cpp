#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
char* getchuser()
{
  char* a;
	fstream file;
	file.open("zffcc/user", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
  cin >> a;
	cin.rdbuf(stream_buffer_cin);
	file.close();
  return a;
}
int getlevel(){
	int typeU;
	fstream file;
	file.open("zffcc/level", ios::in);
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
	file.open("zffcc/level", ios::out);
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
	file.open("zffcc/boot", ios::in);
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
	file.open("zffcc/boot", ios::out);
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
	file.open("zffcc/user", ios::in);
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
	file.open("zffcc/user", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
