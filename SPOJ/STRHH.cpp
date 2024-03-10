#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int num; cin >> num;
	for (size_t i = 0; i < num; i++) {
		string word, halfhalf;
		cin >> word;
		for (size_t j = 0; j < (word.length() + 1)/2; j++) { //over half of the length of the word
			if (j % 2 == 0) {
				halfhalf += word[j]; //take every other character and add it to the new string
			}
		}
		cout << halfhalf << endl;
	}
	return 0;
}