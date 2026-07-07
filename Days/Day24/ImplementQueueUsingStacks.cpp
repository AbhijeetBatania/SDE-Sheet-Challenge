/*
=========================================================
Problem: Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/
=========================================================
*/

// ---------------------------
// Method 1 : Two Stacks
// Amortized Time Complexity:
// push() -> O(1)
// pop()  -> O(1)
// peek() -> O(1)
// Space Complexity: O(N)
// ---------------------------

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {

        // Always push into first stack.
        s1.push(x);
    }

    int pop() {

        // Transfer elements only when needed.
        if(s2.empty()){

            while(!s1.empty()){

                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();

        return x;
    }

    int peek() {

        // Transfer elements only when needed.
        if(s2.empty()){

            while(!s1.empty()){

                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {

        return s1.empty() && s2.empty();
    }
};