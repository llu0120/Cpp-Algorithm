/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

//See problem 46. Permutations
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result; 
        vector<int> out; 
        combinationDFS(n, k, 1, out, result);
        return result;
    }
    
    void combinationDFS(int n, int k, int level, vector<int>& out, vector<vector<int>>& result) {
        //if the size of out is the same as k --> this is one of the combination result
        if (out.size() == k) {
            result.push_back(out);
        }        
        //Traverse the number behind the level
        for (int i = level; i <= n; i++) {
            out.push_back(i); 
            combinationDFS(n, k, i + 1, out, result);
            
            //Remember to pop out the last one to goback to the last level 
            out.pop_back();
        }
    }
};
