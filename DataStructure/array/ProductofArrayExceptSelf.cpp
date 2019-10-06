/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/
//Time: O(n) Space: O(n) 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> forward_product(nums_size,1);
        vector<int> backward_product(nums_size,1);
        vector<int> result;
        for (int i = 0; i < nums_size - 1; i++) {
           //forward_product: there is no numbers in front of index 0 --> forward_product[0] = 1
            forward_product[i+1] = forward_product[i] * nums[i];
        }
        for (int i = nums_size - 1; i > 0; i--) {
            //backward_product: there is no numbers at the back of index 3 --> backward_product[3] = 1
            backward_product[i-1] = backward_product[i] * nums[i];
        }
        for (int i = 0; i < nums_size; i++) {
            result.push_back(forward_product[i]*backward_product[i]);
        }
        return result;
    }
};

//Time: O(n) Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> result(nums_size,1);
        //Calculate forward_product
        for (int i = 0; i < nums_size - 1; i++) {
            result[i+1] = result[i]*nums[i];
        }
        //Set a backward product 
        int backward = 1;
        for (int i = nums_size - 1; i >= 0; i--) {
            result[i] *= backward;
            backward *= nums[i];
        }
        return result;
    }
};
