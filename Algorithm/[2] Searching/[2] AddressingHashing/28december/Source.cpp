#include <iostream>
using namespace std;

class addressingHashing {
private:
	float counter = 0.0;   int hashArraySize;   int* hashArray;

public:                                                                                        // cleaning the HashingTable while constructing
	addressingHashing()              { hashArraySize = 10;         hashArray = new int[hashArraySize];   for (int i = 0; i < hashArraySize; i++) { hashArray[i] = -1; } }
	addressingHashing(int arraysize) { hashArraySize = arraysize;  hashArray = new int[hashArraySize];   for (int i = 0; i < hashArraySize; i++) { hashArray[i] = -1; } }

	void modularArithmetic(int data) {//hFunc1 | INDEX is the modulus of the enterd data | 356 is stored in index 6
		int index = data % hashArraySize;                                                   counter++;       rehashingActivation();
		if (hashArray[index] == -1)     hashArray[index] = data;
		else    hashArray[linearProbing(index)] = data;
	}
	void truncation(int data) {//hFunc2 | INDEX is the first digit of the entered data | 356 is stored in index 3 and so on
		int index = data;                 while (index > 10) { index /= 10; }            
		if (hashArray[index] == -1)                                                    hashArray[index] = data;
		else                                                                hashArray[linearProbing(index)] = data;
	}
	void midSquare(int data) {//hFunc3 | INDEX is the middle digit of the entered data | 356 is stored in index 5
		int length = log10(data) + 1;     int index = (int)(data / pow(10, length / 2)) % 10;
		if (hashArray[index] == -1)  hashArray[index] = data;
		else                                                                hashArray[linearProbing(index)] = data;
	}
	void folding(int data) {//hFunc4 | INDEX is the sum of the digits of the entered data | 356 is stored in 14 
		int x = data, sum = 0, digit = 0;
		while (x > 0) { digit = x % 10;   sum += digit;    x = (int)x / 10; }//index here acts as sum
		while (sum >= hashArraySize) { sum = (int)(sum / 10); }/* if sum(index) = 123 and our size is 100, the number will be stored in 12 instead of 123 */
		if (hashArray[sum] == -1)  hashArray[sum] = data;
		else                                                                hashArray[linearProbing(sum)] = data;
	}

	int search(int data) {//sequential search
		for (int i = 0; i < hashArraySize; i++) { if (hashArray[i] == data)      return i; }
		return -1;
	}
	void remove(int data) {
		if (search(data) != -1) { hashArray[search(data)] = -1; }
		else cout << "This data isn't found to be deleted";
	}
	void printHashTable() { cout << "\nIndex:\tdata\n";   for (int i = 0; i < hashArraySize; i++) { cout << i << "\t" << hashArray[i] << "\n"; } }

	int linearProbing(int inx) { while (hashArray[inx] != -1) { inx++; }               return inx; }
	int quadraticProbing(int inx) { while (hashArray[inx] != -1) { inx *= inx; }             return inx; }

	void rehashingActivation() { if (counter / hashArraySize > 0.7)         rehashing(); }
	int toPrime(int num) {
		int factors = 0;    for (int i = 2; i < num; i++) { if ((num % i) == 0)  factors++; }
		if (factors == 0) { return num; }
		else { num++; toPrime(num); }
	}
	void rehashing() {
		int* newArray = new int[toPrime(2 * hashArraySize)];
		for (int i = 0; i < toPrime(2 * hashArraySize); i++) { newArray[i] = -1; }      // the new array's size must be a prime number

		for (int i = 0; i < hashArraySize; i++) { int newIndex = hashArray[i] % toPrime(2 * hashArraySize);   newArray[newIndex] = hashArray[i]; }
		delete hashArray;       hashArray = newArray;          newArray = NULL;       hashArraySize = toPrime(2 * hashArraySize);
	}

};



int main() {
	addressingHashing h1(10);
	
		h1.modularArithmetic(0);     h1.printHashTable();    //0
		h1.modularArithmetic(1);     h1.printHashTable();    //1
		h1.modularArithmetic(2);     h1.printHashTable();    //2
		h1.modularArithmetic(3);     h1.printHashTable();    //3
		h1.modularArithmetic(4);     h1.printHashTable();    //4
		h1.modularArithmetic(5);     h1.printHashTable();    //5
		h1.modularArithmetic(6);     h1.printHashTable();    //6
		h1.modularArithmetic(7);     h1.printHashTable();    //7
		h1.modularArithmetic(8);     h1.printHashTable();    //8
		h1.modularArithmetic(9);     h1.printHashTable();    //9
		h1.modularArithmetic(10);    h1.printHashTable();    //10
		h1.modularArithmetic(11);    h1.printHashTable();    //11
		h1.modularArithmetic(12);    h1.printHashTable();    //12
		h1.modularArithmetic(13);    h1.printHashTable();    //13
		h1.modularArithmetic(14);    h1.printHashTable();    //14
		h1.modularArithmetic(15);    h1.printHashTable();    //15
		h1.modularArithmetic(16);    h1.printHashTable();    //16
		h1.modularArithmetic(17);    h1.printHashTable();    //17
}