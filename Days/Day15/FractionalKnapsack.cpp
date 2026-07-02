/*
=========================================================
Problem: Fractional Knapsack
Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Greedy (Value / Weight)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();

        vector<pair<double,int>> vec(n);

        // Store {value/weight ratio, index}.
        for(int i = 0; i < n; i++){

            vec[i].first = (double)val[i] / wt[i];
            vec[i].second = i;
        }

        // Sort by ratio in descending order.
        sort(vec.begin(), vec.end(), greater<pair<double,int>>());

        double profit = 0;

        for(int i = 0; i < vec.size(); i++){

            int idx = vec[i].second;

            // Take the whole item.
            if(capacity >= wt[idx]){

                profit += val[idx];
                capacity -= wt[idx];
            }
            else{

                // Take only the required fraction.
                profit += ((double)capacity / wt[idx]) * val[idx];
                break;
            }
        }
        return profit;
    }
};