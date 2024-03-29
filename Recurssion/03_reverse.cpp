#include <iostream>
using namespace std;

int reverse(int n, int reversedNum=0) {

	if (n == 0) {
		return reversedNum;
	}

	int digit = n % 10;
	reversedNum = reversedNum * 10  + digit;

	return reverse(n/10, reversedNum);
}

int main() {

	int n = 132;

	int ans = reverse(n);

	cout << ans;
}