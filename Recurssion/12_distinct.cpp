#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

set<string> st;
void solve(string s, string ans, int index) {
	if (index == s.size()) {
		st.insert(ans);
		cout << ans << endl;
		return ;
	}


	ans.push_back(s[index]);
	solve(s, ans, index + 1);
	ans.pop_back();
	solve(s, ans, index + 1);
}

int main() {

	string s = "gfg";
	// sort(s.begin(), s.end());
	string ans = "";

	solve(s, ans, 0);

	for(auto it: st){
		cout << it << "--";
	}
}