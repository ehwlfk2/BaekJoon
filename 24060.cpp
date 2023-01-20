/**
* 24060. 알고리즘 수업 - 병합 정렬 1
* 5 <= arrSize   <= 500_000, 
* 1 <= savePoint <= 10^8,
* 1 <= arrValue  <= 10^9
* 
* 병합 정렬 의사코드
merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
    if (p < r) then {
        q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
        merge_sort(A, p, q);      # 전반부 정렬
        merge_sort(A, q + 1, r);  # 후반부 정렬
        merge(A, p, q, r);        # 병합
    }
}

# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
merge(A[], p, q, r) {
    i <- p; j <- q + 1; t <- 1;
    while (i ≤ q and j ≤ r) {
        if (A[i] ≤ A[j])
        then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
        else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
    }
    while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
        tmp[t++] <- A[i++];
    while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
        tmp[t++] <- A[j++];
    i <- p; t <- 1;
    while (i ≤ r)  # 결과를 A[p..r]에 저장
        A[i++] <- tmp[t++]; 
}
*/
// header
#include<iostream>
#define size 500000

// global variable
using namespace std;
// int arr[size] = { 0, }, tmp[size] = { 0, }, save = 0, savePoint;
int arr[size] = { 0, }, tmp[size] = { 0, }, save = 0, savePoint;

// arr[p..q]와 arr[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// arr[p..q]와 arr[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];  // tmp[t] = arr[i]; t++; i++;
        else tmp[t++] = arr[j++];                   // tmp[t] = arr[i]; t++; j++;
    }
    while (i <= q) tmp[t++] = arr[i++];             // 왼쪽 배열 부분이 남은 경우
    while (j <= r) tmp[t++] = arr[j++];             // 오른쪽 배열 부분이 남은 경우

    i = p, t = 1;
    while (i <= r) {                // 결과를 arr[p..r]에 저장
        arr[i++] = tmp[t++];
        if (++save == savePoint) {  // 탈출 조건
            cout << arr[i - 1];
            exit(0);
        }
    }
}

// arr[p.. r]을 오름차순 정렬
void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;        // q는 p와 r의 중간 지점
        merge_sort(p, q);           // 전반부
        merge_sort(q + 1, r);       // 후반부
        merge(p, q, r);             // 병합
    }
}

int main(void) {
    //fastIO
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // local variable
    int arrSize;
    {
        cin >> arrSize >> savePoint;
    }
    // input
    for (int i = 0; i < arrSize; ++i) cin >> arr[i];

    // process
    merge_sort(0, arrSize - 1);

    // output
    cout << -1;

    return 0;
}