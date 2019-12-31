/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreak(s, wordSet);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& wordSet) {
        //If in memory, return  
        if (memory_.find(s) != memory_.end()) {
            return memory_[s]; 
        }
        //If the string s is a word in the wordSet, store in the memory and return true 
        if (wordSet.find(s) != wordSet.end()) {
            memory_[s] = true;
            return true;
        }
        //Try every break point
        for (int i = 1; i < s.size(); i++) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            //Find the solution for s
            if (wordSet.find(left) != wordSet.end() && wordBreak(right, wordSet)) {
                memory_[s] = true; 
                return true; 
            }
        }
        //If no solution s, store in the memory and return false
        memory_[s] = false; 
        return false; 
    }
    
private: 
    unordered_map<string, bool> memory_;
};
