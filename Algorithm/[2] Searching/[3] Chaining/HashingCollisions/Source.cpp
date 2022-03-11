#include<iostream>
using namespace std;

struct node { int data;  node* next; };
class LinkedQueue {
private:    node* front, * rear;
public:
	LinkedQueue() { front = rear = NULL; }
	void enqueue(int d) {
		node* temp = new node;
		temp->data = d;   temp->next = NULL;
		if (rear != NULL) { rear->next = temp;   rear = temp; }
		else                rear = front = temp;}
	void dequeue(int key){
		node* temp = front, * prev=NULL;
		if (temp != NULL && temp->data == key){ front = temp->next;    delete temp;           return; }
		while (temp != NULL && temp->data != key){prev = temp;    temp = temp->next;}
		if (temp == NULL)  return;
		prev->next = temp->next;      delete temp; }
	void printQueue() { node* temp = front;    while (temp != NULL) { cout << temp->data << " -->";    temp = temp->next; }   cout << "NULL" << endl; }
	bool isFound(int d) {
		node* temp = front;
		while (temp != NULL) {
			if (temp->data == d)   return 1;
			else                  temp = temp->next;
			}
		}
};

class ChainingHashing {
private:   LinkedQueue *hashArray;  int hashArraySize=10;
public:   

	ChainingHashing()              { hashArraySize = 10;          hashArray= new LinkedQueue[hashArraySize]; }
    ChainingHashing(int arraySize) { hashArraySize = arraySize;   hashArray=new LinkedQueue[hashArraySize]; }

	void modularArithmetic(int data) { 
		int index = data % hashArraySize;
		hashArray[index].enqueue(data); 
	}
	void truncation(int data) { 
		int index = data;       while (index > 10) { index /= 10; }   
		hashArray[index].enqueue(data);
	}
	void midSquare(int data) {
		int length = log10(data) + 1;     int index = (int)(data / pow(10, length / 2)) % 10;
		hashArray[index].enqueue(data);
	}
	void folding(int data) {
		int x = data, sum = 0, digit = 0;
		while (x > 0) { digit = x % 10;   sum += digit;    x = (int)x / 10; }
		while (sum >= hashArraySize) { sum = (int)(sum / 10); }
		hashArray[sum].enqueue(data);
	}

	void remove(int data) {   for (int i = 0; i < hashArraySize; i++)   hashArray[i].dequeue(data);  }

	int search(int data) { 
		LinkedQueue* temp = hashArray;   int i =0;
		while (i < hashArraySize) {
			if (temp->isFound(data)==1) { return i; }
			else                    { temp++; i++; }
		}
		return -1;
	}

	void printHashTable() {         for (int i = 0; i < hashArraySize; i++) { hashArray[i].printQueue();  cout << "\n"; }          }

};

int main(){ 

	ChainingHashing h1(7);
	cout << "****Chaining Hashing*****\n";
	h1.modularArithmetic(0);
	h1.modularArithmetic(4);
	h1.modularArithmetic(8);
	h1.modularArithmetic(12);
	h1.modularArithmetic(16);
	h1.modularArithmetic(20);
	h1.modularArithmetic(24);
	h1.modularArithmetic(30);
	h1.modularArithmetic(36);
	h1.modularArithmetic(42);
	h1.modularArithmetic(48);
	h1.modularArithmetic(55);
	h1.modularArithmetic(60);
	h1.modularArithmetic(77);
	h1.modularArithmetic(88);
	h1.printHashTable();
	cout << "\n****Chaining Hashing after dequeuing*****\n";
	h1.remove(42);
	h1.printHashTable();

	cout << "\nIs number 88 found ?\n";
	if (h1.search(88) != -1) cout << "It's found in List number " << h1.search(88) << "\n";
	else cout << "It's not found\n";

}


















