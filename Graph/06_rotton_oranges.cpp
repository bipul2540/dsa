// since there can be multiple rotton oranges....Hence we have to use BFS.


#include<bits/stdc++.h>

using namespace std;
int main(){

	int m, n;

	cin >> m >> n;

	vector<vector<int>> matrix(m, vector<int>(n, 0));

	for(int i = 0 ; i<m ;i++){
		for(int j = 0; j<n ;j++){
			int val;
			cin >> val;
			matrix[i][j] = val;
		}
	}

	vector<vector<int>> vis(m, vector<int>(n, 0));

	queue<pair<pair<int ,int>, int>> q;
	for(int i = 0; i<m ;i++){
		for(int j = 0; j<n; j++){
			if(matrix[i][j]==2) {
				q.push({{i, j}, 0});
				vis[i][j] = 2;
			}
		}
	}
	int ans = 0;

	int delrow[]  = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};
	while(!q.empty()){
		auto it = q.front();
		q.pop();

		int sr = it.first.first;
		int sc = it.first.second;
		int time_taken = it.second;

		cout << "-> " << time_taken << endl;

		ans = max(ans, time_taken);


		for(int i = 0; i<4; i++){
			int nrow = sr + delrow[i];
			int ncol = sc + delcol[i];

			if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && matrix[nrow][ncol]==1 && !vis[nrow][ncol]){
				q.push({{nrow, ncol}, time_taken+1});
				vis[nrow][ncol] = 2;
			}
		}
	}

	for(int i = 0; i<m; i++){
		for(int j = 0; j<n ;j++){
			if(vis[i][j]!=2 && matrix[i][j]==1) ans = -1;
		}
	}

	cout << ans;

}