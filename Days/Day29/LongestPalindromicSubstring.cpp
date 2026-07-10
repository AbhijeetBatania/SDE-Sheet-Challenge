/*
=========================================================
Problem: Longest Palindromic Substring
Link: https://leetcode.com/problems/longest-palindromic-substring/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Brute Force (TLE)
// Time Complexity: O(N³)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {  // TLE
public:
    bool isPalindrome(string s){

        int left = 0;
        int right = s.size()-1;

        while(left < right){

            if(s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        string ans;

        for(int i = 0 ; i < s.size() ; i++){

            for(int j = i ; j < s.size() ; j++){

                if(j-i+1 > ans.size() && isPalindrome(s.substr(i,j-i+1))){
                    ans = s.substr(i,j-i+1);
                }
            }
        }

        return ans;
    }
};


// ---------------------------------------------------------
// Approach 2 : Expand Around Center
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        if (n <= 1)
            return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};