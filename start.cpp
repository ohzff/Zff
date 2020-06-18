#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
  printf (" -----| Welcome |----- \n");
  printf ("|                     |\n");
  printf ("|  Welcome to LanGong |\n");
  printf ("| Zff Game for Linux. |\n");
  printf ("|                     |\n");
  printf (" --------------------- \n");
  printf (" >> Choose a language. \n    > (1) Chinese\n    > (2) English\n");
  int language;
  scanf ("%d", &language);
  if (language == 1){
    system ("clear && ./zff-ch");
  }
  else if (language == 2){
    system ("clear && ./zff-en");
  }
  else{
    printf (" >> ERROR-03: Start Error, '%d' is not a value.\n", language);
    exit(3);
  }
  return 0;
}
