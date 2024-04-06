#include<bits/stdc++.h>

using namespace std;


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m, 0));

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			int temp;
			cin >> temp;
			matrix[i][j] = temp;
		}
	}


	vector<vector<int>> vis(n, vector<int>(m , 0));

	vector<vector<int>> dist(n, vector<int>(m, 0));

	queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (matrix[i][j] == 1) {
				q.push({{i, j}, 0});
				vis[i][j] = 1;
			}
		}
	}

	int delrow[] = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};

	while (!q.empty()) {
		auto it= q.front();
		q.pop();
		int row = it.first.first;
		int col = it.first.second;

		int step = it.second;
		dist[row][col] = step;


		for (int i = 0; i < 4; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];

			if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]) {
				vis[nrow][ncol] = 1;
				q.push({{nrow, ncol}, step + 1});
			}
		}
	}

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			cout << dist[i][j] << " ";
		}

		cout << endl;
	}
}