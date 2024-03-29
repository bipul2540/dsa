#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n){
	for(int i = 0; i<n; i++){
		int mini = i;

		for(int j = i ;j<n; j++){
			if(arr[mini]>arr[j]) mini = j;
		}

		swap(arr[i], arr[mini]);
	}
}

void insertionSortRecurr(vector<int> &arr, int i, int j, int mini){
	if(i==arr.size()){
		return ;
	}


	mini = arr[i];
	if(j>arr.size()){
		swap(arr[i], arr[mini]);
		insertionSortRecurr(arr, i+1, i+1, mini);
		return ;
	}
	
	if(arr[j]<mini){
		mini = j;
	}

	insertionSortRecurr(arr, i, j+1, mini);
}

int main(){

	vector<int> arr = {5, 4, 3, 2, 1};
	int n = arr.size();
	int mini = arr[0];

	// insertionSort(arr, n);
	insertionSortRecurr(arr, 0, 0, mini);

	for(int it: arr){
		cout << it << " ";
	}
}