/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

//My naive Solution
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums; 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                nums.push_back(matrix[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};

//BinarySearch 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int start = matrix[0][0];
        int end = matrix.back().back();
        while (start < end) {
            int mid = (start + end) / 2; 
            int count = 0;
            //If mid > the last element in the row --> return the number of the elements in this row (smaller elements than k )
            //If mid < the first element in the row --> return 0
            for (int i = 0; i < matrix.size(); i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            //If count < k --> need more smaller elements --> start = mid + 1
            if (count < k) {
                start = mid + 1;
            } else {
                end = mid; 
            }
        }
        return start; 
    }
};
