/*
Given target, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

Example
Example 1:

Input: A = [1, 2, 3], target = 2, k = 3
Output: [2, 1, 3]
Example 2:

Input: A = [1, 4, 6, 8], target = 3, k = 3
Output: [4, 1, 6]
Challenge
O(logn + k) time

Notice
The value k is a non-negative integer and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^410
​4
​​ 
Absolute value of elements in the array will not exceed 10^410
​4
​​ 
*/


class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        //Find the  two numbers on the two sides of the target
        int start = 0;
        int end = A.size();
        vector <int> result;
        while (start + 1 < end){
            int mid = (start + end) / 2; 
            if (A[mid] < target){
                start = mid; 
            }
            else{
                end = mid; 
            }
        }
        int left = start; 
        int right = end; 
						
        while (k > 0){		// Until k is 0 ---> find all closest elements
            if (left >= 0 && right <= A.size() - 1){ //If there still have lefter number and there still have righter numbers. Compare the absolute value to see the right is nearer or right is nearer 
                if (abs(A[right] - target) < abs(A[left] - target)){
                    result.push_back(A[right]);
                    right++;
                    k--;
                } 
                else{ //(abs(A[right] - target) > abs(A[left] - target))
                    result.push_back(A[left]);
                    left--;
                    k--;
                }
            }
            else if (left < 0 && right <= A.size() - 1){		// If there doesn't have any number left, but still have righter number, then directly add A[right] in the result array. 
                result.push_back(A[right]);
                right++;
                k--;
            }
            else{												//If there doesn;t have any number right, but still have lefter number, then directly add A[left] in the result array. 
                result.push_back(A[left]);
                left--;
                k--;
            }
        }
        return result;
            
        
    }
};
