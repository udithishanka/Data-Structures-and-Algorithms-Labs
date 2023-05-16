#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;
    list<int> neighbors;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    void addEdge(int u, int v) {
        // Add v to the neighbor list of u
        nodes[u - 1].neighbors.push_back(v);

        // Add u to the neighbor list of v
        nodes[v - 1].neighbors.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << i + 1 << " neighbors: ";
            for (int neighbor : nodes[i].neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] nodes; // Deallocate the memory used for nodes
    }
};

int main() {
    Graph * g = new Graph;// Create a Graph object directly

    g->initializeNodes();

    // Add edges for the graph
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 8);
    g->addEdge(5, 7);
    g->addEdge(5, 6);
    

    // Print the graph adjacency list
    g->print();

    return 0;
}
