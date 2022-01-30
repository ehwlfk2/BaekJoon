#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int d[101];
int s[101];

int main()
{
    int tc;
    scanf("%d", &tc);
    int n, m, i, t;
    for (; tc--;) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i) scanf("%d", d + i), s[i] = -d[i];
        sort(s, s + n);
        t = 0;
        i = 0;
        while (true) {
            while (d[t] != -s[i]) t = (t + 1) % n;
            ++i;
            if (t == m) break;
            t = (t + 1) % n;
        }
        printf("%d\n", i);
    }
    return 0;
}
