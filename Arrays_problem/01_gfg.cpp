#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


static bool cmp(string a, string b) {

//here this will automatically sort the value after conactenation
	return (a + b > b + a);
}

int main() {

	vector<string> arr = {"3", "30", "34", "5", "9"};
	int n = arr.size();

	sort(arr.begin(), arr.end(), cmp);

	for (auto it : arr) {
		cout << it <<endl;
	}
}