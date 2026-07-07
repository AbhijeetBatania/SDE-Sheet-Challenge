/*
=========================================================
Problem: Implement Queue using Array
Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
=========================================================
*/

// ---------------------------
// Method 1 : Using STL Queue
// Time Complexity:
// enqueue() -> O(1)
// dequeue() -> O(1)
// getFront() -> O(1)
// getRear() -> O(1)
// Space Complexity: O(N)
// ---------------------------

class myQueue {
    queue<int> q;
    int capacity;

public:
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return q.empty();
    }

    bool isFull() {
        // check if the queue is full
        return q.size() == capacity;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if (!isFull())
            q.push(x);
    }

    void dequeue() {
        // Removes the front element of the queue.
        if (!isEmpty())
            q.pop();
    }

    int getFront() {
        // Returns the front element of the queue.
        if (!isEmpty())
            return q.front();
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if (!isEmpty())
            return q.back();
        return -1;
    }
};