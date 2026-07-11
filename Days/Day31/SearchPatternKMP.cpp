/*
=========================================================
Problem: Search Pattern (KMP Algorithm)
Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : KMP (Knuth-Morris-Pratt)
// Time Complexity: O(N + M)
// Space Complexity: O(M)
// ---------------------------------------------------------

class Solution {
  public:

    // Build Longest Prefix Suffix (LPS) array
    void findLPS(vector<int> &LPS, string &pat){

        int len = 0;

        LPS[0] = 0;

        int i = 0;

        while(i < pat.size()){

            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{

                if(len != 0){
                    len = LPS[i-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string &pat, string &txt) {

        // code here

        int m = pat.size();
        int n = txt.size();

        int i = 0, j = 0;

        vector<int> LPS(m , 0);

        findLPS(LPS , pat);

        vector<int> ans;

        // KMP Pattern Matching
        while(i < n){

            if(txt[i] == pat[j]){
                i++;
                j++;
            }

            if(j == m){
                ans.push_back(i-j);
                j = LPS[j-1];
            }
            else if(i < n && txt[i] != pat[i]){

                if(j != 0){
                    j = LPS[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return ans;
    }
};