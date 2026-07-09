/*
=========================================================
Problem: Implement Stack using Array
Link: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
=========================================================
*/

class myStack {
    int *arr;  // vector<int> arr;
    int top;
    int size;

public:
    myStack(int n) {
        size = n;
        arr = new int[size];  //arr.resize(size);
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (isFull()) {
            return;   // Stack Overflow
        }
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            return;   // Stack Underflow
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }
};


// ---------------------------
// Method 2 : Using STL Stack
// Time Complexity:
// push()  -> O(1)
// pop()   -> O(1)
// peek()  -> O(1)
// isEmpty() -> O(1)
// isFull()  -> O(1)
// Space Complexity: O(N)
// ---------------------------

class myStack {
    stack<int> st;
    int capacity;

public:
    myStack(int n) {
        capacity = n;
    }

    bool isEmpty() {
        return st.empty();
    }

    bool isFull() {
        return st.size() == capacity;
    }

    void push(int x) {

        // Insert element only if stack is not full.
        if (!isFull())
            st.push(x);
    }

    void pop() {

        // Remove top element if present.
        if (!st.empty())
            st.pop();
    }

    int peek() {

        // Return top element.
        if (!st.empty()) 
            return st.top();

        return -1;
    }
};