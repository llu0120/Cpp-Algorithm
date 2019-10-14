/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/ 
//O(n) 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int nums_size = nums.size();
        vector<int> cur_max(nums_size, 0);
        vector<int> cur_min(nums_size, 0);
        cur_max[0] = nums[0];
        cur_min[0] = nums[0];
        for (int i = 1; i< nums_size; i++) {
            cur_max[i] = max(max(cur_max[i-1]*nums[i], cur_min[i-1]*nums[i]), nums[i]);
            //The cur_min[i] number might be negative, then when a negative number times a negative number --> it might be big 
            cur_min[i] = min(min(cur_max[i-1]*nums[i], cur_min[i-1]*nums[i]), nums[i]);
            result = max(result, cur_max[i]);
        }
        return result;
    }
};
