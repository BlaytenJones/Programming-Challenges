#include <iostream>
using namespace std;

void merge(string* collection, int first, int midpoint, int last) {
	int end1 = midpoint - first + 1; int end2 = last - midpoint;
    string *leftSubarray = new string[end1]; string *rightSubarray = new string[end2];
    for (int i = 0; i < end1; i++) {
        leftSubarray[i] = collection[first + i];
    }
    for (int j = 0; j < end2; j++) {
        rightSubarray[j] = collection[midpoint + 1 + j];
    }
    int i = 0; int j = 0; int k = first;
    while (i < end1 && j < end2) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            collection[k] = leftSubarray[i];
            i++;
        } else {
            collection[k] = rightSubarray[j];
            j++;
        }
        k++;
    }
    while (i < end1) {
        collection[k] = leftSubarray[i];
        i++; k++;
    }
    while (j < end2) {
        collection[k] = rightSubarray[j];
        j++; k++;
    }
}

void mergeSort(string* collection, int first, int last) {
    if (first < last) {
        int midpoint = (first + last) / 2;
        mergeSort(collection, first, midpoint);
        mergeSort(collection, midpoint + 1, last);
        merge(collection, first, midpoint, last);
    }
}

int main() {
    const int MAXSTACK = 99;
	int numCases; cin >> numCases;
	for (size_t i = 0; i < numCases; i++) {
		int numItems; cin >> numItems;
		string collection[MAXSTACK];
		//add new term inputs into vector
		for (size_t j = 0; j < numItems; j++) {
			string term = ""; cin >> term;
			collection[j] = term;
		}
		//sort vector
		mergeSort(collection, 0, numItems - 1);
		//print vector in order
		for (size_t k = 0; k < numItems; k++) {
			cout << collection[k] << endl;
		}
	}
	return 0;
}