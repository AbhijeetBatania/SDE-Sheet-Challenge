/*
=========================================================
Problem: Find Nth Root of M
Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
=========================================================
*/

// ---------------------------
// Method 1 : Binary Search + Linear Power
// Time Complexity: O(N * log M)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int power(int mid, int n, int m) {

        long long ans = 1;

        // Calculate mid^n.
        for (int i = 0; i < n; i++) {

            ans *= mid;

            // Greater than m.
            if (ans > m)
                return 2;
        }

        if (ans == m)
            return 1;

        return 0;
    }

    int nthRoot(int n, int m) {

        int low = 1;
        int high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int temp = power(mid, n, m);

            if (temp == 1)
                return mid;
            else if (temp == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};


// ---------------------------
// Method 2 : Binary Search + Fast Exponentiation
// Time Complexity: O(log N * log M)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int power(int mid, int n, int m) {

        long long ans = 1;

        // Fast exponentiation.
        while (n > 0) {

            if ((n & 1) == 1) {
                ans *= mid;
            }

            mid *= mid;
            n >>= 1;
        }

        if (ans > m)
            return 2;

        if (ans == m)
            return 1;

        return 0;
    }

    int nthRoot(int n, int m) {

        int low = 1;
        int high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int temp = power(mid, n, m);

            if (temp == 1)
                return mid;
            else if (temp == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};