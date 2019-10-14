/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/ 
//O(mn)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; 
        if (matrix.size() == 0) {
            return result; 
        }
        //Create boundary that tracks the matrix elements that has been traversed
        int row_start = 0; 
        int row_end = matrix.size() - 1;
        int col_start = 0; 
        int col_end = matrix[0].size() - 1;
        while (row_start <= row_end && col_start <= col_end) {
            for (int i = col_start; i <= col_end; i++) { 
                cout << matrix[row_start][i] << endl;
                result.push_back(matrix[row_start][i]); //1,2,3   --> next iteration 5 
            }
            row_start++;
            for (int i = row_start; i <= row_end; i++) { 
                result.push_back(matrix[i][col_end]); //6,9
            }
            col_end--;
            if (row_start <= row_end) {
                for (int i = col_end; i >= col_start; i--) {
                    result.push_back(matrix[row_end][i]); //7,8
                }
            }
            row_end--;
            if (col_start <= col_end) {
                for (int i = row_end; i >= row_start; i--) {
                    result.push_back(matrix[i][col_start]); //4
                }
            }
            col_start++;
        }
        return result;
    }
};
