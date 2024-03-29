
#include <iostream>
#include<vector>
using namespace std;

int fiboncciNumber(int n){
	if(n<=1) return n;
	return fiboncciNumber(n-1)  + fiboncciNumber(n-2);	
}

int main(){
	
	int n ;
	cin>> n;
	int ans = fiboncciNumber(n);
	cout << ans;
}