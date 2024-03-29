#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) : V(vertices) {
        graph.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;  // Undirected graph
    }

    vector<vector<int>> primMST() {
        vector<vector<int>> result;
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);

        key[0] = 0;  // Start with vertex 0

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        for (int i = 1; i < V; ++i) {
            result.push_back({parent[i], i, graph[i][parent[i]]});
        }

        return result;
    }

private:
    int minKey(const vector<int>& key, const vector<bool>& mstSet) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }
};

int maxMatching(const vector<vector<int>>& graph, vector<int>& parent, vector<bool>& visited, vector<int>& match) {
    int V = graph.size();
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || maxMatching(graph, parent, visited, match)) {
                match[v] = parent[v];
                return 1;
            }
        }
    }
    return 0;
}

int calculateCost(const vector<vector<int>>& spanningTree, int c) {
    int totalWeight = 0;
    int maxMatchingSize = 0;
    for (const auto& edge : spanningTree) {
        totalWeight += edge[2];
        if (edge[0] == edge[1])
            ++maxMatchingSize;
    }
    return totalWeight + maxMatchingSize * c;
}

int main() {
    int n, c;
    cin >> n >> c;  // Number of vertices and integer c
    Graph g(n);

    // Input graph edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                g.addEdge(i, j, weight);
            }
        }
    }

    auto spanningTree = g.primMST();

    // Calculate cost
    int cost = calculateCost(spanningTree, c);

    // Output cost
    cout << cost << endl;

    return 0;
}
