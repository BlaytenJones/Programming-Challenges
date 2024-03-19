#include <iostream>
using namespace std;

inline unsigned long gcd(unsigned long A, unsigned long B) {
    while (B != 0) {
        unsigned long temp = B;
        B = A % B;
        A = temp;
    }
    return A;
}

int main() {
    //A, B, & C are inputs, D is divisor
    unsigned long A = 0, B = 0, C = 0, D = 0;
    cin >> A >> B >> C;
    cout << gcd(A, gcd(B, C));
    return 0;
}
