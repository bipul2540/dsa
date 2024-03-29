#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<string>  findSubsets(string str, string ds, vector<string> &ans, int index) {
	if (index == str.size() ) {
		vector<string> newArr ;

		newArr.push_back(ds);
		return newArr;
	}


	ds.push_back(str[index]);
	vector<string> left = findSubsets(str, ds, ans, index + 1);


	ds.pop_back();
	vector<string> right = findSubsets(str, ds, ans, index + 1);

	left.insert(left.end(), right.begin(), right.end());

	return left;


}

int main() {

	string str = "abc";
	string s = "";

	vector<string> ans;

	vector<string> res = findSubsets(str, s,  ans, 0);

	for (auto str : res) {
		std::cout << str  << "--" << std::endl;
	}

}