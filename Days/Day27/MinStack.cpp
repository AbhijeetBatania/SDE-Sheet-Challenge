/*
=========================================================
Problem: Min Stack
Link: https://leetcode.com/problems/min-stack/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Two Stack Method
// Time Complexity: O(1)
// Space Complexity: O(N)
// ---------------------------------------------------------

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {}

    void push(int val) {

        st.push(val);

        // Push into min stack if current value
        // is smaller than current minimum
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop() {

        // Remove from min stack also
        // if current minimum is removed
        if (st.top() == minSt.top())
            minSt.pop();

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};


// ---------------------------------------------------------
// Approach 2 : Store Current Minimum With Every Element
// Time Complexity: O(1)
// Space Complexity: O(N)
// ---------------------------------------------------------

class MinStack {
public:

    stack<pair<int, int>> st; // {normal value, min value}

    MinStack() {}

    void push(int val) {

        if (st.empty()) {
            st.push({val, val});
        }
        else {

            // Store current minimum with every node
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};