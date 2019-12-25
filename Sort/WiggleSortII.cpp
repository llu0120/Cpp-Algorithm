/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums; 
        sort(tmp.begin(), tmp.end());
        int mid = (nums.size() + 1) / 2; 
        int end = nums.size();
        //Divide the copy of nums --> tmp by 2
        //Select each from the first and second part of tmp to put into nums 
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = tmp[mid-1];
                mid--;
            } else {
                nums[i] = tmp[end-1];
                end--;
            }
        }
    }
};
