#include <iostream>
using namespace std;

struct node {  int data;    node* next;     node* prev;  };

class DoubleLinkedList {
private:
	node* front, * rear;    int counter = 0;
public:
	DoubleLinkedList() { front = rear = NULL; }

	void addLast(int d) {
		node* temp = new node;
		if (temp == NULL) { cout << "Memory is full"; }
		temp->data = d;    temp->next = NULL;

		if (rear == NULL)    { rear = front = temp; }
		else                 { temp->prev = rear;      rear->next = temp;      rear = temp; }
		counter++;
	}
	void addFirst(int d) {
		node* temp = new node;
		if (temp == NULL) { cout << "Memoy is full"; }
		temp->data = d;    temp->prev = NULL;    temp->next = NULL;

		if (rear == NULL)   { rear = front = temp; }
		else                { temp->next = front;    front->prev = temp;    front = temp; }

		counter++;
	}
	void addIndex(int d, int index) {
		node* tempBefore = new node;     node* tempAfter = new node;      node* temp = new node;
		temp->prev = NULL;				  temp->next = NULL;				  temp->data = d;
	
		if (temp == NULL) {cout << "Memory is full";}
		tempBefore = tempAfter = front;

		if (index < counter && index>0){
			for (int i = 0; i < index - 1; i++) { tempAfter = tempBefore->next; }
			for (int i = 0; i < index - 1; i++){tempAfter = tempBefore->next;}
			tempAfter->prev = temp;    temp->next = tempAfter;
			tempBefore->next = temp;   temp->prev = tempBefore;
		}
		else if (index == 0) { addFirst(d); }
		else if (index == counter) { addLast(d); }
		else { cout << "Error; can't add"; }
	}
	void addSorted(int d) {
		node* temp = new node;  node* current = new node;
		temp->data = d;    temp->next = NULL;  temp->prev = NULL;

		if (front == NULL) { front = temp; }
		else if (front->data >= temp->data) { temp->next = front;     temp->next->prev = temp;     front = temp; }
		else {
			current = front;
			while (current->next != NULL && current->next->data < temp->data) { current = current->next; }

			temp->next = current->next;

			if (current->next != NULL) { temp->next->prev = temp;      current->next = temp;      temp->prev = current; }
		}
		counter++;
	}

	void deleteFirst() {
		if (front == NULL) { cout << "Error"; }
		node* temp = front;    front = front->next;    front->prev = NULL;     delete temp;  counter--;
	}
	void deleteLast() {
		if (rear == NULL) { cout << "Error"; }
		node* temp = rear;     rear = rear->prev;      rear->next = NULL;      delete temp;  counter--;
	}
	void deleteIndex(int index) {
		node* temp = front;

		if (index < counter && index>0) {
			for (int i = 0; i < index; i++) { temp = temp->next; }

			temp->next->prev = temp->prev;     temp->prev->next = temp->next;
			delete temp;   counter--;
		}
	}

	void search(int d) {
		node* temp = front;       int found = 0, i=0;
		if (temp != NULL) {
			while (temp!=NULL){
			i++;
			if (temp->data == d) { found++; break; }
			temp = temp->next;
		}
		if (found == 1) { cout << "Found at index " << i-1 << endl; }
		else { cout << "Not found\n"; }
	}
	else { cout << "List is empty\n"; }
	}

	bool isEmpty()      { return (front == NULL); }
	int getElementsNo() { return counter; }
	void printList()  {      node* temp = front;      while (temp!=NULL) { cout << temp->data << "\t";       temp = temp->next; }     }

};
int main(){

	DoubleLinkedList odd, even;

	for (int i = 0; i < 10; i++) {   if (i % 2 == 0)    even.addLast(i);    else     odd.addLast(i);   }

	cout << "\n*****BEFORE********Even & Odd in two differend Doubly lists****************************\n";
	cout << "Odd are\n";   odd.printList();     cout << endl;
	cout << "Even are\n";  even.printList();    cout << endl;

	cout << "\n*****After********Even & Odd in two differend Doubly lists****************************\n";
	even.addIndex(1, 2);    even.addSorted(5);      even.deleteFirst();
    odd.deleteFirst();     odd.deleteLast();
	cout << "Odd are\n";   odd.printList();     cout << endl;
	cout << "Even are\n";  even.printList();    cout << endl;

	cout << "\n**********************New Doubly LinkedList**************************\n";
	DoubleLinkedList z;
	z.addFirst(8);       z.addFirst(4);
	z.addLast(21);   z.addIndex(122, 2);     z.addLast(92);
	z.printList();

	cout << "\n**************************New Doubly LinkedList**************************\n";
	DoubleLinkedList k;
	k.addSorted(10);      k.addSorted(2);     k.addSorted(6);     k.addSorted(5);
	k.printList();


	cout << "\nIs number 2 found ?";        k.search(2);

	return 0;

}