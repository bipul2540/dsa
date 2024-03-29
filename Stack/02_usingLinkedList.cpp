#include<iostream>

using namespace std;


class Node {

public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}

};

class Stack {
public:
	Node* top=nullptr;
	Node* start = nullptr;

	void push(int data){

		if(top==nullptr){
			Node* temp = new Node(data);
			top = temp;
			start = temp;
		}else {
			Node* newNode = new Node(data);
			top->next = newNode;
			top = newNode;
		}
	}

	void pop(){
		if(top==nullptr) {
			cout <<"Stack underflow";
		}else {
			Node* temp = start;

			while(temp->next->next!=nullptr){
				temp = temp->next;
			}

			temp->next = nullptr;
			top = temp;
			
		}
	}

	void print(){
		Node* temp = start;

		while(temp!=nullptr){
			cout << temp->data << " ";
			temp = temp->next;
		}

	}


	

	void peek(){
		if(top) cout << top->data;
		else cout <<"NULL";
	}

	void startd(){
		Node* temp = start;

		cout << temp->data;
	}


};


int main() {
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.pop();

	st.print();
	// st.startd();
	// st.peek();
}