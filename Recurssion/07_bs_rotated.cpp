#include <iostream>
#include <vector>

using namespace std;


int search(vector<int> arr, int n, int target, int low, int high) {
	 if(low>high) return -1;

	int mid = (low + high) / 2;


	while (low <= high) {

		if (arr[mid] == target) return mid;

		if (arr[low] <= arr[mid]) {
			if (arr[low] <= target && target <= arr[mid]) return search(arr, n, target, low, mid-1);
			else return search(arr, n, target, mid+1, high);
		} else {
			if (arr[mid] <= target && target <= arr[high]) return search(arr, n, target, mid +1, high);
			else return search(arr ,n, target, low, mid-1);
		}

		mid = (low+ high)/2;

	}


	return -1;
}


int main() {

	vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
	int n = arr.size();
	int target = 7;

	int ans = search(arr, n, target, 0, n-1);
	cout << ans;
}