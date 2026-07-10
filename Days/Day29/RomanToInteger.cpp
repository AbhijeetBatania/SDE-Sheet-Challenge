/*
=========================================================
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Using HashMap
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.length(); i++) {

            if (i + 1 < s.length() && romanMap[s[i + 1]] > romanMap[s[i]]) {
                result -= romanMap[s[i]];
            }
            else {
                result += romanMap[s[i]];
            }
        }

        return result;
    }
};


// ---------------------------------------------------------
// Approach 2 : Using Helper Function
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:

    int value(char c) {

        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;

        return 0;
    }

    int romanToInt(string s) {

        int result = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() && value(s[i]) < value(s[i + 1]))
                result -= value(s[i]);
            else
                result += value(s[i]);
        }

        return result;
    }
};