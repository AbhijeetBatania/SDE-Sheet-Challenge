/*
=========================================================
Problem: Pow(x, n)
Link: https://leetcode.com/problems/powx-n/
=========================================================
*/

// ---------------------------
// Method 1 : Binary Exponentiation (Recursive)
// Time Complexity: O(log N)
// Space Complexity: O(log N)
// ---------------------------

class Solution {
public:

    double solve(double x, long n) {

        // Base case.
        if (n == 0)
            return 1;

        // Handle negative powers.
        if (n < 0)
            return 1 / solve(x, -n);

        // If power is even,
        // square the base and halve the exponent.
        if (n % 2 == 0)
            return solve(x * x, n / 2);

        // If power is odd,
        // multiply one x and solve the remaining power.
        return x * solve(x * x, (n - 1) / 2);
    }

    double myPow(double x, int n) {

        return solve(x, (long)n);
    }
};