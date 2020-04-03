/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
class Solution {
public:
    vector<pair<int, int>> DIR{{1,0},{0,1},{-1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        unordered_map<int, int> um;  //location code, time 
        int m = grid.size(); 
        int n = grid[0].size();

        //Start from all rotten orange
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    int code = i*n + j; 
                    q.push(code);
                    um[code] = 0; 
                }
            }
        }

        //BFS
        int result = 0; 
        while (!q.empty()) {
            int tmp_i = q.front() / n;
            int tmp_j = q.front() % n;
            cout << tmp_i << ", " << tmp_j << endl; 
            q.pop();
            for (auto dir : DIR) {
                int next_i = tmp_i+dir.first;
                int next_j = tmp_j+dir.second;

                if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && grid[next_i][next_j] == 1) {
                    
                    grid[next_i][next_j] = 2; 
                    q.push(next_i*n + next_j);
                    um[next_i*n + next_j] = um[tmp_i*n + tmp_j] + 1; 
                    result = um[next_i*n + next_j];
                }
            }
        }
        
        //Check if there is fresh orange left
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    result = -1;
                    break;
                }
            }
        }
        return result; 
    }
    

};
