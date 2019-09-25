/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Corner Case
        if (nums.size() == 0) {
            return -1;
        }
        //General Case
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[start]) { //This means the left sequence is rotated sorted array and the right is a sorted array
                if (nums[mid] < target && target <= nums[end]) { //If target is in the range of right sorted array
                    start = mid;
                } else {
                    end = mid;
                }
            } else { // This means the left sequence is a sorted array and the right is a rotated sorted array
                if (nums[mid] > target && target >= nums[start]) { //If target is in the range of left sorted array
                    end = mid; 
                } else {
                    start = mid;
                }
            }
        }

        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};
