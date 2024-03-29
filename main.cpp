
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {

	string s = "too hot";
	stringstream ss(s);

	vector<string> words;
	string str;

	while (ss >> str) {
		words.push_back(str);
	}

	for(auto it :words){
		cout << it << " ";
	}
}