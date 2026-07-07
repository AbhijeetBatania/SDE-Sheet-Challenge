/*
=========================================================
Problem: Top K Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements/
=========================================================
*/

// ---------------------------
// Method 1 : Min Heap
// Time Complexity: O(N log K)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Frequency map.
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        // Min heap stores {frequency, number}.
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        // Maintain heap of size k.
        for(auto it : mp) {
            
            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> result;

        while(!pq.empty()) {

            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};


// ---------------------------
// Method 2 : Bucket Sort
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency.
        for(int num : nums) {

            freq[num]++;
        }

        // bucket[i] stores numbers occurring i times.
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &it : freq) {

            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Traverse from highest frequency.
        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {

            for(int num : bucket[i]) {

                ans.push_back(num);

                if(ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};