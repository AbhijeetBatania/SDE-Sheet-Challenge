/*
=========================================================
Problem: Implement Stack using Queues
Link: https://leetcode.com/problems/implement-stack-using-queues/
=========================================================
*/

// ---------------------------
// Method 1 : Single Queue
// Time Complexity:
// push() -> O(N)
// pop()  -> O(1)
// top()  -> O(1)
// empty()-> O(1)
// Space Complexity: O(N)
// ---------------------------

class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {

        // Insert new element.
        q.push(x);

        // Move all previous elements behind the new element
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        int x = q.front();
        q.pop();

        return x;
    }

    int top() {

        return q.front();
    }

    bool empty() {

        return q.empty();
    }
};