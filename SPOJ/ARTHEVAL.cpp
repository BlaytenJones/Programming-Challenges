#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char val; Node* l = nullptr; Node* r = nullptr;
    Node(char val) : val(val) {}
};

Node* buildExprTree(const string& expression) {
    stack<Node*> POTstack;
    size_t size = expression.size();
    Node** parent = nullptr;
    bool seeking = false;
    string subExpr = "";
    for (size_t i = 0; i < size; i++) {
        char val = expression[i];
        if (val == ')') {
            seeking = false;
            if (!subExpr.empty()){
                if (parent != nullptr) {
                    *parent = buildExprTree(subExpr);
                } else {
                    POTstack.push(buildExprTree(subExpr));
                }
            }
            subExpr = "";
        } else if (val == '(' || seeking) {
            seeking = true;
            subExpr += (val != '(') ? val : '\0';
        } else if (isdigit(val)) {
            Node* digit = new Node(val);
            if (parent != nullptr) {
                *parent = digit;
            } else {
                POTstack.push(digit);
            }
        } else if (val == '+' || val == '-' || val == '*' || val == '/') {
            Node* op = new Node(val);
            op->l = POTstack.top();
            parent = &(op->r);
            POTstack.pop();
            POTstack.push(op);
        }
    }
    return POTstack.top();
}

int evalExprTree(Node* root) {
    if (isdigit(root->val)) {
        return root->val - '0';
    }
    int lVal = evalExprTree(root->l);
    int rVal = evalExprTree(root->r);
    switch (root->val) {
        case '+':
            return lVal + rVal;
        case '-':
            return lVal - rVal;
        case '*':
            return lVal * rVal;
        case '/':
            return lVal / rVal;
        default:
            return 0;
    }
}

int main() {
    string input;
    cin >> input;
    cout << evalExprTree(buildExprTree(input));
    return 0;
}
