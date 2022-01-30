// 1966. 우선순위 큐의 변형
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node {
	int idx, ipt;
	struct node* link;
}node;

node* doc = new node[100], * back, * front;
int docIdx;

// 문서 순서와 중요도
void push(int idx, int ipt) {
	if (docIdx > 0) {
		doc[docIdx - 1].link = &doc[docIdx];
	}

	doc[docIdx].idx = idx;
	doc[docIdx].ipt = ipt;
	doc[docIdx].link = NULL;

	back = &doc[docIdx++];
}

void push(node* p) {
	back->link = p;
	back = p;
	p->link = NULL;
}

bool compare(int a, int b) {
	return a > b;
}

void setting() {
	// std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();

	// process field
	int repeat, docs, n;
	cin >> repeat;

	// field
	int sortQueue[101], s, ipt;
	node* p, * bp;

	// process
	while (repeat--) {
		cin >> docs >> n;

		// init
		front = doc;

		// insert
		for (docIdx = s = 0; s < docs; s++) {
			cin >> ipt;
			sortQueue[s] = ipt;
			push(s, ipt);
		}

		// sorting
		sort(sortQueue, sortQueue + s, compare);

		// Queue 배치, sortQueue와 doc의 값이 같으면 next, 아니면 Queue의 맨 끝으로 이동
		p = front, bp = NULL, s = 0, ipt = 1;
		while (p != back) {
			if (sortQueue[s] == p->ipt) {
				if (p->idx == n) break;
				ipt++;
				bp = p;
				p = p->link;
				s++;
			}
			else {
				node* tmp = p->link;
				// 첫번째 노드가 아니면
				if (bp != NULL) {
					bp->link = p->link;
				}
				// 첫번째 노드라면
				else {
					front = p->link;
				}
				push(p);
				p = tmp;
			}
		}

		// print
		printf("%d\n", ipt);
		} // while(repeat)

	return 0;
}