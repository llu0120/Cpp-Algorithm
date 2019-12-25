/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numSize = nums.size();
        //Swap 2nd and 3rd, Swap 4th and 5th ...... 
        for (int i = 2; i < nums.size(); i += 2) {    
                swap(nums[i], nums[i-1]);
            }
        return;
    }
};
