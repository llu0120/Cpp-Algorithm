/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

//Naive solution 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        
        return nums[k-1];
    }
};

//Heap solution 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); 
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
            
        }
        return pq.top();
    }
};

//quick select https://www.cnblogs.com/grandyang/p/4539757.html 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0; 
        int right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k-1) {
                return nums[pos];
            } else if (pos > k-1) {
                right = pos - 1; 
            } else {
                left = pos + 1; 
            }
            
        }
        
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1; 
        int r = right; 
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++; 
                r--;
            }
            
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[r], nums[left]);
        return r; 
    }
};
