/**
* 25083. »õ½Ï
*/

/*
#include<iostream>
using namespace std;

int main(void) {
    string pnt = "         ,r'\"7\nr`-_   ,'  ,/\n \\. \". L_r\'\n   `~\\/\n      |\n      |\n";
    cout << pnt; 
    return 0;
}
*/

// http://egloos.zum.com/sweeper/v/3059035 C++ String literal
#include<stdio.h>

int main() {
    printf(
R"(         ,r'"7
r`-_   ,'  ,/
 \. ". L_r'
   `~\/
      |
      |
    )");
}
