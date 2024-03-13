class Solution {
public:
    int longestValidParentheses(string s) {
        size_t len = s.length();
        int longest = 0;
        int openCount = 0;
        int closeCount = 0;

        for (size_t i = 0; i < len; ++i) {
            if (s[i] == '(') {
                openCount++;
            } else {
                if (++closeCount == openCount) {
                    longest = ((longest > closeCount) ? longest : closeCount);
                } else if (closeCount > openCount) {
                    openCount = closeCount = 0;
                }
            }
        }

        openCount = closeCount = 0;

        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == ')') {
                closeCount++;
            } else {
                if (++openCount == closeCount) {
                    longest = ((longest > openCount) ? longest : openCount);
                } else if (openCount > closeCount) {
                    openCount = closeCount = 0;
                }
            }
        }

        return 2 * longest;
    }
};
