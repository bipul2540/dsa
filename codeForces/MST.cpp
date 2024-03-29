#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int spanningTree(int n, vector<vector<int>>& graph) {
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node]) continue;

        vis[node] = true;
        sum += wt;

        for (int adjNode = 0; adjNode < n; adjNode++) {
            if (!vis[adjNode] && graph[node][adjNode] != 0) {
                pq.push({graph[node][adjNode], adjNode});
            }
        }
    }

    return sum;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
      // Handling self-loops
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }
    int ans = spanningTree(n, graph);

    cout << "Sum is: " << ans << endl;

    return 0;
}