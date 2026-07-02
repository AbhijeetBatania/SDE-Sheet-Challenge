/*
=========================================================
Problem: Job Sequencing Problem
Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Greedy + Slot Array (TLE)
// Time Complexity: O(N × MaxDeadline) == O(N^2)
// Space Complexity: O(MaxDeadline) 
// ---------------------------

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();

        vector<pair<int, int>> jobs;

        // Store {profit, deadline}.
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by profit in descending order.
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        // Find maximum deadline.
        int maxi = *max_element(deadline.begin(), deadline.end());

        // -1 indicates a free slot.
        vector<int> slot(maxi + 1, -1);

        int count = 0;
        int totalProfit = 0;

        // Schedule every job.
        for (int i = 0; i < n; i++) {

            int d = jobs[i].second;

            // Find the latest available slot.
            for (int j = d; j >= 1; j--) {

                if (slot[j] == -1) {

                    slot[j] = i;
                    count++;
                    totalProfit += jobs[i].first;
                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};


// ---------------------------
// Method 2 : Greedy + Min Heap
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();

        vector<pair<int,int>> arr;

        // Store {deadline, profit}.
        for(int i = 0; i < n; i++){
            arr.push_back({deadline[i], profit[i]});
        }

        // Sort by deadline.
        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int result = 0;

        for(int i = 0; i < n; i++)
        {
            int currDeadline = arr[i].first;
            int currProfit = arr[i].second;

            result += currProfit;
            pq.push(currProfit);

            // Remove the least profitable job
            // if jobs exceed available slots.
            if(pq.size() > currDeadline){

                int minProfit = pq.top();
                pq.pop();

                result -= minProfit;
            }
        }
        return {pq.size(), result};
    }
};