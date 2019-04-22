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
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if (grid.size() == 0) return 0; 
        int count = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == false) continue; // if grid is 0 or has been visited, then continue
                bfs(grid, make_pair(i,j));
                count++;
            }
        }
        return count;
    }
    
    bool isValid(vector<vector<bool>>& grid, pair<int,int> loc){
        if (loc.first < 0 || loc.first >= grid.size()) return false;// Out of bound
        if (loc.second < 0 || loc.second >= grid[0].size()) return false; //Out of bound
        if (grid[loc.first][loc.second] == false) return false;  //See if this node has been visit or not 
        return true;
    }
    
    void bfs(vector<vector<bool>> &grid, pair<int,int> loc){
        queue<pair<int,int>> Q; // Initialize a queue;
        Q.push(loc); // push the node into the queue
        grid[loc.first][loc.second] = false;    // Set this node to 0 --> means visited
        while (!Q.empty()){
            pair<int,int> tmp = Q.front();
            Q.pop();                            // pop the node: FIFO 
            for (auto direction: directions){
                pair<int,int> next_loc = make_pair(tmp.first + direction.first, tmp.second + direction.second);
                if (!isValid(grid,next_loc)) continue;
                Q.push(next_loc);               //Add next_loc into queue
                grid[next_loc.first][next_loc.second] = false;
            }
            
        }
    }
    
};
