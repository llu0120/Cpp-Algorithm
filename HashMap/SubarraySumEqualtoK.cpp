/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
//https://www.youtube.com/watch?v=aYfwus5T3Bs
//Brute force O(n^3) 
//O(n) 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Corner Case: 
        if (nums.size() == 0) {
            return 0;
        }
        //General Case: 
        unordered_map<int, int> prefixSumCount; //key: prefix sum, value: count 
        prefixSumCount[0] = 1; 
        int prefixSum = 0; 
        int result = 0; 
        for (int i = 0; i < nums.size(); i++) {
            //First calculate prefix sum in this index
            prefixSum += nums[i];
            //If the (prefixSum - k) has been value before --> means the subarray sum to k exist, add its count 
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                result += prefixSumCount[prefixSum - k];
            }
            //If the prefix sum count is already exist --> +1 , if not make its value in the map 1 
            if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
                prefixSumCount[prefixSum]++;
            } else {
                prefixSumCount[prefixSum] = 1;
            }
        }
        return result;
    }
};
