/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/ 

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        //Corner Case: 
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row_index = 0;
        int mid;
        int num_row = matrix.size();
        int num_col = matrix[0].size();
        //First Binary Search for the first column to determine the target is on which row
        int start = 0;
        int end = num_row - 1;
        while (start + 1 < end) {
            mid = (start + end) / 2; 
            if (matrix[mid][0] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        //If the target is on the first column of the matrix
        if (matrix[start][0] == target || matrix[end][0] == target) {
            return true;
        }
        //Determine the target's row index
        if (target > matrix[end][0]){
            row_index = end;   
        } else {
            row_index = start;
        }
        
        //Knowing that the target is on certain row index, search the row if target is on it. 
        start = 0; 
        end = num_col - 1;
        while (start + 1 < end) {
            mid = (start + end) / 2;
            if (matrix[row_index][mid] == target) {
                return true;
            }
            if (matrix[row_index][mid] > target) {
                end = mid;    
            } else {
                start = mid;
            }
        }
        if (matrix[row_index][start] == target || matrix[row_index][end] == target) {
            return true;
        }
        return false;
    }
};
