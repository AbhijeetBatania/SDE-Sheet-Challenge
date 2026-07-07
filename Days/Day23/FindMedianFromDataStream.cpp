/*
=========================================================
Problem: Find Median from Data Stream
Link: https://leetcode.com/problems/find-median-from-data-stream/
=========================================================
*/

// ---------------------------
// Method 1 : Store + Sort (TLE)
// Time Complexity:
// addNum()     -> O(1)
// findMedian() -> O(N log N)
// Space Complexity: O(N)
// ---------------------------

class MedianFinder {
public:
    vector<int> arr;

    MedianFinder() {
    }

    // Insert new number.
    void addNum(int num) {
        arr.push_back(num);
    }

    // Sort every time before finding median.
    double findMedian() {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        if(n % 2 == 1)
            return arr[n/2];

        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    }
};


// ---------------------------
// Method 2 : Two Heaps
// Time Complexity:
// addNum()     -> O(log N)
// findMedian() -> O(1)
// Space Complexity: O(N)
// ---------------------------

class MedianFinder {
public:

    // Max heap stores left half.
    priority_queue<int> left_max_heap;

    // Min heap stores right half.
    priority_queue<int, vector<int>, greater<int>> right_min_heap;

    MedianFinder() {
    }

    void addNum(int num) {

        // Insert into appropriate heap.
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        }
        else {
            right_min_heap.push(num);
        }

        // Balance both heaps.

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {

            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size()) {

            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    double findMedian() {

        // Even number of elements.
        if(left_max_heap.size() == right_min_heap.size()) {

            return (double)(left_max_heap.top() + right_min_heap.top()) / 2;
        }

        // Odd number of elements.
        return left_max_heap.top();
    }
};