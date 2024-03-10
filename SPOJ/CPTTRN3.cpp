#include <iostream>
using namespace std;

int main() {
	int num; cin >> num; //Gets the number of inputs
	for (size_t i = 0; i < num; i++) {
		int r, c;
		cin >> r >> c; //Gets the number of rows and columns
		string gridDesign = "*";
		for (size_t k = 0; k < c; k++) {
			gridDesign += "..*";
		}
		for (size_t j = 0; j < r; j++) {
			cout << "*" << string(3 * c, '*') << endl; //prints line
			cout << gridDesign << endl << gridDesign << endl; //prints grid design twice
		}
		cout << "*" << string(3 * c, '*') << endl; // prints last line
	}
	return 0;
}