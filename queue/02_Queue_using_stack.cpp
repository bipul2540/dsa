#include<iostream>
#include<stack>

using namespace std;


class Queue{
public: 
	stack<int> st1;
	stack<int> st2;
	int front;
	int rear ;
	int size;


	Queue(){
		
	}

	void push(int data){
		

		while(!st1.empty()){
			st2.push(st1.top());
			st1.pop();
		}

		st1.push(data);
		while(!st2.empty()){
			st1.push(st2.top());
			st2.pop();
		}
	}

	int top(){
		return st1.top();
	}

	void pop(){
		if(!st1.empty()){
			st1.pop();
		}
	}
};

int main(){

	Queue q;
	q.push(5);
	q.push(6);

	cout << q.top();
	q.pop();
	cout << q.top();

	string str = "bipulkumargupta";

	string temp = str.substr(1, 5);

	cout << temp;


}