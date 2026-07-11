/*
=========================================================
Problem: Find the Index of the First Occurrence in a String
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Brute Force
// Time Complexity: O(N × M)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i=0; i<haystack.size(); i++){

            int k=i;
            int j=0;

            while(haystack[k]==needle[j]){

                k++;
                j++;

                if(j+1>needle.size())
                    return i;

                if(k>haystack.size())
                    return -1;
            }
        }

        return -1;
    }
};


// ---------------------------------------------------------
// Approach 2 : Using KMP Algorithm
// Time Complexity: O(N + M)
// Space Complexity: O(M)
// ---------------------------------------------------------

class Solution {
public:

    void findLPS(string &needle, vector<int> &lps) {

        int len = 0;

        lps[0] = 0;

        int i = 1;

        while (i < needle.size()) {

            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {

        if (needle.empty())
            return 0;

        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m, 0);

        findLPS(needle, lps);

        int i = 0;
        int j = 0;

        while (i < n) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            }

            else if (i < n && haystack[i] != needle[j]) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};