#include<iostream>
using namespace std;

int main(void) {
    int score;
    char c;
    cin >> score;

    if (score >= 90) c = 'A';
    else if (score >= 80) c = 'B';
    else if (score >= 70) c = 'C';
    else if (score >= 60) c = 'D';
    else c = 'F';
    
    printf("%c", c);
    return 0;
}