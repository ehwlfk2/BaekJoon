/* 1269. 대칭 차집합
 * 집합 A 만 만들고, 집합 B 에 있는 원소가 있는지만 확인.
 * 정답: 양 집합 개수의 합 - 겹치는 원소 * 2
 */

/*
#include <iostream>
#include <set>
using namespace std;

int main(void) {
	//fastIO
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	set<int> books;
	int n, m, cnt, i, j;

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		cin >> j;
		books.insert(j);
	}

	auto end = books.end();
	for (i = cnt = 0; i < m; i++) {
		cin >> j;
		if (books.find(j) != end) cnt++;
	}

	cout << n + m - cnt * 2;

	return 0;
}
*/

/*
// Best Solution

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

namespace kx { //reference : https://github.com/voutcn/kxsort
    static const int kRadixBits = 8;
    static const size_t kInsertSortThreshold = 64;
    static const int kRadixMask = (1 << kRadixBits) - 1;
    static const int kRadixBin = 1 << kRadixBits;

    //================= HELPING FUNCTIONS ====================

    template <class T>
    struct RadixTraitsUnsigned {
        static const int nBytes = sizeof(T);
        int kth_byte(const T& x, int k) { return (x >> (kRadixBits * k)) & kRadixMask; }
        bool compare(const T& x, const T& y) { return x < y; }
    };

    template<class T>
    struct RadixTraitsSigned {
        static const int nBytes = sizeof(T);
        static const T kMSB = T(0x80) << ((sizeof(T) - 1) * 8);
        int kth_byte(const T& x, int k) {
            return ((x ^ kMSB) >> (kRadixBits * k)) & kRadixMask;
        }
        bool compare(const T& x, const T& y) { return x < y; }
    };

    template <class RandomIt, class ValueType, class RadixTraits>
    inline void insert_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        for (RandomIt i = s + 1; i < e; ++i) {
            if (radix_traits.compare(*i, *(i - 1))) {
                RandomIt j;
                ValueType tmp = *i;
                *i = *(i - 1);
                for (j = i - 1; j > s && radix_traits.compare(tmp, *(j - 1)); --j) {
                    *j = *(j - 1);
                }
                *j = tmp;
            }
        }
    }

    template <class RandomIt, class ValueType, class RadixTraits, int kWhichByte>
    inline void radix_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        RandomIt last_[kRadixBin + 1];
        RandomIt* last = last_ + 1;
        size_t count[kRadixBin] = { 0 };

        for (RandomIt i = s; i < e; ++i) {
            ++count[radix_traits.kth_byte(*i, kWhichByte)];
        }

        last_[0] = last_[1] = s;

        for (int i = 1; i < kRadixBin; ++i) {
            last[i] = last[i - 1] + count[i - 1];
        }

        for (int i = 0; i < kRadixBin; ++i) {
            RandomIt end = last[i - 1] + count[i];
            if (end == e) { last[i] = e; break; }
            while (last[i] != end) {
                ValueType swapper = *last[i];
                int tag = radix_traits.kth_byte(swapper, kWhichByte);
                if (tag != i) {
                    do {
                        std::swap(swapper, *last[tag]++);
                    } while ((tag = radix_traits.kth_byte(swapper, kWhichByte)) != i);
                    *last[i] = swapper;
                }
                ++last[i];
            }
        }

        if (kWhichByte > 0) {
            for (int i = 0; i < kRadixBin; ++i) {
                if (count[i] > kInsertSortThreshold) {
                    radix_sort_core_<RandomIt, ValueType, RadixTraits,
                        (kWhichByte > 0 ? (kWhichByte - 1) : 0)>
                        (last[i - 1], last[i], radix_traits);
                }
                else if (count[i] > 1) {
                    insert_sort_core_<RandomIt, ValueType, RadixTraits>(last[i - 1], last[i], radix_traits);
                }
            }
        }
    }

    template <class RandomIt, class ValueType, class RadixTraits>
    inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*, RadixTraits radix_traits) {
        if (e - s <= (int)kInsertSortThreshold)
            insert_sort_core_<RandomIt, ValueType, RadixTraits>(s, e, radix_traits);
        else
            radix_sort_core_<RandomIt, ValueType, RadixTraits, RadixTraits::nBytes - 1>(s, e, radix_traits);
    }

    template <class RandomIt, class ValueType>
    inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*) {
        if (ValueType(-1) > ValueType(0)) {
            radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsUnsigned<ValueType>());
        }
        else {
            radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsSigned<ValueType>());
        }
    }

    //================= INTERFACES ====================

    template <class RandomIt, class RadixTraits>
    inline void radix_sort(RandomIt s, RandomIt e, RadixTraits radix_traits) {
        typename std::iterator_traits<RandomIt>::value_type* dummy(0);
        radix_sort_entry_(s, e, dummy, radix_traits);
    }

    template <class RandomIt>
    inline void radix_sort(RandomIt s, RandomIt e) {
        typename std::iterator_traits<RandomIt>::value_type* dummy(0);
        radix_sort_entry_(s, e, dummy);
    }
}

int main() {
    struct stat st; fstat(0, &st);
    char* p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    auto ReadInt = [&]() {
        int ret = 0;
        for (char c = *p++; c & 16; ret = 10 * ret + (c & 15), c = *p++);
        return ret;
    };

    int n = ReadInt(), m = ReadInt(), v[n], w[m];
    for (int i = 0; i < n; i++) v[i] = ReadInt();
    for (int i = 0; i < m; i++) w[i] = ReadInt();
    kx::radix_sort(v, v + n); kx::radix_sort(w, w + m);

    vector<int> res; res.reserve(n + m);
    set_symmetric_difference(v, v + n, w, w + m, back_inserter(res));
    cout << res.size() << '\n';
}
*/

#include <cstdio>
#include <algorithm>
using namespace std;

// ============================== 읽고쓰기 ==============================
char buf[1 << 16];
int idx = 1 << 16;

inline char read() {
    if (idx == 1 << 16) {
        fread(buf, 1, 1 << 16, stdin);
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt() {
    int sum = 0;
    char now = read();

    while (now == ' ' || now == '\n') now = read();
    while (now >= '0' && now <= '9') {
        sum = sum * 10 + now - 48;
        now = read();
    }
    return sum;
}

//============================== 프로세스 ==============================
int main() {
    int a = readInt();
    int b = readInt();

    int i, j, cnt = 0, *arr;
    b += a;
    // malloc은 항상 성공하는 함수가 아닙니다.
    do {
        arr = (int*)malloc(sizeof(int) * b);
    } while (arr == NULL);

    // process
    for (i = 0; i < a; ++i) arr[i] = readInt();
    for (j = a; j < b; ++j) arr[j] = readInt();

    sort(arr, arr + a);
    sort(arr + a, arr + b);
    
    i = 0, j = a;
    while (i < a && j < b) {
        if (arr[i] < arr[j]) ++i;
        else if (arr[i] > arr[j]) ++j;
        else  ++i, ++j, ++cnt;
    }

    printf("%d", b - cnt * 2);
    return 0;
}