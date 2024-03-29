#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;

vector<int> findPrevSmaller(vector<int> heights) {
    vector<int> ans;
    int n = heights.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {

        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        
        if (!st.empty()) {
            ans.push_back(st.top()+1);
        } 
        if(st.empty()) {
            ans.push_back(0);
        }
        st.push((i));
    }

    return ans;
}

vector<int> findNextSmaller(vector<int> heights) {
    vector<int> ans;
    int n = heights.size();
    stack<int> st;
    for (int i = n-1; i >=0; i--) {

        while (!st.empty() &&  st.top()!=0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        
        if (!st.empty()) {
            ans.push_back(st.top()-1);
        } 
        if(st.empty()) {
            ans.push_back(i);
        }
        st.push((i));
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {
    vector<int> arr = {2,3};
    int n = arr.size();


    vector<int> prevS =  findPrevSmaller(arr);
    vector<int> nextS =  findNextSmaller(arr);

    for (auto it : prevS) {
        cout << it << " ";
    }
    cout << endl;

    for (auto it : nextS) {
        cout << it << " ";
    }
    cout << endl;
}