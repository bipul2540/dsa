#include<bits/stdc++.h>

using namespace std;

bool result = false;
void findSubsequence(int index, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds,int target,  int sum){
	if(index == arr.size()){
		if(sum==target){
			result = true;
		}


		return ;
	}

	findSubsequence(index+1, arr, ans, ds,target, sum+arr[index]);

	findSubsequence(index+1, arr, ans, ds, target, sum);
}

int main(){

	vector<int> arr= {3, 7, 5 ,3 ,2};

	vector<vector<int>> ans;

	vector<int> ds;
	int target = 5;


	findSubsequence(0, arr, ans, ds,target, 0);

	cout << result << endl;

	for(auto it: ans){
		if(it.size()==0) cout << "[]";
		for(auto i: it){
			cout << i << " ";
		}
		cout << endl;
	}
}