#include <iostream>
using namespace std;


struct Node {
	int val;
	Node* next;
};

struct Edge {
	int src, dest;
};


class Graph {
	int totalNodes;

	Node* getAdjListNode(int dest, Node* head) {
		Node* newNode = new Node;
		newNode->val = dest;
		newNode->next = head;
		return newNode;
	}
public:
	Node** head;
	Graph(Edge edges[], int n, int totalNodes) {
		head = new Node * [totalNodes]();
		this->totalNodes = totalNodes;

		for (int i = 0; i < totalNodes; i++) {
			head[i] = NULL;
		}
		for (int i = 0; i < n; i++) {
			int src = edges[i].src;
			int dest = edges[i].dest;
			Node* newNode = getAdjListNode(dest, head[src]);
			head[src] = newNode;
		}
	}

};

// print all neighboring vertices of given vertex
void printList(Node* ptr) {
	while (ptr != nullptr) {
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
int main() {
	// array of graph edges as per above diagram.
	Edge edges[] = {
		// pair (src, dest) represents edge from src to dest
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int N = 6;
	int n = sizeof(edges) / sizeof(edges[0]);

	Graph graph(edges, n, N);
	for (int i = 0; i < N; i++) {
		cout << i << " --";
		printList(graph.head[i]);
	}

	return 0;
}
