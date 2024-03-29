#include<iostream>
using namespace std;


int sumOfDigit(int n ) {

	if (n%10 == n) {
		return n;
	}
	int digit = n % 10;
	return sumOfDigit(n / 10) * digit;
}

int main() {
	

}