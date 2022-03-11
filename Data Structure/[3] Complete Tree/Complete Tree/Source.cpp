#include <iostream>
using namespace std;

class ArrayStack{
private: char* arr;      int top, size;
public:  ArrayStack(int ss) { top = 0; size = ss; arr = new char[size]; }     ArrayStack(void) { top = 0; size = 10; arr = new char[size]; }
	void push(char data) { arr[top++] = data; }
	char pop(void) { return arr[--top]; }
	bool isEmpty(void) { return (top == 0); }
	bool isFull(void) { return(top == size); }
};
class ArrayQueue{
private:  char* arr;     int front, rear, size, counter;
public:  ArrayQueue(int ss){ front=rear=counter=0; size=ss; arr=new char[size]; }  ArrayQueue(void){ front=rear=counter=0; size=10; arr=new char[size]; }
	void enqueue(char data){ arr[rear] = data;   rear = (rear + 1) % size; counter++; }
	char dequeue(void){ char temp;  temp = arr[front];  front = (front + 1) % size; counter--;   return temp; }
	bool isEmpty(void) { return(counter == 0); }
	bool isFull(void) { return(counter == size); }
};

struct treeNode{ char name, father; int order; };

void print_DFS(treeNode* ptr, int size){
	int counter; char* sons = new char[size]; ArrayStack s; char temp;

	for (int i = 0; i < size; i++){   if (ptr[i].father == '0') {s.push(ptr[i].name); break;}    }

	while (!s.isEmpty()){
		temp = s.pop(); cout <<"\t" << temp; counter = 0;
		for (int i = 0; i < size; i++) { if (ptr[i].father == temp) { sons[ptr[i].order] = ptr[i].name;   counter++; }}
		for (int i = counter; i >= 1; i--)     s.push(sons[i]);
	}
}
void print_BFS(treeNode* ptr, int size){
	int counter; char* sons = new char[size]; ArrayQueue q; char temp;

	for (int i = 0; i < size; i++){   if (ptr[i].father == '0') {q.enqueue(ptr[i].name); break;}   }

	while (!q.isEmpty()){
		temp = q.dequeue(); cout<<"\t" << temp; counter = 0;
		for (int i = 0; i < size; i++) { if (ptr[i].father == temp) { sons[ptr[i].order] = ptr[i].name; counter++; } }
		for (int i = 1; i <= counter; i++)    q.enqueue(sons[i]);
	}
}

int main(){
	treeNode treeArray[12] = { {'A','M',2},{'B','M',1},{'C','A',1},{'D','H',3},{'F','H',1},{'G','H',2},
							   {'H','M',3},{'K','B',2},{'M','0',0},{'P','K',2},{'X','K',1},{'Y','B',1} };

	cout << "DFS: "; print_DFS(treeArray, 12);
	cout << "\nBFS: ";print_BFS(treeArray, 12);

}