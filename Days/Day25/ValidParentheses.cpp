/*
=========================================================
Problem: Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/
=========================================================
*/

// ---------------------------
// Method 1 : Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    bool isValid(string s) {

        // Stack stores opening brackets.
        stack<char> st;

        for (char c : s) {

            // Push opening brackets.
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {

                // Closing bracket without opening bracket.
                if(st.empty()) return false;

                else if (c == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (c == ']' && st.top() == '[') {
                    st.pop();
                }
                else if (c == '}' && st.top() == '{') {
                    st.pop();
                }

                // Invalid matching.
                else return false;
            }
        }

        // return true if stack is empty
        return st.empty();
    }
};