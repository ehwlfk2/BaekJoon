#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "InputGenerator.h"

void generate() {
    FILE* out = fopen("input.txt", "w");
    int n = 10;

    srand(time(NULL));

    fprintf(out, "%d\n", n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) fprintf(out, "%d ", rand() * 10 / RAND_MAX);
        fprintf(out, "\n");
    }

    fclose(out);
}

int main() {
    generate();
    solve1();
    solve2();

    return 0;
}