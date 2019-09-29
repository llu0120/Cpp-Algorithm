/*
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.

Example
Example 1:

Input:
[
  [1,1,0,0,0],
  [0,1,0,0,1],
  [0,0,0,1,1],
  [0,0,0,0,0],
  [0,0,0,0,1]
]
Output:
3
Example 2:

Input:
[
  [1,1]
]
Output:
1
*/

class Solution {
public:
    vector<pair<int, int> > DIRECTIONS{{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        //Corner Case:
        if (grid.size() == 0) {
            return 0;
        }
        int row_size = grid.size(); 
        int col_size = grid[0].size();
        //General Case: 
        int count = 0; 
        for (int i = 0; i< row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == '0') { //Visited before or is '0'
                    continue;
                } else {
                    bfs(grid, make_pair(i,j));
                    count++;
                } 
            }
        }
        return count; 
    }
    bool isValid(vector<vector<char> >& grid, pair<int, int> loc) {
        int row_size = grid.size(); 
        int col_size = grid[0].size();
        if (loc.first < 0 || loc.first >= row_size) { //Out of Bound
            return false;
        } 
        if (loc.second < 0 || loc.second >= col_size) { //Out of Bound
            return false;
        }
        if (grid[loc.first][loc.second] == '0') { //Visited before or is water
            return false;
        } 
        return true;
    }
    void bfs(vector<vector<char> >& grid, pair<int, int> loc) {
        queue<pair<int, int>> q;
        q.push(loc);
        grid[loc.first][loc.second] = '0'; //Means visited
        while (!q.empty()) {
            pair<int, int> tmp_loc = q.front(); 
            q.pop();
            for (auto dir: DIRECTIONS) {
                pair<int,int> next_loc = make_pair(tmp_loc.first + dir.first, tmp_loc.second + dir.second);
                if (!isValid(grid, next_loc)) {
                    continue;
                }
                q.push(next_loc); 
                grid[next_loc.first][next_loc.second] = '0'; //Means visited
            }
        }
        
    }
};