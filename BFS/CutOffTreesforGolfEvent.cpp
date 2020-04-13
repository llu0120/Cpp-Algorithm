/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
In one step you can walk in any of the four directions top, bottom, left and right also when standing in a point which is a tree you can decide whether or not to cut off the tree.

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 

Example 2:

Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 

Example 3:

Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
 

Constraints:

1 <= forest.length <= 50
1 <= forest[i].length <= 50
0 <= forest[i][j] <= 10^9
*/

class Solution {
public:
    vector<pair<int, int>> DIR{{1,0},{0,1},{-1,0},{0,-1}};
    int cutOffTree(vector<vector<int>>& forest) {
        int result = 0; 
        int m = forest.size(); 
        int n = forest[0].size(); 
        vector< pair<int, pair<int, int>> > info; //int: tree height, pair<int, int>: location 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    info.push_back({forest[i][j], {i,j}});
                }
            }
        }
		//Sort the info to know which tree need to be cut first
        sort(info.begin(), info.end());
        pair<int, pair<int, int>> cur{forest[0][0], {0,0}};
        for (int i = 0; i < info.size(); ++i) {
            pair<int, pair<int, int>> goal = info[i];
            int next_step = bfs(forest, cur, goal); 
            if(next_step == -1) {
                return -1; 
            }
            result += next_step; 
            cur = goal; 
        }
        return result; 
    }
    
    int bfs(vector<vector<int>>& forest, pair<int, pair<int, int>>& cur, pair<int, pair<int, int>>& goal) {
        if (cur.second.first == goal.second.first && cur.second.second == goal.second.second) {
            return 0; 
        }
        int m = forest.size();
        int n = forest[0].size(); 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[cur.second.first][cur.second.second] = 1;
        int length = 0; 
        queue<pair<int, int>> q; 
        q.push(cur.second); 
        while (!q.empty()) {
            int qsize = q.size(); 
            length++; 
            for (int i = 0; i < qsize; ++i) {
                pair<int, int> tmp_loc = q.front(); 
                q.pop(); 
                for (auto dir : DIR) {
                    pair<int, int> next_loc{tmp_loc.first+dir.first, tmp_loc.second+dir.second};
                    if (next_loc.first == goal.second.first && next_loc.second == goal.second.second) {
                        return length; 
                    }
                    if (!isValid(forest, next_loc, visited)) {
                        continue; 
                    }
                    q.push(next_loc);
                    visited[next_loc.first][next_loc.second] = 1; 
                }
            }
        }
        return -1; 
    }
    
    bool isValid(vector<vector<int>>& forest, pair<int, int>& loc, vector<vector<int>>& visited) {
        int m = forest.size(); 
        int n = forest[0].size(); 
        if (loc.first < 0 || loc.first >= m || loc.second < 0 || loc.second >= n) {
            return false; 
        }
        if (forest[loc.first][loc.second] == 0) {
            return false; 
        }
        if (visited[loc.first][loc.second] == 1) {
            return false;
        }
        return true;
    }
};
