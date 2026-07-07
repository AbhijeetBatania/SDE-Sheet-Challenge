/*
=========================================================
Problem: Merge K Sorted Arrays
Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
=========================================================
*/

// ---------------------------
// Method 1 : Flatten + Sort
// Time Complexity: O(NK log(NK))
// Space Complexity: O(NK)
// ---------------------------

class Solution {
public:

    vector<int> mergeArrays(vector<vector<int>> &mat) {

        vector<int> arr;

        // Store every element in one array.
        for(auto &row : mat) {

            for(int num : row) {

                arr.push_back(num);
            }
        }

        // Sort the merged array.
        sort(arr.begin(), arr.end());

        return arr;
    }
};


// ---------------------------
// Method 2 : Min Heap
// Time Complexity: O(NK log K)
// Space Complexity: O(K)
// ---------------------------

class Solution {
public:

    vector<int> mergeArrays(vector<vector<int>> &mat) {

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<int> ans;

        int n = mat.size();

        // Push first element of every row.
        for(int i = 0; i < n; i++) {

            pq.push({mat[i][0], i, 0});
        }

        while(!pq.empty()) {

            auto [value, row, col] = pq.top();
            pq.pop();

            ans.push_back(value);

            // Push next element from same row.
            if(col + 1 < mat[row].size()) {

                pq.push({mat[row][col + 1], row, col + 1});
            }
        }

        return ans;
    }
};