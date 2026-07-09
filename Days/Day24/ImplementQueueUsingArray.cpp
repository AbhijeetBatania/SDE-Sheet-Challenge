/*
=========================================================
Problem: Implement Queue using Array
Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
=========================================================
*/

class myQueue {   // Circular Queue
    int *arr;
    int front, rear;
    int size;

public:
    myQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        if (isFull()) return;

        // First element insertion
        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;

        // Removing last element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;

        return arr[rear];
    }
};


// ---------------------------
// Method 2 : Using STL Queue
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