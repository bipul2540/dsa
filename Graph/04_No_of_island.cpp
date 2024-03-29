#include<bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> matrix, vector<vector<int>>&vis) {
	vis[row][col] = 1;
	int n = matrix.size();
	int m = matrix[0].size();

	int delrow[]  = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};

	for (int i = 0; i < 4; i++) {
		int nrow = row + delrow[i];
		int ncol = col + delcol[i];

		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1 && !vis[nrow][ncol]) {
			dfs(nrow, ncol, matrix, vis);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m , 0));
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			int val;
			cin >> val;
			matrix[i][j] = val;
		}
	}

	int count = 0;

	vector<vector<int>> vis(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			if (!vis[i][j] && matrix[i][j]==1) {
				dfs(i, j, matrix, vis);
				count++;
			}
		}
	}

	cout << count;
}
