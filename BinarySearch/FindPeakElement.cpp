//Binary Search
/*
There is an integer array which has the following features:
The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peak if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

Example
Example 1:
	Input:  [1, 2, 1, 3, 4, 5, 7, 6]
	Output:  1 or 6
	
	Explanation:
	return the index of peek.


Example 2:
	Input: [1,2,3,4,1]
	Output:  3

Challenge
Time complexity O(logN)

Notice
It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        // write your code here
        int len = A.size();
        int start = 0;
        int end = len -1; 
        while (start + 1 < end){
            int mid = (start + end) / 2;
            if (A[mid] > A[mid + 1] && A[mid] > A[mid-1]) return mid; //mid already is the peak, then return mid
            if (A[mid] < A[mid + 1])  // still in the climbing sequence
                start = mid; 
            else
                end = mid;
        }
        // The while will have two numbers, so the bigger one will be the peak 
        if (A[start] > A[end])
            return start;
        if (A[start] < A[end])
            return end;
    }
};
