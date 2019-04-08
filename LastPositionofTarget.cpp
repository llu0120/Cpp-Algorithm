//Binary Search
//Find the last position of a target number in a sorted array. Return -1 if target does not exist.
//Example
//Example 1:
//Input: nums = [1,2,2,4,5,5], target = 2
//Output: 2
//Example 2:
//Input: nums = [1,2,2,4,5,5], target = 6
//Output: -1



class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target){
        // write your code here
        int len = nums.size();
        if (len == 0){          //if len of nums is zero, then target doesn't exist
            return -1;
        }
        if (target < nums[0] || target > nums[len-1]){ //if target is smaller than the first number or bigger than the last number, then target doesn't exist
            return -1;
        }
        
        int start = 0, end = len - 1;
        while (start + 1 < end){        //binary search
            int mid = (start + end) / 2;
            if (target < nums[mid]){
                end = mid;
            }
            else if(target > nums[mid]){
                start = mid;
            }
            else{
                start = mid;
            }
        } // there will be two numbers at last, a start and an end
        
        if (nums[end] == target){
            return end;
        }
        else if (nums[start] == target){
            return start;
        }
        else{
            return -1;
        }
        
    }
