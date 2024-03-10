#include <iostream>
using namespace std;

int main() {
	int num; cin >> num;
	for (size_t i = 0; i < num; i++) {
		int c, k, w;
		cin >> c >> k >> w;
		cout << ((c * w > k) ? "no" : "yes") << endl;
	}
	return 0;
}