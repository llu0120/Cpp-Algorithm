/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result; 
        int n = nums.size(); 
        //Corner Case:
        if (n == 0) {
            return result; 
        }
        //General Case:
        int start = 0; 
        for (int i = 1; i < n; i++) {
            if (nums[i] - 1 != nums[i-1]) {
                if (i - 1 == start) {
                    result.push_back(to_string(nums[start]));
                } else {
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i; 
            }
        }
        //To see if the start is at the last number 
        //if yes --> add the last number to the end 
        //if no --> add the last interval from start to the end 
        if (start == n - 1) {
            result.push_back(to_string(nums[start]));
        } else {
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[n-1]));
        }
        return result;
    }
        
};

