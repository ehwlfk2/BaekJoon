#include<iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    printf("%s", (a > b) ? ">" : (a < b) ? "<" : "==");
    return 0;
}