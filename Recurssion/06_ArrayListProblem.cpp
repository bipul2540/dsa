#include<iostream>

#include<vector>

using namespace std;

vector<int> findTarget(vector<int> arr, int target, int index){

	vector<int> ans;
	if(index==arr.size()){
		return ans;
	}

	if(arr[index]==target){
		ans.push_back(index);
	}

	vector<int> res =  findTarget(arr, target, index+1);
	for(auto it: res){
		ans.push_back(it);
	}

	return ans;
}

int main(){

	vector<int> arr = {1, 2, 3, 4, 4, 4, 5, 6};
	int target = 4;
	
	vector<int> res = findTarget(arr, target, 0);

	for(auto it: res){
		cout << it << " ";
	}
}
