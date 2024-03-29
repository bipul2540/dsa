#include<iostream>

using namespace std;


string removeChar(string str, string ans, int index){
	if(index==str.size()){
		return ans;
	}

	if(str[index] != 'a'){
		ans.push_back(str[index]);
	}

	return removeChar(str, ans, index+1);
}

// by using global variable

string removeChar2(string str, int index){
	string ans = "";
	if(index==str.size()){
		return ans;
	}

	if(str[index]!='a'){
		ans.push_back(str[index]);
	}

	string res = removeChar2(str, index+1);

	for(auto it: res) ans.push_back(it);

	return ans;
}

int main(){

	string str = "abbccd";

	string s= "";
	

	// string ans = removeChar(str, s, 0);
	string ans = removeChar2(str, 0);
	for(auto it: ans){
		cout << it;
	}
}