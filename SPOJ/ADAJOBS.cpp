//CURRENTLY DOES NOT MEET TIMING REQUIREMENTS
#include <iostream>
#include <string>
using namespace std;

struct Node {
    bool valid = false;
    Node* transitions[26] = { nullptr };
    Node* failure = nullptr;
};

int main() {
    long unsigned numCases; cin >> numCases; cin.ignore();
    Node* trieHead = new Node;
    trieHead->failure = trieHead;
    for (size_t i = 0; i < numCases; i++) {
        short queryType; string input;
        cin.clear();
        cin >> queryType >> input;
        bool found;
        Node* currNode = trieHead;
        size_t m = input.length();
        if (queryType) {
            //FIND IN TRIE
            found = false;
            size_t j = 0;
            Node* transNode = nullptr;
            while ((j < m) && (!found)) {
                transNode = currNode->transitions[input[j] - 'a'];
                if (transNode) {
                    currNode = transNode;
                    found = currNode->valid;
                    j++;
                } else {
                    Node* failNode = currNode->failure;
                    j += (currNode == failNode) ? 1 : (currNode = failNode, 0);
                }
            }
            cout << (found ? "YES\n" : "NO\n");
        }
        else {
            //ADD TO TRIE
            //DO THE FIRST LETTER
            int letter = input[0] - 'a';
            if (!currNode->transitions[letter]) {
                currNode->transitions[letter] = new Node;
                currNode->failure = trieHead;
            }
            currNode = currNode->transitions[letter];
            //DO THE REST OF THE LETTERS
            for (size_t i = 1; i < m; i++) {
                letter = input[i] - 'a';
                if (!currNode->transitions[letter]) {
                    currNode->failure = trieHead;
                    currNode->transitions[letter] = new Node;
                    size_t j = i;
                    while (j < m) {
                        int currFailLetter = input[j++] - 'a';
                        if (trieHead->transitions[currFailLetter]) {
                            currNode->failure = trieHead->transitions[currFailLetter];
                            while (j <= i && (currNode->failure->transitions[input[j] - 'a'])) {
                                currNode->failure = currNode->failure->transitions[input[j++] - 'a'];
                            }
                            goto failureFound;
                        }
                    }
                }
            failureFound:
                currNode = currNode->transitions[letter];
            }
            Node* firstNodeLastLetter = trieHead->transitions[input[m - 1] - 'a'];
            currNode->failure = !firstNodeLastLetter ? trieHead : firstNodeLastLetter;
            currNode->valid = true;
        }
    }
    return 0;
}