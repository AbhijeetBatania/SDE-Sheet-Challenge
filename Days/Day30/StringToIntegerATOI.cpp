/*
=========================================================
Problem: String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : String Traversal
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    int myAtoi(string s) {

        long long ans = 0;
        int sign = 1;
        int i = 0;

        // Skip leading whitespaces
        while(i < s.size() && s[i] == ' ')
            i++;

        // Check sign
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
            i++;

        // Convert numeric characters
        while(i < s.size() && isdigit(s[i])) {  // s[i]>='0' && s[i]<='9'

            ans = ans * 10 + (s[i] - '0');
            i++;

            // Overflow check
            if (sign * ans > INT_MAX)
                return INT_MAX;

            if (sign * ans < INT_MIN)
                return INT_MIN;
        }

        return (int)(sign * ans);
    }
};