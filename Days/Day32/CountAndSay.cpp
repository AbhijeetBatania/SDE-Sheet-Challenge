/*
=========================================================
Problem: Count and Say
Link: https://leetcode.com/problems/count-and-say/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Recursion
// Time Complexity : Exponential
// Space Complexity : O(n)
// ---------------------------------------------------------

class Solution {
public:
    string countAndSay(int n) {

        // Base case
        if( n == 1) return "1";

        // Generate previous sequence
        string say = countAndSay(n-1);

        string ans = "";

        // Count consecutive characters
        for(int i  = 0 ; i < say.size() ; i++){

            int count = 1;

            while(i<say.size()-1 && say[i] == say[i+1]){
                count++;
                i++;
            }

            ans+= to_string(count) + string(1, say[i]);
        }

        return ans;
    }
};


// ---------------------------------------------------------
// Approach 2 : Iterative
// Time Complexity : O(total generated characters)
// Space Complexity : O(1) (excluding output)
// ---------------------------------------------------------

class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";

        // Build sequence from 2 to n
        for (int i = 2; i <= n; i++) {

            string curr = "";

            for (int j = 0; j < ans.size(); j++) {

                int count = 1;

                while (j < ans.size() - 1 && ans[j] == ans[j + 1]) {
                    count++;
                    j++;
                }

                curr += to_string(count);
                curr += ans[j];
            }

            ans = curr;
        }

        return ans;
    }
};