/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
//Dynamic Programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Corner Case:
        if (*max_element(nums.begin(),nums.end()) < 0) {
            return *max_element(nums.begin(),nums.end());
        }
        //General Case:
        vector<int> result_list(nums.size());
        result_list[0] = nums[0];
        //If result_list[i-1] > 0 --> result_list[i] = result_list[i-1] + nums[i]
       //If result_list <= 0 --> result_list[i] = nums[i]
        for (int i = 1; i < nums.size(); i++) {
            // result_list[i] = max(result_list[i-1] + nums[i], nums[i])
			if ((result_list[i-1]) > 0) {
                result_list[i] = result_list[i-1] + nums[i];
            } else {
                result_list[i] = nums[i];
            }
        }

        return *max_element(result_list.begin(),result_list.end());
    }
};
