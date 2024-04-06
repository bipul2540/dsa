/*
X X X X
X O O X
X O X X
X O X X
X X O O

Since middle O's are not connected to boundry they they can be converte to x
*/

/*
X X X X
O O O X
X O X X
X O X X
X X O O

ince O's are connceted to bounry cannot be converted to x;
*/



#include<bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<char>> &matrix, vector<vector<int>>&vis) {
	vis[row][col] = 1;

	int delrow[] = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};

	for (int i = 0; i < 4; i++) {
		int nrow = delrow[i] + row;
		int ncol = delcol[i] + col;

		if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && matrix[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
			dfs(nrow, ncol, matrix, vis);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<char>> matrix(n, vector<char>(m, ' '));

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			char temp;
			cin >> temp;

			matrix[i][j] = temp;
		}
	}


	vector<vector<int>> vis(n, vector<int>(m, 0));

	vector<vector<char>> ans(n, vector<char>(m, ' '));


	for (int i = 0; i < n; i++) if (matrix[i][0] == 'O' && !vis[i][0]) dfs(i, 0, matrix, vis);

	for (int i = 0; i < n ; i++) if (matrix[i][m - 1] == 'O' && !vis[i][m-1]) dfs(i, m - 1, matrix, vis);

	for (int i = 0; i < m ; i++) if (matrix[0][i] == 'O' && !vis[0][i]) dfs(0, i, matrix, vis);

	for (int i = 0; i < m ; i++) if (matrix[n - 1][i] == 'O' && !vis[n-1][i]) dfs(n - 1, i, matrix, vis);;

	for (int i = 0; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m ; j++) {
			cout << vis[i][j] << " ";
		}
		cout << endl;
	}
}



