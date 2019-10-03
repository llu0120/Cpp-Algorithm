/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Add numbers from the back 
        //m is the size of nums1, n is the size of nums2
        int n1_ptr = m - 1; //last number index in nums1
        int n2_ptr = n - 1; //last number index in nums2
        int result_ptr = m + n - 1; //result index which is the length of nums1 + nums2 - 1
        while (n1_ptr >= 0 && n2_ptr >= 0) {
            if (nums1[n1_ptr] > nums2[n2_ptr]) {
                nums1[result_ptr] = nums1[n1_ptr];
                n1_ptr--;
                result_ptr--;
            } else {
                nums1[result_ptr] = nums2[n2_ptr];
                n2_ptr--;
                result_ptr--;
            }
        }
        //if m > n (nums2 will finish earlier than nums1), the return nums1 will still be correct because it is already sorted
        //if n > m, we will need to add all the element in nums2 to until finished
        while (n2_ptr >= 0) {
            nums1[result_ptr] = nums2[n2_ptr];
            n2_ptr--;
            result_ptr--;
        }
        return;
    }
};


