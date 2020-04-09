/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
//https://www.youtube.com/watch?v=ScCg9v921ns
//Binary Search 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        //Ensure n1 is smaller than n2 
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        //Start finding the boundary of each array
        int n = n1 + n2; 
        int start_n1 = 0;
        int end_n1 = n1; 
        double l1, l2, r1, r2; 
        while (start_n1 <= end_n1) {
            int cut1 = (start_n1 + end_n1) / 2; 
            int cut2 = (n+1) / 2 - cut1; 
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            r1 = (cut1 == n1) ? INT_MAX : nums1[cut1]; 
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
			//Unsuccessful partition
			if (l1 > r2) {
                end_n1 = cut1-1; 
            } else if (l2 > r1) {
                start_n1 = cut1+1; 
            }

  			//This means successful partition           
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2; 
                } else {
                    return max(l1, l2);
                }
            }
        }
        return -1; 
    }
}; 
//Brute Force 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums; 
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        int n_total = n1 + n2; 
        int ptr1 = 0;
        int ptr2 = 0; 
        while (ptr1 < n1 && ptr2 < n2) {
            if (nums1[ptr1] > nums2[ptr2]) {
                nums.push_back(nums2[ptr2]); 
                ptr2++;
            } else {
                nums.push_back(nums1[ptr1]);
                ptr1++; 
            }
        }
        while (ptr1 < n1) {
            nums.push_back(nums1[ptr1]);
            ptr1++;
        }
        while (ptr2 < n2) {
            nums.push_back(nums2[ptr2]); 
        }
        return nums[n_total/2];
    }
};
