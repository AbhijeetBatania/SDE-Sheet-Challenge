/*
=========================================================
Problem: Max Heap Implementation
Link: https://www.geeksforgeeks.org/problems/max-heap-implementation/1
=========================================================
*/

// ---------------------------
// Method 1 : Using STL Priority Queue
// Time Complexity:
// push()  -> O(log N)
// pop()   -> O(log N)
// peek()  -> O(1)
// size()  -> O(1)
// Space Complexity: O(N)
// ---------------------------

class maxHeap {
private:

    // STL priority_queue is implemented as a Max Heap by default.
    priority_queue<int> pq;

public:

    // Insert an element.
    void push(int x) {
        pq.push(x);
    }

    // Remove the maximum element.
    void pop() {

        if (!pq.empty())
            pq.pop();
    }

    // Return the maximum element.
    int peek() {

        if (!pq.empty())
            return pq.top();

        return -1;
    }

    // Return current heap size.
    int size() {
        return pq.size();
    }
};