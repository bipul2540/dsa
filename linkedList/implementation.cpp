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


void printNode(Node* &head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insertAtHead(Node* &head, int data) {


	Node* temp = head;
	if (temp == nullptr) {
		Node* NodeToInsert = new Node(data);
		head = NodeToInsert;
	}
	Node* NodeToInsert = new Node(data);
	NodeToInsert->next = temp;
	head = NodeToInsert;
}

void insertAtTail(Node* &head, int data) {
	Node* temp = head;

	if (temp == nullptr) {
		Node* newNode = new Node(data);
		temp = newNode;
		head = temp;
	} else {
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		Node* newNode = new Node(data);
		temp->next = newNode;
	}


}

int main() {

	Node* head = nullptr;

	insertAtHead(head, 6);
	insertAtHead(head, 7);
	insertAtTail(head, 8);

	printNode(head);
	
}