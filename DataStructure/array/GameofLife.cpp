/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/
//O(mn)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //Corner Case:
        if (board.size() == 0) {
            return;
        }
        //General Case:
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbor = liveNeighborsNum(board, m, n, i, j);
                //Died case --> use 3 to represent
                if ((board[i][j] == 1 && liveNeighbor < 2) || (board[i][j] == 1 && liveNeighbor > 3)) {
                    board[i][j] = 3;
                }
                //Recover case --> use 4 to represent
                if (board[i][j] == 0 && liveNeighbor == 3) {
                    board[i][j] = 4;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 3) { //if board[i][j] == 3 -> the cell will die next gen
                    board[i][j] = 0;
                }
                if (board[i][j] == 4) { //if board[i][j] == 4 -> the cell will recover next gen
                    board[i][j] = 1;
                }
            }
        }
        return;
    }
    
    int liveNeighborsNum(vector<vector<int>>& board, int m, int n, int i, int j) {
        int neighborsNum = 0;
        for (int y = i - 1; y <= i + 1; y++) {
            if (y < 0 || y >= m) continue;
            for (int x = j - 1; x <= j + 1; x++) {
                if (x < 0 || x >= n) continue;
                if (board[y][x] == 1 || board[y][x] == 3) { //board[y][x] == 3 means the cell is originally alive == 1 but will died == 0 next generation
                    neighborsNum++;
                }
            }
        }
        
        if (board[i][j] == 1) { //If the cell itself is 1 --> need to substract one to the calculated number of live neighbor
            neighborsNum--;
        }
        
        
        return neighborsNum;
    }
};
