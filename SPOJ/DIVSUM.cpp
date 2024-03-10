#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int num; cin >> num;
	for (size_t i = 0; i < num; i++) {
		int n; int sum = 0;
		cin >> n;
		for (size_t j = 1; j <= sqrt(n); j++) { //all integer divisor combinations will be exhausted after the sqrt of the number
			sum += (n%j == 0 ? j + (n/j != j ? n/j : 0) : 0); //only add the combo if it is a divisor (mod 0) and only add the second portion of the combo if the combo is not a square
		}
		cout << sum - n << endl;
	}
	return 0;
}