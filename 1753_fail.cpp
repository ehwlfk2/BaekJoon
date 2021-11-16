#include<iostream>
#define V 20001 // 20,000
#define E 300000 // 300,000
#define INT_MAX 2147483647
using namespace std;

class shortestPath {
private:
	int vertex[V];
	int edge[E][3];
	int startVertex, v, e;

	void swap(int i, int j) {
		int* a = edge[i];
		int* b = edge[j];

		int p[3] = { a[0], a[1], a[2] };
		a[0] = b[0], a[1] = b[1], a[2] = b[2];
		b[0] = p[0], b[1] = p[1], b[2] = p[2];
	}

	int partition(int st, int ed) {
		int low = st, high = ed + 1, pivot = edge[st][0];

		while (low < high) {
			do { low++; } while (!(edge[low][0] > pivot) && low < high);
			do { high--; } while (edge[high][0] > pivot && low <= high);

			if (low < high) swap(low, high);
		}
		swap(st, high);
		return high;
	}

	void quickSortToEdge(int st, int ed) {
		if (st < ed) {
			int q = partition(st, ed);

			quickSortToEdge(st, q - 1);
			quickSortToEdge(q + 1, ed);
		}
	}
public:
	shortestPath() {
		cin >> v >> e;

		cin >> startVertex;
		for (int i = 0; i < e; i++) {
			// startVertex => 0
			int st, ed;
			cin >> st >> ed >> edge[i][2];
			edge[i][0] = st - startVertex < 0 ? st - startVertex + v : st - startVertex;
			edge[i][1] = ed - startVertex < 0 ? ed - startVertex + v : ed - startVertex;
		}

		for (int i = 0; i < v; i++) vertex[i] = INT_MAX;
	}

	void findShortestPath() {
		quickSortToEdge(0, e - 1);

		vertex[0] = 0;

		for (int i = 0; i < e; i++) {
			int* p = edge[i];
			int weight = vertex[p[0]] + p[2];
			p = &p[1];
			if (vertex[*p] > weight && weight >= 0) vertex[*p] = weight;
		}

		printVertex(v - startVertex + 1, v);
		printVertex(0, v - startVertex + 1);
	}

	void printVertex(int st, int ed) {
		for (int i = st; i < ed; i++) {
			if (vertex[i] == INT_MAX)
				printf("INF\n");
			else
				printf("%d\n", vertex[i]);
		}
	}
};

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	while (1) {
		shortestPath* sp = new shortestPath();
		sp->findShortestPath();
		delete(sp);
	}
	return 0;
}