#include<iostream>
using namespace std;


void printPatter(int n){
	if(n==0) return ;

	for(int i =0 ;i<n ;i++){
		cout << "* ";
	}

	cout << endl;

	printPatter(n-1);
}

void printPatter(int row, int col){
	if(row==0) return ;

	if(col<row){
		cout << "* ";
		printPatter(row, col+1);
	}else {
		cout << endl;
		printPatter(row-1, 0);
	}
}

int main(){
	int row = 4;
	int col = 0;

	printPatter(row, col);
}