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
