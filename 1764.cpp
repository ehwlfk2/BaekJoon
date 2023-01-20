/**
 * 1764. 듣보잡
 * 듣도 못한 사람 수 N, 보도 못한 사람 수 M.
 * 이름은 알파벳으로만 이뤄져있고 길이는 20 이하.
 * N, M은 500,000 이하의 자연수이다.
 * 
 * 24060. 에서 만든 병합정렬을 가져왔다.
 */
#include<iostream>
#include<string>
#define size 2 << 18
// global variable
using namespace std;
// int listen[size] = { 0, }, look[size] = { 0, }, tmp[size] = { 0, };
string listen[size] = {}, look[size] = {}, tmp[size] = {};

// arr[p..q]와 arr[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// arr[p..q]와 arr[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(string* arr, int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];  // tmp[t] = arr[i]; t++; i++;
        else tmp[t++] = arr[j++];                   // tmp[t] = arr[i]; t++; j++;
    }
    while (i <= q) tmp[t++] = arr[i++];             // 왼쪽 배열 부분이 남은 경우
    while (j <= r) tmp[t++] = arr[j++];             // 오른쪽 배열 부분이 남은 경우

    i = p, t = 1;
    while (i <= r) arr[i++] = tmp[t++];             // 결과를 arr[p..r]에 저장
}

// arr[p.. r]을 오름차순 정렬
void merge_sort(string* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;        // q는 p와 r의 중간 지점
        merge_sort(arr, p, q);           // 전반부
        merge_sort(arr, q + 1, r);       // 후반부
        merge(arr, p, q, r);             // 병합
    }
}

int process(const int listenall, const int lookAll){
    int i = 0, j = 0, compare, cnt = 0;
    while (i < listenall && j < lookAll) {
        compare = listen[i].compare(look[j]);
        if (compare < 0)
            ++i;
        else if (compare > 0)
            ++j;
        else
            ++i, tmp[cnt++] = look[j++];
    }

    return cnt;
}

int main(void) {
    //fastIO
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int listenAll, lookAll;
    cin >> listenAll >> lookAll;

    for (int i = 0; i < listenAll; ++i) cin >> listen[i];
    for (int i = 0; i < lookAll; ++i) cin >> look[i];

    merge_sort(listen, 0, listenAll - 1);
    merge_sort(look, 0, lookAll - 1);

    int cnt = process(listenAll, lookAll);
    cout << cnt << "\n";
    for (int i = 0; i < cnt; ++i) cout << tmp[i] << "\n";

	return 0;
}   