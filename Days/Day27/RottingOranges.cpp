/*
=========================================================
Problem: Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges/
=========================================================
*/

//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells

class Solution {
public:

    // Four possible movement directions
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;

        int freshCount = 0;

        // Push all rotten oranges into queue
        // Count fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {
                    que.push({i, j}); //Storing all possible sources at once in the queue
                }
                else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if(freshCount == 0)
            return 0;

        //Applying Multi-Source BFS
        int time = 0;

        while(!que.empty()) {

            int n = que.size();

            //because we want to cover all neighbours of a node
            //at once which are affected in a particular time frame
            while(n--) {

                pair<int, int> curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions) {

                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 &&
                       new_i < grid.size() &&
                       new_j >= 0 &&
                       new_j < grid[new_i].size() &&
                       grid[new_i][new_j] == 1) {

                        grid[new_i][new_j] = 2;
                        que.push({new_i, new_j});
                        freshCount--;
                    }
                }
            }

            time++;
        }

        time--;  // cause 1 extra min is added

        return (freshCount==0) ? time : -1;
    }
};