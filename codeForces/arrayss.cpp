#include<bits/stdc++.h>
using namespace std;

int main() {


	int n, k;
	cin >> n >> k;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp ;
		cin >> temp;
		arr.push_back(temp);
	}

	int maxi = INT_MIN;

	while (k >= 0 ) {

		for (int i = 0 ; i < n - 1; i++) {
			if (arr[i] <= arr[i + 1]) {
				maxi = max(maxi, max(arr[i]+1, arr[i+1]));
				arr[i] = arr[i]+ 1;
			}
			
		}

		k-=n-1;

	}


	cout << maxi;
}