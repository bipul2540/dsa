#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void findSubarrays(vector<int> arr, vector<int> &ans) {
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n ; j++) {
			int mini = arr[i];
			for (int k = i; k <= j ; k++) {
				mini = min(mini, arr[k]);
			}
			
				ans.push_back(mini);
		}
	}
}

int main() {

	vector<int> arr = {3,1,2,4};

	vector<int> ans;
	findSubarrays(arr, ans);

	for (auto it : ans) {
		cout << it <<" ";
	}
	int res = accumulate(ans.begin(), ans.end(), 0);
	cout << res;


}