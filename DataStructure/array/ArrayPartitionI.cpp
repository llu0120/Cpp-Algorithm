/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
1. n is a positive integer, which is in the range of [1, 10000].
2. All the integers in the array will be in the range of [-10000, 10000].
*/
//O(n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int result = 0; 
        //To make the sum of each min(ai,bi) the largest, I need to make each pair of number as close as possible and pick the smaller one to add to result.

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }
};
