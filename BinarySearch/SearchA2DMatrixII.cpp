/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Corner Case: 
        if (matrix.size() == 0) {
            return false;
        }
        if (matrix.size() != 0 && matrix[0].size() == 0) {
            return false;
        }
        //General Case:
        //Start from the left bottom of the matrix to search
        //--> upper number is smaller, righter number is bigger 
        int row_ind = matrix.size() - 1;
        int col_ind = 0; 
        while (true) {
            if (matrix[row_ind][col_ind] > target) {
                row_ind--;
            } else if (matrix[row_ind][col_ind] < target) {
                col_ind++;
            } else if (matrix[row_ind][col_ind] == target) {
                return true;
            } 
            
            if (row_ind < 0 || col_ind > matrix[0].size() - 1) {
                break;
            }
        }
        return false;
    }
};
