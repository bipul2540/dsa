#include<bits/stdc++.h>

using namespace std;

int main() {

	vector<int> arr = {3, 5 , 2, 1 , 4};
	int n  = arr.size();
	int i  = 0;

	while (i<n) {
		int correctIdx = arr[i]-1;
		if(arr[i] != arr[correctIdx]){
			swap(arr[i], arr[correctIdx]);
		}else {
			i++;
		}
	}

	for (auto it : arr) {
		cout << it << " ";
	}

}