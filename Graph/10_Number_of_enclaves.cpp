/*

You are given an n*m binary matrix grid where,
0 represent sea cell and 1 represent land cell

find the number of lan cells in gri for which we cannot walk off the boundry


0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0


*/



#include<bits/stdc++.h>




using namespace std;


vector<vector<int>> takeInput() {
	int n; int m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m, 0));

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			int temp;
			cin >> temp;

			matrix[i][j] = temp;
		}
	}

	return matrix;
}


void print(vector<vector<int>>&matrix) {
	for (int i = 0; i < matrix.size() ; i++) {
		for (int j = 0; j < matrix[0].size() ; j++) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}


void dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>>&vis) {
	vis[row][col] = 1;

	int delrow[] = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};

	for (int i = 0; i < 4; i++) {
		int nrow = delrow[i] + row;
		int ncol = delcol[i] + col;

		if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && matrix[nrow][ncol] == 1 && !vis[nrow][ncol]) {
			dfs(nrow, ncol, matrix, vis);
		}
	}
}



int main() {

	vector<vector<int>> matrix = takeInput();



	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> vis(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) if (matrix[i][0] == 1 && !vis[i][0]) dfs(i, 0, matrix, vis);

	for (int i = 0; i < n ; i++) if (matrix[i][m - 1] == 1 && !vis[i][m - 1]) dfs(i, m - 1, matrix, vis);

	for (int i = 0; i < m ; i++) if (matrix[0][i] == 1 && !vis[0][i]) dfs(0, i, matrix, vis);

	for (int i = 0; i < m ; i++) if (matrix[n - 1][i] == 1 && !vis[n - 1][i]) dfs(n - 1, i, matrix, vis);;

	print(matrix);

	cout << endl;
	print(vis);

	int cnt = 0;

	for(int i = 0; i<n ;i++){
		for(int j = 0; j<m ;j++){
			if(matrix[i][j]==1 && vis[i][j]==0) cnt++;
		}
	}
	cout << endl;

	cout << "Ans is: " << cnt;

}