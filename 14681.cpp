#include<iostream>
using namespace std;

int main(void) {
    int x, y;
    cin >> x >> y;

    printf("%d", x > 0 && y > 0 ? 1 : x < 0 && y<0 ? 3 : x>y ? 4 : 2);
    return 0;
}