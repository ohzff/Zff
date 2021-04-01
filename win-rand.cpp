#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
int r(int n){
	srand((unsigned)time(NULL));
	return rand()%n;
}
