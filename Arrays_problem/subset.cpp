#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> subs = {{}};
	for (int num : nums) {
		int n = subs.size();
		for (int i = 0; i < n; i++) {
			subs.push_back(subs[i]);
			subs.back().push_back(num);
		}
	}
	return subs;
}

int main() {

	vector<int> arr = {2,5,2,1,2};

	vector<vector<int>> ans = subsets(arr);

	for (auto it : ans) {
		for (int num : it) {
			cout << num <<     " ";
		}
		cout << endl;
	}
}