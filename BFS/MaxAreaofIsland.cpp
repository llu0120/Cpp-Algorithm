/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    vector<vector<int>> DIR{{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool isValid(vector<vector<int> >& grid, pair<int, int> loc) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        if (loc.first < 0 || loc.first >= row_size) { //Out of Bound
            return false;
        }
        if (loc.second < 0 || loc.second >= col_size) { //Out of Bound
            return false;
        }
        if (grid[loc.first][loc.second] == 0) { //Visited before or is water
            return false;
        }
        return true;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        int result = 0; 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                //If visited set to 0 
                grid[i][j] = 0; 
                queue<pair<int, int>> q;
                q.push({i, j});
                int tmp_res = 1; //Now include 1 island
                
                while (!q.empty()) {
                    pair<int, int> tmp_loc = q.front();
                    q.pop();
                    //Update the result
                    result = max(result, tmp_res++);
                    
                    //Traverse each directions
                    for (auto dir : DIR) {
                        pair<int, int> next_loc = {tmp_loc.first + dir[0], tmp_loc.second + dir[1]};
                        
                        //If out of bound or visited
                        if (!isValid(grid, next_loc)) {
                            continue;
                        }
                        //if visited set to 0 
                        grid[next_loc.first][next_loc.second] = 0; 
                        q.push(next_loc);
                    }
                }
            }
        }
        return result;
    }
    
};
