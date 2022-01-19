#include <iostream>

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

template <typename T>
class Queue {
private:
	int capacity;
	int f, b;
	T* q;

public:
	Queue(int capacity) {
		// init
		b = 1;
		f = 0;
		this->capacity = capacity + 1;

		q = new T[this->capacity];
	}

	void push(T value) {
		// front == capacity 이면 FULL
		q[b++] = value;
	}

	T pop() {
		if (empty()) return -1;
		return q[++f];
	}

	int size() {
		return b - f - 1;
	}

	int empty() {
		return b == f + 1 ? 1 : 0;
	}

	T front() {
		if (empty()) return -1;
		return q[f + 1];
	}

	T back() {
		if (empty()) return -1;
		return q[b - 1];
	}

	~Queue() {
		delete q;
	}
}; // 배열 Queue

/*
push	: 	0
pop		:	1
size	:	2
empty	:	3
front	:	4
back	:	5
*/
int transOrder(std::string order) {
	char tmp = order.operator[](0);
	switch (tmp) {
	case 'p':
		tmp = order.operator[](1);
		return tmp == 'u' ? 0 : 1;
	case 's':
		return 2;
	case 'e':
		return 3;
	case 'f':
		return 4;
	case 'b':
		return 5;
	}
	// 에러.
	exit(1);
}

int main(void) {
	setting();

	int repeat, num;
	std::string order;
	// 입력받는 명령의 갯수
	std::cin >> repeat;
	Queue<int> q = repeat;

	while (repeat--) {
		std::cin >> order;
		switch (transOrder(order)) {
		case 0:
			std::cin >> num;
			q.push(num);
			break;
		case 1:
			printf("%d\n", q.pop());
			break;
		case 2:
			printf("%d\n", q.size());
			break;
		case 3:
			printf("%d\n", q.empty());
			break;
		case 4:
			printf("%d\n", q.front());
			break;
		case 5:
			printf("%d\n", q.back());
			break;
		}
	}

	return 0;
}