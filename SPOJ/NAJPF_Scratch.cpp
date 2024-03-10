#include <iostream>
using namespace std;

const unsigned int MAXSTACK = 1000;

void preprocessing(string& pattern, unsigned int lps[]) {
    lps[0] = 0; unsigned int len = 0;
    size_t i = 1; size_t m = pattern.length();
    while(i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        }
        else {
            if (len) {
                len = lps[len - 1];
            }
            else {
                lps[i++] = 0;
            }
        }
    }
}

int main() {
    int positions[MAXSTACK];
    short unsigned numCases; cin >> numCases;
    for (size_t i = 0; i < numCases; i++) {
        string target; string pattern;
        cin >> target >> pattern;
        int pos = 0; int numAppearances = 0;
        unsigned int lps[MAXSTACK];
        preprocessing(pattern, lps);
        size_t targeti = 0, patterni = 0;
        size_t targetlen = target.length();
        size_t patternlen = pattern.length();
        while (targeti < targetlen) {
            if (pattern[patterni] == target[targeti]) {
                patterni++; targeti++;
            }
            if (patterni == patternlen) {
                positions[numAppearances++] = targeti - patterni + 1;
                patterni = lps[patterni - 1];
            }
            else if(targeti < targetlen && pattern[patterni] != target[targeti]) {
                if (patterni) {
                    patterni = lps[patterni - 1];
                }
                else {
                    targeti++;
                }
            }
        }
        if (!numAppearances) {
            cout << "Not Found";
        }
        else {
            cout << numAppearances << endl;
            for (size_t j = 0; j < numAppearances; j++) {
                cout << positions[j] << " ";
            }
        }
        cout << endl << endl;
    }
    return 0;
}