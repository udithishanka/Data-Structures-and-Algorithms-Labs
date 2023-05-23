#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to compare edges based on weight (used for priority queue)
struct CompareEdge {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

// Function to calculate and print the minimum spanning tree
void calculateMST(const vector<vector<int>>& graph, int startNode) {
    int numVertices = graph.size();

    // Create a priority queue to store edges
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;

    // Create a vector to track the minimum key values for each vertex
    vector<int> key(numVertices, INT_MAX);

    // Create a vector to store the parent of each vertex in the MST
    vector<int> parent(numVertices, -1);

    // Create a vector to track visited vertices
    vector<bool> visited(numVertices, false);

    // Start with the specified node
    key[startNode] = 0;

    // Add all edges from the start node to the priority queue
    for (int i = 0; i < numVertices; ++i) {
        if (graph[startNode][i] != 0) {
            Edge e = {startNode, i, graph[startNode][i]};
            pq.push(e);
        }
    }

    // Process all vertices
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int src = e.src;
        int dest = e.dest;
        int weight = e.weight;

        // If the destination vertex is not visited and the weight is smaller than the current key, update the minimum key and parent
        if (!visited[dest] && weight < key[dest]) {
            key[dest] = weight;
            parent[dest] = src;

            // Add all edges from the destination vertex to the priority queue
            for (int i = 0; i < numVertices; ++i) {
                if (graph[dest][i] != 0) {
                    Edge newEdge = {dest, i, graph[dest][i]};
                    pq.push(newEdge);
                }
            }
        }

        visited[src] = true;
    }

    cout << "Minimum Spanning Tree Edges:" << endl;

    // Print the MST edges
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    // Define the adjacency matrix for the graph
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode = 0;

    // Calculate and print the minimum spanning tree
    calculateMST(graph, startNode);

    return 0;
}

