#include <iostream>
#include <vector>
using namespace std;


void printSubSequence(int idx, vector<int> &ds, vector<int> arr,  int n, int k, int sum) {
	if (idx >= n) {
		if (sum == k) {
			for (auto it : ds) {
				cout << it << " ";
			}

			cout << endl;
		}

		return ;
	}

	ds.push_back(arr[idx]);
	sum += arr[idx];
	printSubSequence(idx + 1, ds, arr, n, k, sum);

	ds.pop_back();
	sum -= arr[idx];
	printSubSequence(idx + 1, ds, arr, n, k, sum);
}

int main() {
	std::vector<int> v = {1,1,2,2};
	int n = v.size();

	vector<int> ds;
	int k = 4;
	int sum = 0;
	printSubSequence(0, ds, v,  n, k, sum);
}
