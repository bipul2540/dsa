#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> arr, int target,  int s, int e) {

	if (s > e) return -1;

	int m = s + (e - s) / 2;
	cout << "mid: "<< m  << endl;

	if (arr[m] == target) return m;


	if (arr[m] > target) {
		return search(arr,target,  s, m - 1);
	}
	return search(arr,target,  m + 1, e);

}

int main() {
	vector<int> arr;
	int n;
	cin >> n;
	cout << endl;

	for (int i = 0; i < n ; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int target;
	cin >> target;

	int index = search(arr, target,  0, arr.size() - 1);

	cout << "index is : " << index;

}