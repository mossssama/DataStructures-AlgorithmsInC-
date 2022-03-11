#include <iostream>
using namespace std;

void swap(int* a, int* b) { int temp = *a;    *a = *b;    *b = temp; }
void printArray(int arr[], int size) { cout << "Array is [ ";  for (int i = 0; i < size; i++) { cout << arr[i] << " "; } cout << "]" << endl; }
void bubbleSort(int arr[], int size) { for (int j = 0; j < size; j++) { for (int i = 0; i < size - j - 1; i++) { if (arr[i + 1] < arr[i]) swap(&arr[i], &arr[i + 1]); } } }

int sequentialSearch(int arr[], int key, int size) {
	for (int index = 0; index < size; index++) {
		if (arr[index] == key) { return index; }                  // return number's index if the number is found
	}
	return -1;                                                        // return -1 if the number isn't found
}

int binarySearch(int arr[], int key, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (key == arr[mid])       return mid;                        // return the number's index if the number is found
		else if (key > arr[mid])   start = mid + 1;
		else if (key < arr[mid])   end = mid - 1;
	}
	return -1;                                                        // return -1 if the number isn't found
}

struct indexNode { int slot;        int val; };
int indexedSearch(int arr[], int key, int size, int indexSize) {
	indexNode* inx = new indexNode[indexSize];
	int s = size / indexSize;

	for (int i = 0; i < indexSize; i++) {             // implementing the struct (indexArray)
		inx[i].slot = (i * s);
		inx[i].val = arr[i * s];
	}

	for (int i = indexSize - 1; i >= 0; i--) {           // index searching
		if (key == inx[i].val)      return (i * s);
		else if (key > inx[i].val)
			for (int j = 0; j < s - 1; j++) { if (key == arr[++(inx[i].slot)])   return (inx[i].slot); }
	}
	return -1;
}


int main() {
	int arr[8] = { 2,4,8,16,32,64,128,256 };      int size = sizeof(arr) / sizeof(arr[0]);

	cout << "\n********** SequentialSearch **********\n";

	int result = sequentialSearch(arr, 63, size);
	if (result == -1)    cout << "The number isn't found\n";              else  cout << "The number is found and it's index is " << result << endl;
	int result2 = sequentialSearch(arr, 128, size);
	if (result2 == -1)    cout << "The number isn't found\n";             else  cout << "The number is found and it's index is " << result2 << endl;

	cout << "\n********** BinarySearch **********\n";

	int result3 = binarySearch(arr, 63, 0, size - 1);
	if (result3 == -1)    cout << "The number isn't found\n";              else  cout << "The number is found and it's index is " << result3 << endl;
	int result4 = binarySearch(arr, 128, 0, size - 1);
	if (result4 == -1)    cout << "The number isn't found\n";              else  cout << "The number is found and it's index is " << result4 << endl;

	cout << "\n********** IndexedSearch **********\n";

	int result5 = indexedSearch(arr, 63, 8, 4);
	if (result5 == -1)    cout << "The number isn't found\n";              else  cout << "The number is found and it's index is " << result5 << endl;
	int result6 = indexedSearch(arr, 128, 8, 4);
	if (result6 == -1)    cout << "The number isn't found\n";              else  cout << "The number is found and it's index is " << result6 << endl;


}