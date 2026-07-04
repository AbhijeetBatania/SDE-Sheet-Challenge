/*
=========================================================
Problem: N-Queens
Link: https://leetcode.com/problems/n-queens/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: O(N!)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    vector<vector<string>> ans;

    bool isValid(int row, int col, vector<string>& board){

        // Check upward column.
        for(int i = row; i >= 0; i--){
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper left diagonal.
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        // Check upper right diagonal.
        for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n){

        // All queens placed successfully.
        if(row == n){
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column.
        for(int col = 0; col < n; col++){

            if(isValid(row, col, board)){

                board[row][col] = 'Q';

                solve(row + 1, board, n);

                // Backtrack.
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        if(n == 0)
            return {};

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};