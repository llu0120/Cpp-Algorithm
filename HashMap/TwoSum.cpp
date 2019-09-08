//Hash Map
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        int diff;
	// initialize hash map
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i; // key ---> value
        }
	// trasversal hash map
        for (int i = 0; i < nums.size(); i++){
            diff = target - nums[i]; 
            if (map.find(diff) != map.end() && map[diff] != i){ //find if diff is in the hash map and the diff cannot be the original i
                result.push_back(i);
                result.push_back(map[diff]);
                break;
            } else {
                continue;
            }
        }
        return result;
    }
};
