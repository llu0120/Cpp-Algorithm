/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //Corner Case
        if (nums.size() == 0) {
            return false;
        }
        //General Case
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (nums[start] > nums[mid]) { //This means the right sequence is a sorted array and the left is a rotated sorted array
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else if (nums[start] < nums[mid]) { //This means the right sequence is a rotated sorted array and the left is a sorted array
                if (nums[mid] > target && target >= nums[start]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                start++; //When meet the condition nums[start] == nums[mid], move start forward 
            }
        }
        if (nums[start] == target || nums[end] == target) {
            return true;
        } else {
            return false;
        }
    }
};
