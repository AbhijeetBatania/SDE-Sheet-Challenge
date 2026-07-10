/*
=========================================================
Problem: Repeated String Match
Link: https://leetcode.com/problems/repeated-string-match/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Manual Matching
// Time Complexity: O((N+M) × M)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int s1 = a.size();
        int s2 = b.size();

        string temp;

        // Minimum repetitions required
        int rep = (s2 + s1 - 1) / s1;

        for (int i = 0; i < rep; i++)
            temp += a;

        char ch = b[0];

        // Check in current repeated string
        for (int j = 0; j < temp.size(); j++) {

            if (temp[j] == ch) {

                if (temp.substr(j, s2) == b)
                    return rep;
            }
        }

        // One extra repetition may be needed
        temp += a;

        for (int j = 0; j < temp.size(); j++) {

            if (temp[j] == ch) {

                if (temp.substr(j, s2) == b)
                    return rep + 1;
            }
        }

        return -1;
    }
};


// ---------------------------------------------------------
// Approach 2 : Using find()
// Time Complexity: O((N+M) × M)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string s = a;
        int cnt = 1;

        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (s.find(b) != -1)
            return cnt;

        s += a;

        if (s.find(b) != -1)
            return cnt + 1;

        return -1;
    }
};