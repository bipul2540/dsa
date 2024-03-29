#include<bits/stdc++.h>


using namespace std;


vector<int> bfsTraversal(vector<int> adj[], int n){

	int startNode = 6;

	queue<int> q;
	vector<int> vis(n+1, 0);
	q.push(startNode);

	vector<int> ans;
	vis[startNode] = 1;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		ans.push_back(node);

		for(auto it: adj[node]){
			if(!vis[it]){
				vis[it]=1;
				q.push(it);
			}
		}
	}

	return ans;
}

int main() {
	int n ;
	cin >> n;
	vector<int> adj[n + 1];

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		for (auto it : adj[i]) {
			cout << it  << " ";
		}

		cout << endl;
	}


	vector<int> val = bfsTraversal(adj, n);

	cout << "Ans arrays is :" << endl;
	for(auto it: val){
		cout << it << " ";
	}



}