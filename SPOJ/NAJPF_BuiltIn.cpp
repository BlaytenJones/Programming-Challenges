#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int partition(int* collection, int first, int last) {
    int pivot = collection[first];
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
        }
        else {
            break;
        }
    }
    swap(collection[first], collection[right]);
    return right;
}

void quickSort(int* collection, int first, int last) {
    if (first < last) {
        int midpoint = partition(collection, first, last);
        quickSort(collection, first, midpoint - 1);
        quickSort(collection, midpoint + 1, last);
    }
}

bool divisible(int* collection, int K, int N, int midpoint) {
    int tempK = K;
    for (int i = N - 1; i >= 0; i--) {
        //if a number in the collection is divisible into X piles of M pieces of candy, subtract X from K
        tempK -= (collection[i] / midpoint);
        //if X > K, M pieces of candy can be distributed evenly among K students, therefore being divisible
        if (tempK <= 0) {
            return true;
        }
    }
    return false;
}

int main() {
    const int MAXSTACK = 50000;
    short unsigned numCases; cin >> numCases;
    for (size_t i = 0; i < numCases; i++) {
        int collection[MAXSTACK] = {};
        unsigned long N; unsigned long K;
        cin >> N >> K;
        for (size_t j = 0; j < N; j++) {
            cin >> collection[j];
        }
        //Sort ascending
        quickSort(collection, 0, N - 1);
        //Try to find the max number of candies via binary search
        int l = 1; int r = collection[N - 1] + 1; int answer = 0;
        while (l <= r) {
            int midpoint = (l + r) / 2;
            //if divisible, try to increase amount; otherwise, decrease
            if (divisible(collection, K, N, midpoint)) {
                answer = midpoint;
                l = midpoint + 1;
            } else {
                r = midpoint - 1;
            }
        }
        cout << answer << endl;
    }
    return 0;
}