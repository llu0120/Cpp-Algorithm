/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nums_size = nums.size(); 
        vector<vector<int>> result; 
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_size - 2; i++) {
            //The first three elements sum > 0 --> This means no solutions in the vector
            if (nums[i] + nums[i+1] + nums[i+2] > 0) {
                break;
            }
            //The i element + the last two elements < 0 --> This means there will be no other two elements + nums[i] will be >= 0
            if (nums[i] + nums[nums_size - 1] + nums[nums_size - 2] < 0) {
                continue;
            }
            //If nums[i] is same as nums[i-1] --> continue
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> sol_set{nums[i], nums[left], nums[right]};
                    result.push_back(sol_set);
                    //move left pointer to left+1 --> left+1 should be smaller than right (left+1<right)
                    //if nums[left] == nums[left+1], left pointer should keep moving
                    while (left + 1 < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    //To make it different than nums[left]
                    left++;
                    //move right pointer to right-1 --> right-1 should be smaller than right (left<right-1)
                    //if nums[right] == nums[right-1], right pointer should keep moving
                    while (left < right - 1 && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    //To make it different than nums[right]
                    right--;
                } else if (sum < 0) {
                    left++;                    
                } else { //sum > 0
                    right--;
                }     
            }
        }
        return result;
    }
};
