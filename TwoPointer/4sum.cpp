/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int nums_size = nums.size();
        vector<vector<int>> result; 
        //Corner Case:
        if (nums_size < 4) {
            return result;
        }
        
        //General Case:
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            //if nums[i] is the same as the one traverse before --> continue
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                //if nums[j] is the same as the one traverse before --> continue
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums_size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> sol_set{nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(sol_set);
                        while (left + 1 < right && nums[left] == nums[left+1]) {
                            left++;
                        } 
                        left++;
                        while (left < right - 1 && nums[right] == nums[right-1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

