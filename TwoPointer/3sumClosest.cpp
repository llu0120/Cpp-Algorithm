/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/ 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nums_size = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2]; //Initialize the closest sum 
        int diff = abs(closest_sum - target); //Initialize the smallest diff 
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums_size; i++) {
            int left = i + 1; 
            int right = nums_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int new_diff = abs(sum - target);
                if (new_diff < diff) { //If the diff is smaller, update the closest sum and the smallest diff
                    closest_sum = sum;
                    diff = new_diff;
                }
                if (sum < target) { //Make the sum closest to the target
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closest_sum;
    }
};
