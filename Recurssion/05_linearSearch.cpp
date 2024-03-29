#include <iostream>
#include<vector>

using namespace std;

int linearSearch(vector<int> arr, int target, int index){
	if(index>arr.size()-1){
		return -1;
	}

	if(arr[index]==target){
		return index;
	}

	return linearSearch(arr, target, index+1);
}


int main(){

	vector<int> arr = {2,3, 7, 9, 80};

	int target = 2;

	int ans = linearSearch(arr, target, 0);

	cout << ans;
}
