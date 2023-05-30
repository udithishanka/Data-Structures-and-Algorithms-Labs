#include <iostream>
#include <climits>

#define V 6 // Number of vertices

int minDistance(int distances[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int distances[V];
    bool visited[V];
    int path[V];  // Store the shortest path from source to each city

    // Initialize distances, visited array, and path
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
        path[i] = -1;  // Initialize path as -1 for each node
    }

    distances[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distances, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                path[v] = u;  // Update the shortest path to node v
            }
        }
    }

    // Print the shortest distances and paths from the source to each city
    for (int i = 0; i < V; i++) {
        if (i != source) {
            std::cout << "Distance of node " << i << " = " << distances[i] << "\n";
            std::cout << "Path = " << i;

            int parent = path[i];
            while (parent != source) {
                std::cout << " <- " << parent;
                parent = path[parent];
            }
            std::cout << " <- " << source << "\n";
        }
    }
    std::cout << "------------------------\n";
}


int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source;
    std::cout << "Enter the starting node: ";
    std::cin >> source;

    dijkstra(graph, source);

    return 0;
}
