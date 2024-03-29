#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool  binarySearch(vector<int> arr, int n) {
	long long maxi = accumulate(arr.begin(), arr.end(), 0);


	long long low = 0;
	long long high = maxi;

	while (low <= high) {
		long long mid = low + (high - low) / 2;

		if (mid * mid == maxi) return true;

		if (mid * mid > maxi) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return false;
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}


		bool ans = binarySearch(arr, n);
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}