#include<iostream>

using namespace std;


int printFibonn(int  n) {
	if (n <= 1) {
		return n;
	}
	

	int ans =  printFibonn(n - 1) + printFibonn(n - 2);
	return ans;

}

int main() {

	int ans = printFibonn(5);

	cout << ans;
}