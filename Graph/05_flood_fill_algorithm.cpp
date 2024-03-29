#include<bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>>&matrix, vector<vector<int>>&vis, int initialColor, int newColor, vector<vector<int>> &ans) {
	vis[row][col] = 1;
	ans[row][col] = newColor;

	int m = matrix.size();
	int n = matrix[0].size();

	int delrow[]  = { -1, 0, +1, 0};
	int delcol[] = {0, +1, 0, -1};


	for (int i = 0; i < 4; i++) {
		int nrow = row + delrow[i];
		int ncol = col + delcol[i];


		if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && matrix[nrow][ncol] == initialColor && ans[nrow][ncol]!=newColor) {
			
			dfs(nrow, ncol, matrix, vis, initialColor, newColor, ans);
			
		}
	}


}

int main() {


	int m, n;

	cin >> m >> n;

	vector<vector<int>> matrix(m, vector<int>(n, 0));

	for (int i = 0; i < m ; i++) {
		for (int j = 0 ; j < n ; j++) {
			int val;
			cin >> val;

			matrix[i][j] = val;
		}
	}

	int sr, sc;
	cin >> sr >> sc;

	int newColor;
	cin >> newColor;



	vector<vector<int>> vis(m, vector<int>(n, 0));
	int initalColor = matrix[sr][sc];
	matrix[sr][sc] = newColor;

	vector<vector<int>> ans = matrix;

	dfs(sr, sc, matrix, vis, initalColor, newColor, ans);




	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m ; j++) {
			cout << ans[i][j] <<  " ";
		}

		cout << endl;
	}
}