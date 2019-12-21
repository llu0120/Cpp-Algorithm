//Hash map method
/**
* Given an array of integers, remove the duplicate numbers in it.
* You should:
* Do it in place in the array.
* Move the unique numbers to the front of the array.
* Return the total number of the unique numbers.
* Example
* Example 1:
* Input:
* nums = [1,3,1,4,4,2]
* Output:
* [1,3,4,2,?,?]
* 4
* Explanation:
* Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
* Return the number of unique integers in nums => 4.
* Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.
* Example 2:
* Input:
* nums = [1,2,3]
* Output:
* [1,2,3]
* 3
* Challenge
* Do it in O(n) time complexity.
* Do it in O(nlogn) time without extra space.
* Notice
* You don't need to keep the original order of the integers.
*/



class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        vector<int> result;
        unordered_map<int,int> hash_map;
        for (int i = 0; i < nums.size();i++){
            if (hash_map.find(nums[i]) == hash_map.end()){ // if nums[i] is not in the hash_map (use hash_map.end())
                hash_map[nums[i]] == nums[i];
                result.push_back(nums[i]);
            }
        }
        nums = result; //Do it in place in the array.
        return result.size();
    }
};


//Two Pointer methode
