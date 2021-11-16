#include<iostream>
using namespace std;

typedef struct node {
	int vertex;
	int weight;
	struct node* link;
}node;

class shortestPath {
private:
	int v, e, stv, mi;
	node* memory, * p;



public:
	// ������
	shortestPath() {
		cin >> v >> e >> stv;
		memory = new node[e+v+10];
		// �ʱ�ȭ �ϴ� ���� ����� ������?
		for (int i = 0; i < v + 1; i++) {
			p[i] = memory[mi++];
		}

		mi = 0;
		for (int i = 0; i < e; i++) {
			int st;
			cin >> st >> memory[mi].vertex >> memory[mi].weight;
			memory[i].link = NULL;

			if (p[st].link == NULL) p[st].link = &memory[mi++];
			else {
				node* tmp = p[st].link;
				int weight = memory[mi].weight;
				
				// ���� ����, �ߺ����� ����.
				while (tmp->link != NULL) {
					if (tmp->link->weight < weight) { // ���Ե� ����� ���԰� ���̴�.
						tmp = tmp->link;
					}
					else { // ���Ե� ����� ���԰� ������.
						memory[mi].link = before->link;

					}
				}
				if(tmp->link == NULL) tmp->link = &memory[mi++];
			}

		}
	}


};


int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	shortestPath* sp = new shortestPath();
	delete(sp);
	return 0;
}