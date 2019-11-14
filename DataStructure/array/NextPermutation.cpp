/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
//O(n) if iterate from the back to the first(worst case) --> directly swap

class Solution {
public:
    /*
    ex:
    1, 2, 5, 4, 3 
--> 1, 3, 5, 4, 2 (do the swap of i(2) and j(3))
--> 1, 3, 2, 4, 5 (do the swap from i+1(5) to the end(2))
    
    */
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i+1] > nums[i]) {
                //find the smallest number(nums[j]) that is bigger then the nums[i] from the back, then swap nums[i] and nums[j]
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                //reverse the number from i+1 to the end
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        //If it is the biggest case, directly swap from the first to the end
        reverse(nums.begin(), nums.end());
    }
}; 
