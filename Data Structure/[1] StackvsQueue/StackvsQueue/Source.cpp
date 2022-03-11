#include <iostream>
using namespace std;

struct node {  int data;  node* next; };

class LinkedStack {
private:   node* top;
public:
	LinkedStack() { top = NULL; }

	void push(int d) {
		node* temp = new node;
		if (temp == NULL) { cout << "Error, Memory is full\n"; }
		temp->data = d;     temp->next = top;   top = temp;
	}

	int pop() {
		if (top == NULL) { cout << "Error, Stack is empty\n"; }
			int d;   node* temp = top;
			d = top->data;  top = top->next;
			delete temp;  return d;
		}

	bool isEmpty() { return top == NULL; }

	int getTop() { return top->data; }

	int getElementsNo() {
		int counter = 0;    node* temp = top;
		while (temp != NULL) { temp = temp->next;  counter++;}

		return counter;
		}

	void printStack() {
		node* temp = top;
		while (temp != NULL) { cout << temp->data << "\t";   temp = temp->next; }
		}
};

class ArrayStack {
private: int top, * arr, maxSize;
public:
	ArrayStack()                         { top = 0;  maxSize = 10;    arr = new int[maxSize]; }
	ArrayStack(int size) { if (size > 0) { top = 0;  maxSize = size;  arr = new int[maxSize]; } }

	void push(int d) { arr[top] = d; top++; }

	int pop() { top--;  return arr[top]; }

	bool isEmpty() { return top <= 0; }

	bool isFull() { return top >= maxSize; }
	void doubleSize() {
		int* tempArr = new int [maxSize * 2];
		for (int i = 0; i < top; i++) { tempArr[i] = arr[i]; }

		maxSize*= 2;    delete arr;   arr = tempArr;
	}

	int getTop() { return arr[top - 1]; }

	int getElementsNo() { return top; }

	void printStack() {
		int temp = top; int i = 0;
		while (i < temp) {   cout << arr[temp- 1]<<"\t";    temp--; }
	}
};

class LinkedQueue {
private: node* front, * rear;
public:
	LinkedQueue() { front = rear = NULL; }

	void enqueue(int d) {
		node* temp = new node;
		if (temp == NULL) { cout << "Error,Memory is full\n"; }
		temp->data = d;    temp->next = NULL;

		if (rear != NULL) { rear->next = temp;    rear = temp; }
		else { rear = front = temp; }
	}
	int dequeue() {
		if (front == NULL) { cout << "Error,the Queue is empty"; }
		int d;  node* temp = front;
		d = front->data;     front = front->next;

		if (front == NULL) { rear = NULL; }

		delete temp;   return d;
	}

	bool isEmpty() { return front == NULL; }

	int getFront() { return front->data; }

	int getElementsNo() {
		int counter = 0;  node* temp = front;
		while (temp != NULL) { temp = temp->next;    counter++; }
		return counter;
	}

	void printQueue() {
		node* temp = front;
		while (temp != NULL) {  cout << temp->data << "\t";   temp = temp->next; }
	}
};

class ArrayQueue {
private: int front, rear, counter, maxSize, * arr;
public: 
	ArrayQueue()                         { front = rear = counter = 0;     maxSize = 10;     arr = new int[maxSize]; }
	ArrayQueue(int size) { if (size > 0) { front = rear = counter = 0;     maxSize = size;   arr = new int[maxSize]; } }
	
	void enqueue(int d) {
		if (isFull() == true) { doubleSize(); }

		arr[rear] = d;   counter++;     rear = (rear + 1) % maxSize;
	}

	int dequeue() {
		if (isEmpty() == true) { cout << "Error,Queue is Empty";  return -1; }

		int i = front;  counter--;    front = (front + 1) % maxSize;     return arr[i];
	}

	bool isEmpty() { return counter == 0; }

	bool isFull() { return counter >= maxSize; }
	void doubleSize() {
		int* tempArr = new int[maxSize * 2];
		for (int i = 0; i < counter; i++) { tempArr[i] = arr[(front + i) % maxSize]; }

		front = 0;   rear = counter;
		maxSize *= 2;  delete arr;    arr = tempArr;
	}
	
	int getFront() { return arr[front]; }

	int getElementsNo() { return counter; }

	void printQueue() {
		int temp = front;  int i = counter;
		while (i > 0) { cout << arr[temp] << "\t";    temp = (temp + 1) % maxSize;     i--; }
	}
};

int main() {
	cout << "\n*****************************LINKED Stack**************************\n";
	LinkedStack s1;    s1.push(3);   s1.push(6);    s1.push(9);      s1.pop();    
	s1.push(3);   s1.push(6);    s1.push(9);      s1.pop(); s1.push(3);   s1.push(6);    s1.push(9);      s1.pop();
	s1.push(3);   s1.push(6);    s1.push(9);      s1.pop(); s1.push(3);   s1.push(6);    s1.push(9);      s1.pop();
	
	s1.printStack();      cout << s1.getElementsNo();    cout << s1.getTop();

	cout << "\n*****************************ARRAY Stack**************************\n";
	ArrayStack s2;     s2.push(3);   s2.push(6);    s2.push(9);      s2.pop();
	s2.push(3);   s2.push(6);    s2.push(9);      s2.pop(); s2.push(3);   s2.push(6);    s2.push(9);      s2.pop();
	s2.push(3);   s2.push(6);    s2.push(9);      s2.pop(); s2.push(3);   s2.push(6);    s2.push(9);      s2.pop();
	 
	s2.printStack();      cout<<s2.getElementsNo();      cout << s2.getTop();

	cout << "\n*****************************LINKED Queue**************************\n";
	LinkedQueue q1;    q1.enqueue(3);   q1.enqueue(6);    q1.enqueue(9);      q1.dequeue();   
	q1.enqueue(3);   q1.enqueue(6);    q1.enqueue(9);      q1.dequeue(); q1.enqueue(3);   q1.enqueue(6);    q1.enqueue(9);      q1.dequeue();
	q1.enqueue(3);   q1.enqueue(6);    q1.enqueue(9);      q1.dequeue(); q1.enqueue(3);   q1.enqueue(6);    q1.enqueue(9);      q1.dequeue();
	
	q1.printQueue();      cout<<q1.getElementsNo();      cout << q1.getFront();

	cout << "\n*****************************ARRAY Queue**************************\n";
	ArrayQueue q2;     q2.enqueue(3);   q2.enqueue(6);    q2.enqueue(9);      q2.dequeue();   
	q2.enqueue(3);   q2.enqueue(6);    q2.enqueue(9);      q2.dequeue(); q2.enqueue(3);   q2.enqueue(6);    q2.enqueue(9);      q2.dequeue();
	q2.enqueue(3);   q2.enqueue(6);    q2.enqueue(9);      q2.dequeue(); q2.enqueue(3);   q2.enqueue(6);    q2.enqueue(9);      q2.dequeue();
	
	q2.printQueue();      cout<<q2.getElementsNo();     cout << q2.getFront();
}