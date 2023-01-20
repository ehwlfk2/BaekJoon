/**
 * 1764. �躸��
 * �赵 ���� ��� �� N, ���� ���� ��� �� M.
 * �̸��� ���ĺ����θ� �̷����ְ� ���̴� 20 ����.
 * N, M�� 500,000 ������ �ڿ����̴�.
 * 
 * 24060. ���� ���� ���������� �����Դ�.
 */
#include<iostream>
#include<string>
#define size 2 << 18
// global variable
using namespace std;
// int listen[size] = { 0, }, look[size] = { 0, }, tmp[size] = { 0, };
string listen[size] = {}, look[size] = {}, tmp[size] = {};

// arr[p..q]�� arr[q+1..r]�� �����Ͽ� A[p..r]�� �������� ���ĵ� ���·� �����.
// arr[p..q]�� arr[q+1..r]�� �̹� ������������ ���ĵǾ� �ִ�.
void merge(string* arr, int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];  // tmp[t] = arr[i]; t++; i++;
        else tmp[t++] = arr[j++];                   // tmp[t] = arr[i]; t++; j++;
    }
    while (i <= q) tmp[t++] = arr[i++];             // ���� �迭 �κ��� ���� ���
    while (j <= r) tmp[t++] = arr[j++];             // ������ �迭 �κ��� ���� ���

    i = p, t = 1;
    while (i <= r) arr[i++] = tmp[t++];             // ����� arr[p..r]�� ����
}

// arr[p.. r]�� �������� ����
void merge_sort(string* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;        // q�� p�� r�� �߰� ����
        merge_sort(arr, p, q);           // ���ݺ�
        merge_sort(arr, q + 1, r);       // �Ĺݺ�
        merge(arr, p, q, r);             // ����
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