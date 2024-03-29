#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>&vis){

	vis[node] = 1;
	ans.push_back(node);

	for(auto it: adj[node]){
		if(!vis[it]){
			dfs(it, adj, ans, vis);
		}
	}
}

int main(){

	int n ;
	cin >> n;

	vector<int> adj[n+1];

	for(int i = 0; i<n ;i++){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	for(int i = 1; i<=n ;i++){
		for(auto it: adj[i]){
			cout << it << " ";
		}

		cout << endl;
	}


	vector<int> ans;
	vector<int> vis(n+1, 0);
	int startNode = 1;


	dfs(startNode, adj, ans, vis);

	cout << "answer Arrays is: " << endl;

	for(auto it: ans){
		cout << it << " ";
	}
}