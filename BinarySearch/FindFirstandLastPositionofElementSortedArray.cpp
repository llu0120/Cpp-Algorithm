/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        //Corner Cases: [],0 
        if (nums.size() == 0) {
            return result;
        }
        //Corner Case: [2,2],2
        if (nums.size() == 1 && nums[0] == target) {
            result[0] = 0;
            result[1] = 0;
            return result;
        }
        
        //General Cases
        int start = 0;
        int end = nums.size()-1;
        int flag = 0; 
        int mid;
        while (start + 1 < end) {
            mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid; 
            } else {
                end = mid;
            } 
        }
        
        //If didn't matcht the target
        if (nums[start] != target && nums[end] != target) {
            return result;
        }
        
        while (nums[end] == target) {
            end++;
            if (end == nums.size()) break; //If out of vector bound
        } 
        end--;
        
        while (nums[start] == target) {
            start--;
            if (start == -1) break; //If out of vector bound
        }
        start++;
        
        result[0] = start;
        result[1] = end;
        return result;
    }
};
