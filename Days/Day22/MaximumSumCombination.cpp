/*
=========================================================
Problem: Maximum Sum Combination
Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
=========================================================
*/

// ---------------------------
// Method 1 : Sorting + Max Heap
// Time Complexity: O(N log N + K log K)
// Space Complexity: O(K)
// ---------------------------

class Solution {
public:

    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {

        int n = a.size();

        // Sort both arrays in descending order.
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        // {Sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>> pq;

        // Store visited index pairs.
        set<pair<int, int>> vis;

        // Push the maximum possible sum.
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});

        vector<int> ans;

        while(ans.size() < k) {

            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);

            // Push next pair from first array.
            if(i + 1 < n && vis.find({i + 1, j}) == vis.end()) {

                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }

            // Push next pair from second array.
            if(j + 1 < n && vis.find({i, j + 1}) == vis.end()) {

                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }

        return ans;
    }
};


// ---------------------------
// Method 2 : Tuple Based Max Heap
// Time Complexity: O(N log N + K log K)
// Space Complexity: O(K)
// ---------------------------

class Solution {
public:

    vector<int> topKSumPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Sort arrays in descending order.
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        // {Sum, i, j}
        priority_queue<tuple<int, int, int>> maxHeap;

        // Stores visited index pairs.
        set<pair<int, int>> visited;

        // Push largest possible sum.
        maxHeap.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        vector<int> result;

        while(k-- && !maxHeap.empty()) {

            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();

            result.push_back(sum);

            // Move to next element in nums1.
            if(i + 1 < nums1.size() && !visited.count({i + 1, j})) {

                maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            // Move to next element in nums2.
            if(j + 1 < nums2.size() && !visited.count({i, j + 1})) {

                maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return result;
    }
};