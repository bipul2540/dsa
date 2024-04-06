#include<bits/stdc++.h>

using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[]) {
	vis[src] = 1;

	queue<pair<int, int>>  q;
	q.push({src, -1});

	while (!q.empty()) {
		int node = q.front().first;
		int parent = q.front().second;

		q.pop();

		for (auto it : adj[node]) {
			if (!vis[it]) {
				vis[it] = 1;
				q.push({it, node});
			} else if (parent != it) {
				return true;
			}
		}
	}
	return false;
}

int main() {

	int V, E;
	cin >> V >> E;

	vector<int> adj[V + 1];

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int vis[V] = {0};

	bool ans = detectCycle(0, adj, vis);

	cout << ans;

}