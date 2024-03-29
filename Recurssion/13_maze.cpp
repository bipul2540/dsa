#include<iostream>
#include<string>
#include<vector>
using namespace std;

// int countPath(int row, int col){
// 	if(row==1 || col==1) return 1;

// 	int right = countPath(row, col-1);
// 	int down  = countPath(row-1, col);

// 	return right + down;
// }

// void printPath(string p, int row, int col){
// 	if(row==1&&col==1) {
// 		cout << p << endl;
// 		return ;
// 	}

// 	if(row>1) printPath(p+"D", row-1, col);
// 	if(col>1) printPath(p+"R", row, col-1);
// }


vector<string> printPathReturn(string p, int row, int col){
	if(row==1 && col==1){
		vector<string> ans;
		ans.push_back(p);
		return ans;
	}

	vector<string> list;
	if(row>1){
		vector<string> down = printPathReturn(p+"D", row-1, col);
		list.insert(list.end(), down.begin(), down.end());
	}

	if(col>1) {
		vector<string> right = printPathReturn(p+"R", row, col-1);
		list.insert(list.end(), right.begin(), right.end());
	}
	return list;
}

int main(){

	// int ans = countPath(3, 3);
	// printPath("", 3, 3);

	vector<string> ans = printPathReturn("", 2, 2);

	
	cout << ans.size();

}