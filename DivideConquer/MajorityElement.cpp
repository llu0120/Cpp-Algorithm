/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

//Using Hash Map: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> count; 
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        for (int i = 0; i < size; i++) {
            if (count.find(nums[i]) == count.end()) {
                count[nums[i]] = 1;
            } else {
                count[nums[i]]++;
                if (count[nums[i]] > (size/2)) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
//Divide and Conquer(recursion): O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int start = 0; 
        int end = nums.size() - 1;
        return majorityElement(nums, start, end);
    }
private: 
    int majorityElement(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        //Divide the vector by 2
        int mid = (left + right) / 2;
        //Compute the majority element on the left and right
        int majority_left = majorityElement(nums, left, mid);
        int majority_right = majorityElement(nums, mid + 1, right);
        //If the majority element on the left and right are the same --> return that element
        if (majority_left == majority_right) {
            return majority_left;
        }
        //Count the majority_element in the vector, determine the majority number is the left or right
        if (count(nums.begin() + left, nums.begin() + right + 1, majority_left) > count(nums.begin() + left, nums.begin() + right + 1, majority_right)) {
            return majority_left;
        } else {
            return majority_right;
        }
    }
}; 
