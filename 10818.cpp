#include<iostream>
using namespace std;

int main(void) {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int T, min = 1000001, max = 0, num;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> num;
        if (num > max) max = num;
        if (num < min) min = num;
    }
    printf("%d %d\n", min, max);
    return 0;
}