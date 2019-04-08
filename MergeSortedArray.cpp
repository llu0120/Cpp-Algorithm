//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//Note:
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//Example:
//Input:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//Output: [1,2,2,3,5,6]



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pointer1 = m-1;
    int pointer2 = n-1; 
    int l = m + n - 1;
    while (pointer1>=0 && pointer2>=0){
        if (nums1[pointer1] >= nums2[pointer2]) {
            nums1[l] = nums1[pointer1];
            pointer1 --;
            l--;
            continue;
        }
        if (nums2[pointer2] > nums1[pointer1]) {
            nums1[l] =nums2[pointer2];
            pointer2 --;
            l --;
            continue;
        }
    }
    //if the while loop didn't iterate any time, then check nums2 is been append into num1 or not
    while (pointer2 >=0) {
        nums1[l] = nums2[pointer2];
        pointer2 --;
        l--;
    }

    
    
    
    }
};
