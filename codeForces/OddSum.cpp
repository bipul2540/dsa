#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int odd = 0;
		int even = 0;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;

			if (temp % 2 == 0) even++;
			else odd++;
			arr.push_back(temp);
		}


		int sum = accumulate(arr.begin(), arr.end(), 0);

		if ((odd > 0 && even > 0) or (odd > 0 && even == 0)) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}
}