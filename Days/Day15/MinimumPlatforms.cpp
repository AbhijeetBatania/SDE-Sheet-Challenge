/*
=========================================================
Problem: Minimum Platforms
Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Sorting + Two Pointers
// Time Complexity: O(N log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        int n = arr.size();

        // Sort arrival and departure times separately.
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int result = 0;
        int i = 0;
        int j = 0;
        int platNeeded = 0;

        while(i < n && j < n)
        {
            // New train arrives before previous departs.
            if(arr[i] <= dep[j])
            {
                platNeeded++;
                i++;

                result = max(result, platNeeded);
            }
            else
            {
                // One platform becomes free.
                platNeeded--;
                j++;
            }
        }
        return result;
    }
};