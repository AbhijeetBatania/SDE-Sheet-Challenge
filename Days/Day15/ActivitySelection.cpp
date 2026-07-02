/*
=========================================================
Problem: Activity Selection
Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Greedy (Sort by Finish Time)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {

        vector<pair<int,int>> vec;

        // Store {finish time, start time}.
        for(int i = 0 ; i < start.size(); i++){
            vec.push_back({finish[i], start[i]});
        }

        // Sort activities by finish time.
        sort(vec.begin(), vec.end());

        int ans = 1;
        int lastFinish = vec[0].first;

        // Select the next activity whose start time
        // is greater than the last selected finish time.
        for(int i = 1 ; i < start.size(); i++){

            if(vec[i].second > lastFinish){
                ans++;
                lastFinish = vec[i].first;
            }
        }
        return ans;
    }
};