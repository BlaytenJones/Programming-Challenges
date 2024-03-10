#include <iostream>
#include <algorithm>
using namespace std;

int partition(string* collection, int first, int last) {
    string pivot = collection[first];
    unsigned int left = first + 1; unsigned int right = last;
    while (true) {
        while (left <= last && collection[left] <= pivot) {
            left++;
        }
        while (right >= first && collection[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(collection[left], collection[right]);
        } else {
            break;
        }
    }
    swap(collection[first], collection[right]);
    return right;
}

void quickSort(string* collection, int first, int last) {
    if (first < last) {
        int midpoint = partition(collection, first, last);
        quickSort(collection, first, midpoint - 1);
        quickSort(collection, midpoint + 1, last);
    }
}

int main() {
    const int MAXSTACK = 99;
    int numCases; cin >> numCases;
    for (size_t i = 0; i < numCases; i++) {
        int numItems; cin >> numItems;
        string collection[MAXSTACK];
        //add new term inputs into matrix
        for (size_t j = 0; j < numItems; j++) {
            cin >> collection[j];
        }
        //sort matrix
        quickSort(collection, 0, numItems - 1);
        //print matrix in order
        for (size_t k = 0; k < numItems; k++) {
            cout << collection[k] << endl;
        }
    }
    return 0;
}