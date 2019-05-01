/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Example
Example 1:

Input：[4, 5, 6, 7, 0, 1, 2]
Output：0
Explanation：
The minimum value in an array is 0.
Example 2:

Input：[2,1]
Output：1
Explanation：
The minimum value in an array is 1.
Notice
You can assume no duplicate exists in the array.
*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int start = 0; 
        int end = nums.size() - 1; 
        while (start + 1 < end){
            int mid = (start + end) / 2;
            if (nums[start] < nums[end])   //If nums[start] < nums[end], this means the array is well sorted, didn't rotate. 
                return nums[start];
                
            if (nums[mid] > nums[start]){    //If nums[mid] > nums[start], this means the rotated sorted array is at the back of nums[mid], so the minimum will be behind nums[mid], so move start to the mid.  
                start = mid;
            }
            if(nums[mid] < nums[start]){    //If nums[mid] < nums[start], this means the nums[mid] is in the sorted array so move end to the mid. 
                end = mid;
            }
        }
        if (nums[end] < nums[start])
            return nums[end];
        if (nums[end] > nums[start])
            return nums[start];
    }
};
