#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;


// ==================BUBBLE SORT ITERETIVE WAY================
/*
void bubbleSort(vector<int> &arr, int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

*/

// ==============BUBBLE SORT RECURSSION===============

void bubbleSort(vector<int> &arr , int n, int j){

	if(n==1) return ;

	if(j==n-1) {
		bubbleSort(arr, n-1, 0);
		return ;
	}

	if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);

	bubbleSort(arr, n, j+1);

}

int main(){

	vector<int> arr = {4, 0, 1, 2, 5};
	int n = arr.size();

	bubbleSort(arr, n,  0);

	for(int it: arr){
		cout << it << " ";
	}
}