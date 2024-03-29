#include<iostream>

using namespace std;

class Queue {
public:
	int * arr;
	int front;
	int rear;
	int cnt;
	int size ;

	Queue(int size) {
		arr = new int[size];
		this->front = 0;
		this->rear = 0;
		this->cnt = 0;
		this->size = size;
	}

	void push(int data) {
		if (cnt < size) {
			arr[rear] = data;
			rear++;
			cnt++;
		} else {
			cout << "Queue is full";

		}
	}

	int top() {
		if (front != rear) {
			return arr[front];
		} else {
			return -1;
		}
	}

	void pop() {
		if (front != rear) {
			front++;
		} else {
			cout << "Queue is empty";
		}
	}

	bool isEmpty() {
		if (front == rear) return true;
		return false;
	}

};

int main() {
	Queue q(10);

	q.push(1);
	q.push(2);
	q.push(3);


	cout << q.top();
	q.pop();
	cout <<q.top();
}