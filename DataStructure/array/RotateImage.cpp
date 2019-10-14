/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/ 
//O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //First swap (the first and the last row), (the second and the second last row)...
        int top = 0; 
        int down = matrix.size() - 1;
        while (top < down) {
            vector<int> tmp_row = matrix[top];
            matrix[top] = matrix[down];
            matrix[down] = tmp_row;
            top++;
            down--;
        }
        //swap the elements symmetric to the diagonal --> if the image is 3*3, start from index (0,1), (0,2), (0,3), (1,2), (1,3), (2,3)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[i].size(); j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        return;
    }
};
