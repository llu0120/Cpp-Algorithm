/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Corner Case:
        
        if (obstacleGrid[0][0] == 1) {
            return 0; 
        }
        
        
        
        //General Case: 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        
        vector<long> col(n, 0);
        vector<vector<long>> grid(m, col);
        
        //Initialize
        grid[0][0] = 1;
        //If the first column confront a 1 --> the grid below will all be 0 
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break; 
            }
            grid[i][0] += 1;
        }
        //If the first row confront a 1 --> the grid at the right will all be 0
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            grid[0][j] += 1;
        }
        
        //dynamic programming
        for (int i = 1; i < m; i++) {
            for (int j = 1; j< n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    grid[i][j] = 0; 
                    continue;
                }
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
            }
        }
        return grid[m-1][n-1];
    }
};
