#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> findNextSmaller(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<pair<int, int>> st;

	for (int i = n - 1 ; i >= 0 ; i--) {
		int cnt = 1;
		while (!st.empty() && st.top().first > arr[i]) {

			cnt += st.top().second;
			st.pop();
		}

		ans[i] = cnt;
		st.push(make_pair(arr[i], cnt));
	}

	return ans;
}


vector<int> findPrevSmaller(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<pair<int, int>> st;

	for (int i = 0 ; i < n ; i++) {
		int cnt = 1;
		while (!st.empty() && st.top().first > arr[i]) {

			cnt += st.top().second;
			st.pop();
		}

		ans[i] = cnt;
		st.push(make_pair(arr[i], cnt));
	}

	return ans;
}

vector<int> findNextGreater(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<pair<int, int>> st;

	for (int i = n - 1 ; i >= 0 ; i--) {
		int cnt = 1;
		while (!st.empty() && st.top().first < arr[i]) {

			cnt += st.top().second;
			st.pop();
		}

		ans[i] = cnt;
		st.push(make_pair(arr[i], cnt));
	}

	return ans;
}

vector<int> findPrevGreater(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<pair<int, int>> st;

	for (int i = 0 ; i < n ; i++) {
		int cnt = 1;
		while (!st.empty() && st.top().first < arr[i]) {

			cnt += st.top().second;
			st.pop();
		}

		ans[i] = cnt;
		st.push(make_pair(arr[i], cnt));
	}

	return ans;
}

int main() {
	vector<int> arr = {3, 1, 2, 4};
	int n = arr.size();

	vector<int> prevSmaller = findPrevSmaller(arr);
	for (auto it : prevSmaller) {
		cout << it << " ";
	}

	cout << endl;

	vector<int> nextSmaller = findNextSmaller(arr);

	for (auto it : nextSmaller) {
		cout << it << " ";
	}
	cout << endl;

	vector<int> nextgreater = findNextGreater(arr);
	for(auto it: nextgreater){
		cout << it <<" ";
	}
	cout << endl;

	vector<int> prevGreater = findPrevGreater(arr);
	for(auto it: prevGreater){
		cout << it << " ";
	}
}