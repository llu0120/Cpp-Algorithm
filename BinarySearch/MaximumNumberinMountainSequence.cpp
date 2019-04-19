//Binary Search
/* 
* Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.
* Example
* Example 1:
* Input: nums = [1, 2, 4, 8, 6, 3] 
* Output: 8
* Example 2:
* Input: nums = [10, 9, 8, 7], 
* Output: 10
*/ 

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }
        int start = 0;
        int end = len-1;
        while (start+1 < end){
            int mid = (start+end)/2;
            if (nums[mid] < nums[mid+1]){ // This means nums[mid] is still in the climbing sequence, so set start = mid
                start = mid;
            }
            else{
                end = mid;
            }
        }
        // Get two numbers after jumping out of the while loop, compare these two number and choose the larger one to be the mountain top 
        if (nums[start]>nums[end]){
            return nums[start];
        }
        else if (nums[end]>nums[start]){
            return nums[end];
        }
    }
};
