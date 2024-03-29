#include<iostream>
using namespace std;

class Stack{
public: 
	int *arr;
	int top;
	int size;

	Stack(int size){
		arr = new int[size];
		this->top = -1;
		this->size = size;
	}

	void push(int data){
		top++;
		arr[top] = data;
	}

	void print(){
		for(int i = 0; i<=top ;i++){
			cout << arr[i] << " ";
		}
	}

	void pop(){
		if(top!=-1){
			top--;
		}else {
			cout <<"Stack underflow";
		}
	}

	void peek(){
		if(top!=-1) cout << arr[top];
		else cout <<"Stack is empty";
	}

	bool isEmpty(){
		if(top==-1) return true;

		return false;
	}



};


int main(){

	Stack st(5);

	st.push(10);
	// st.pop();
	st.peek();
	cout << st.isEmpty();
}