#include<bits/stdc++.h>

using namespace std;


void dfs(int node, vector<int> adj[], vector<int>&vis){
	vis[node] = 1;


	for(auto it: adj[node]){
		if(!vis[it]){
			dfs(it, adj, vis);
		}
	}
}

int findProvinces(int n, vector<int> adj[]){
	int res = 0;
	vector<int> vis(n, 0);
	for(int i = 0; i<n ;i++){
		if(!vis[i]){
			dfs(i, adj, vis);
			res++;
		}
	}

	return res;
}

int main(){

	int n;
	cin>> n;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for(int i =0; i<n; i++){
		for(int j = 0; j<n; j++){
			int val;
			cin >> val;
			matrix[i][j] = val;
		}
	}


	vector<int> adj[n];

	for(int i = 0; i<n ;i++){
		for(int j = 0; j<n ;j++){
			if(matrix[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}


	int ans = findProvinces(n ,adj);

	cout << ans;
}