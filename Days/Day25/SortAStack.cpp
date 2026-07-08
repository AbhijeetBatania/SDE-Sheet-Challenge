/*
=========================================================
Problem: Sort a Stack
Link: https://www.geeksforgeeks.org/problems/sort-a-stack/1
=========================================================
*/

// ---------------------------
// Method 1 : Using Two Extra Stacks
// Time Complexity: O(N²)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    void sortStack(stack<int> &st) {
        // code here
        stack<int> s1, s2;

        while(!st.empty()){

            int x = st.top();
            st.pop();

            if(s1.empty() || s1.top() <= x){
                s1.push(x);
            }
            else{

                // Move larger elements temporarily.
                while(!s1.empty() && s1.top() > x){
                    int y = s1.top();
                    s1.pop();
                    s2.push(y);
                }

                s1.push(x);

                // Restore elements.
                while(!s2.empty()){
                    int z = s2.top();
                    s2.pop();
                    s1.push(z);
                }
            }
        }

        st = s1;
    }
};


// ---------------------------
// Method 2 : Recursion
// Time Complexity: O(N²)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    // Insert current element into its correct position.
    void insertSorted(stack<int> &st, int x) {

        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }

    void sortStack(stack<int> &st) {

        if (st.empty())
            return;

        int x = st.top();
        st.pop();

        // Sort remaining stack.
        sortStack(st);

        // Insert current element.
        insertSorted(st, x);
    }
};