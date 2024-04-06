#include<bits/stdc++.h>

using namespace std;


int main() {

	int t ;
	cin >> t;

	while (t--) {

		long long l, r;

		cin >> l >> r;

		long long a = 0;
		long long b = 0;

		if (l * 2 <= r) {
			a = l;
			b = l * 2;
		} else {
			a = -1;
			b = -1;
		}

		cout << a << " " << b << endl;
	}
}