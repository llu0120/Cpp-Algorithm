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
    unordered_map<int,int> hash_map;
    vector<int> result;
    // initialize hash map
    for (int i = 0; i < nums.size(); i++){
        hash_map[nums[i]] = i; // key ---> value
    }
    // trasversal hash map
    for (int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
        if (hash_map.count(diff) && hash_map[diff] != i){ //find if diff is in the hash map and the diff cannot be the original i
            result.push_back(i);
            result.push_back(hash_map[diff]);
            break;
        }
    }
    return result;
    }
                             
};
