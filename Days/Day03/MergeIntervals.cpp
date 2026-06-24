/*
=========================================================
Problem: Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/
=========================================================
*/

// ---------------------------
// Method 1 : Merge While Traversing
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int n = intervals.size();

        for (int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge all overlapping intervals.
            while (i < n - 1 && end >= intervals[i + 1][0]) {

                end = max(end, intervals[i + 1][1]);
                i++;
            }

            result.push_back({start, end});
        }

        return result;
    }
};


// ---------------------------
// Method 2 : Using Result Back (Optimal)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            // Check if current interval overlaps
            // with the last merged interval.
            if (result.back()[1] >= intervals[i][0]) {

                result.back()[1] =
                    max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};