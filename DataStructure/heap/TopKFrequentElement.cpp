/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/ 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result; 
  		//Construct the correspondence between element and frequency of the nums
        unordered_map<int ,int> map; //key: element, value: frequency 
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1; 
            } else {
                map[nums[i]]++; 
            }
        }
		//put the pair<frequency, key> in the heap 
        priority_queue<pair<int, int>> pq;
        for (auto it: map) {
            pq.push({it.second, it.first});
        }
        
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
