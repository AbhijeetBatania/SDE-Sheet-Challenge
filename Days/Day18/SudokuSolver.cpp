/*
=========================================================
Problem: Sudoku Solver
Link: https://leetcode.com/problems/sudoku-solver/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: O(1) (Fixed Grid Size)
// Space Complexity: O(1) (Fixed Grid Size)
// ---------------------------

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char d) {

        // Check current column.
        for(int i = 0; i < 9; i++) {

            if(board[i][col] == d)
                return false;

            // Check current row.
            if(board[row][i] == d)
                return false;
        }

        // Starting index of 3x3 sub-grid.
        int start_i = row / 3 * 3;
        int start_j = col / 3 * 3;

        // Check the current 3x3 box.
        for(int k = 0; k < 3; k++) {

            for(int l = 0; l < 3; l++) {

                if(board[start_i + k][start_j + l] == d)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find an empty cell.
        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    // Try digits 1 to 9.
                    for(char d = '1'; d <= '9'; d++) {

                        if(isValid(board, i, j, d)) {

                            // Place digit.
                            board[i][j] = d;

                            if(solve(board))
                                return true;

                            // Backtrack.
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        // Sudoku solved.
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};