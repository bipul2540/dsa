#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of (vertex, weight)

// Dijkstra's algorithm using priority queue
vector<int> dijkstra_priority_queue(vector<vector<pii>>& adj, int V, int S) {
    vector<int> dist(V, INT_MAX); // Initialize distances from source to all vertices as infinite
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to store vertices with their respective distances from the source
    
    dist[S] = 0; // Set distance of source vertex to itself as 0
    pq.push({0, S});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Iterate through all adjacent vertices of the extracted vertex
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            
            // If the distance to v through u is less than the currently known distance to v,
            // update the distance and add v to the priority queue
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// Dijkstra's algorithm using simple queue
vector<int> dijkstra_simple_queue(vector<vector<pii>>& adj, int V, int S) {
    vector<int> dist(V, INT_MAX); // Initialize distances from source to all vertices as infinite
    queue<int> q; // Queue to store vertices
    
    dist[S] = 0; // Set distance of source vertex to itself as 0
    q.push(S);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Iterate through all adjacent vertices of the extracted vertex
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            
            // If the distance to v through u is less than the currently known distance to v,
            // update the distance and add v to the queue
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
    
    return dist;
}

int main() {
    // Test Case 1
    int V1 = 3; // Number of vertices
    vector<vector<pii>> adj1 = {{{1, 1}, {2, 2}}, // Adjacency list representation of the graph
                                 {{0, 1}, {2, 3}},
                                 {{0, 2}, {1, 3}}};
    int S1 = 0; // Source vertex
    
    // Calculate distances using priority queue and print the result
    vector<int> dist1_priority = dijkstra_priority_queue(adj1, V1, S1);
    cout << "Test Case 1 - Dijkstra using Priority Queue:" << endl;
    for (int i = 0; i < V1; ++i) {
        cout << "Vertex " << i << ": " << dist1_priority[i] << endl;
    }
    
    // Calculate distances using simple queue and print the result
    vector<int> dist1_simple = dijkstra_simple_queue(adj1, V1, S1);
    cout << "\nTest Case 1 - Dijkstra using Simple Queue:" << endl;
    for (int i = 0; i < V1; ++i) {
        cout << "Vertex " << i << ": " << dist1_simple[i] << endl;
    }
    
    // Test Case 2
    int V2 = 4; // Number of vertices
    vector<vector<pii>> adj2 = {{{1, 4}, {2, 8}, {3, 7}}, // Adjacency list representation of the graph
                                 {{0, 4}, {2, 2}},
                                 {{0, 8}, {1, 2}, {3, 6}},
                                 {{0, 7}, {2, 6}}};
    int S2 = 0; // Source vertex
    
    // Calculate distances using priority queue and print the result
    vector<int> dist2_priority = dijkstra_priority_queue(adj2, V2, S2);
    cout << "\nTest Case 2 - Dijkstra using Priority Queue:" << endl;
    for (int i = 0; i < V2; ++i) {
        cout << "Vertex " << i << ": " << dist2_priority[i] << endl;
    }
    
    // Calculate distances using simple queue and print the result
    vector<int> dist2_simple = dijkstra_simple_queue(adj2, V2, S2);
    cout << "\nTest Case 2 - Dijkstra using Simple Queue:" << endl;
    for (int i = 0; i < V2; ++i) {
        cout << "Vertex " << i << ": " << dist2_simple[i] << endl;
    }
    
    return 0;
}
