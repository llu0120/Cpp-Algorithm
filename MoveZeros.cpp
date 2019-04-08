//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Example
//Example 1:
//Input: nums = [0, 1, 0, 3, 12],
//Output: [1, 3, 12, 0, 0].
//Example 2:
//Input: nums = [0, 0, 0, 3, 1],
//Output: [3, 1, 0, 0, 0].
//Notice
//You must do this in-place without making a copy of the array.
//Minimize the total number of operations.


class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = 0;
        int len = nums.size();
        while(right< len){
            if (nums[right] != 0){     //if the right pointer number is not zero, then swap the number of left pointer and right pointer. Then move the left pointer.
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
            right++;
        }
        }
};
