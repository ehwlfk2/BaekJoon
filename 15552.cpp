#include<iostream>

int main(void) {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }

    return 0;
}