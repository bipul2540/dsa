#include<iostream>
#include<stack>
using namespace std;


void InsertAtSortedPosition(stack<int>& st, int num){
	if(st.empty() || st.top() < num){
		st.push(num);
		return ;
	}

	int val = st.top();
	st.pop();
	InsertAtSortedPosition(st, num);
	st.push(val);
}

void sortStack(stack<int>& st){
	if(st.empty()){
		return ;
	}

	int num = st.top();
	st.pop();
	sortStack(st);

	InsertAtSortedPosition(st, num);
}


int main(){
	
	stack<int> st;

	st.push(2);
	st.push(10);
	st.push(9);
	st.push(5);
	st.push(7);

	sortStack(st);

	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}