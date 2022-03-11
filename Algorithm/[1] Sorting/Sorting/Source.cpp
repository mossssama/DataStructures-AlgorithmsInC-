#include <iostream>
using namespace std;

void swap(int* a, int* b) { int temp = *a;    *a = *b;    *b = temp; }
void printArray(int arr[], int size) { cout << "Array is [ ";  for (int i = 0; i < size; i++) { cout << arr[i] << " "; } cout << "]" << endl; }

void selectionSort(int arr[], int size) {
	for (int j = 0; j < size - 1; j++) {                                                     //Searching for next least num
		int min = j;
		for (int i = j + 1; i < size; i++) { if (arr[i] < arr[min])     min = i; }          //Assuming first num id min & searching for the lowest num
		swap(&arr[min], &arr[j]);
	}
}

void bubbleSort(int arr[], int size) {
	for (int j = 0; j < size; j++) {                                                                           //Iterations for next biggest num
		for (int i = 0; i < size - j - 1; i++) { if (arr[i + 1] < arr[i])     swap(&arr[i], &arr[i + 1]); }
	}// iteration for find the biggest num
}

void insertionSort(int arr[], int size) {
	for (int j = 0; j < size; j++) {                                                                                    //Iterations for next biggest num
		for (int key = 1; key < size - j; key++) { if (arr[key] < arr[key - 1])   swap(&arr[key], &arr[key - 1]); }
	} // comparing choosed key with previous num to find the biggest
}

void merge(int* arr, int* arrL, int* arrR, int sizeL, int sizeR) {           // merging the subarray
	int l = 0, r = 0, i = 0;
	while (l < sizeL && r < sizeR) {
		if (arrL[l] < arrR[r])     arr[i++] = arrL[l++];
		else                       arr[i++] = arrR[r++];
	}
	while (l < sizeL)             arr[i++] = arrL[l++];
	while (r < sizeR)             arr[i++] = arrR[r++];
}
void mergeSort(int* arr, int size) {      // dividing the array into subarray until to be array with one element                                      
	int* arrL, * arrR;
	if (size < 2)   return;

	int mid = size / 2;         arrL = new int[mid];       arrR = new int[size - mid];
	for (int i = 0; i < mid; i++)     arrL[i] = arr[i];
	for (int i = mid; i < size; i++)  arrR[i - mid] = arr[i];

	mergeSort(arrL, mid);        mergeSort(arrR, size - mid);             merge(arr, arrL, arrR, mid, size - mid);
}

int partition(int arr[], int start, int end) {   // for finding the pivot's right index
	int pivot = end;      int index = start;

	for (int i = start; i < end; i++) { if (arr[i] < arr[pivot]) { swap(&arr[index], &arr[i]); index++; } }

	swap(&arr[index], &arr[pivot]);

	return (index);
}
void quickSort(int arr[], int start, int end) {    //recursive function for finding pivots right indeces
	if (start < end) { int piv = partition(arr, start, end);     quickSort(arr, start, piv - 1);  quickSort(arr, piv + 1, end); }
}

void heapifier(int arr[], int size, int pos) {    // for obtaining maxHeap
	int largest = pos;       int childL = (2 * pos) + 1;     int childR = (2 * pos) + 2;

	if (childL<size && arr[childL]>arr[largest])      largest = childL;
	if (childR<size && arr[childR]>arr[largest])      largest = childR;
	if (largest != pos) { swap(arr[pos], arr[largest]);  heapifier(arr, size, largest); }
}
void heapSort(int arr[], int size) {
	for (int i = (size / 2) - 1; i >= 0; i--)   heapifier(arr, size, i);                 //obtaining maxHeap
	for (int i = size - 1; i >= 0; i--) { swap(arr[0], arr[i]);     heapifier(arr, i, 0); }            // sorting ascendingly the maxHeap
}



int main() {
	int x;
	int arr[] = { 14,1,6,32,9,21,4 };           int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Choose the method you want to sort this array with:";         printArray(arr, size);
	cout << "\n1 - selectinoSort\n2 - bubbleSort\n3 - insertionSort\n4 - mergeSort\n5 - quickSort\n6 - heapSort\n";   	cin >> x;

	switch (x) {
	defualt: selectionSort(arr, size);
	case 1: selectionSort(arr, size);         case 2: bubbleSort(arr, size);          case 3: insertionSort(arr, size);
	case 4: mergeSort(arr, size);             case 5: quickSort(arr, 0, size - 1);    case 6: heapSort(arr, size);
	}    printArray(arr, size);
}