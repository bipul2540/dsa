#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void reversefn(int start, int end, vector<int>&arr){
	if(start >= end) return ;

	swap(arr[start], arr[end]);
	reversefn(start+1, end-1, arr);
	
}


int main() {

	vector<int> arr = {1, 2, 3 ,4};
	int start = 0;
	int end = arr.size()-1;

	reversefn(start, end, arr);

	for(auto it: arr){
		cout << it << " ";
	}
}