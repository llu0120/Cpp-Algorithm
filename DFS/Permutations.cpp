/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//https://www.youtube.com/watch?v=KukNnoN-SoY&t=891s
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        //Corner Case: 
        if (nums.size() == 0) {
            return result;
        }
        
        //General Case:
        int level = 0; 
        vector<int> visited(nums.size(), 0);
        vector<int> out; 
        permuteDFS(nums, level, visited, out, result);
        return result;
    }
    
    void permuteDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& result) {
        //Traverse to the last level --> means this is one of the permutation result
        if (level == nums.size()) {
            result.push_back(out);
        }
        
        //Traverse each possible number that can add to the permutation result
        for (int i = 0; i < nums.size(); i++) {
            //if visited --> continue
            if (visited[i] == 1) {
                continue;
            }
            visited[i] = 1; 
            
            out.push_back(nums[i]);
            permuteDFS(nums, level + 1, visited, out, result);
            
            //after passing in the new visited and out list, pop_back the list and set visited[i] = 0 to getback to the upper level
            out.pop_back();
            visited[i] = 0;
        }
    }
};
