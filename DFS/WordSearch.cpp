/* O(m*n*(l^4), l = len(word) 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/ 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        int w = board[0].size();
        //Corner Case:
        if (h*w < word.size()) {
            return false;
        }
        //Genaral Case: 
        //for each position in the board 
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (dfsSearch(board, word, x, y, 0)){
                    return true;
                } 
            }
        }
        return false;
    }
    
    bool dfsSearch(vector<vector<char>>& board, string word, int x, int y, int d) {
        int h = board.size();
        int w = board[0].size();
        //Out of bound
        if (x == w || x < 0 || y == h || y < 0) {
            return false;
        }
        //If the character doesn't match 
        if (word[d] != board[y][x]) {
            return false;
        }
        //if d is the last one 
        if (d == word.size() - 1) {
            return true; 
        }
        //To pass the board into the recursive function, need to set the current position to 0 
        char cur = board[y][x];
        board[y][x] = 0; //Mean visited
        //four direction 
        bool found = dfsSearch(board, word, x+1, y, d+1)
                    || dfsSearch(board, word, x-1, y, d+1)
                    || dfsSearch(board, word, x, y+1, d+1)
                    || dfsSearch(board, word, x, y-1, d+1);
        board[y][x] = cur; //Recover the original status 
        return found;
    }
};
