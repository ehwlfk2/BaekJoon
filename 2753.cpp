#include<iostream>
using namespace std;

int main(void) {
    int year;
    cin >> year;

    printf("%d", !(year % 400) ? 1 : !(year % 100) ? 0 : !(year % 4) ? 1 : 0);
    return 0;
}