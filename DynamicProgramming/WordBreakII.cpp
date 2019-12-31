/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreak(s, wordSet);
    }
    
    //Add the word to the result 
    vector<string> resultAdd(const vector<string>& original, const string& needAppend) {
        vector<string> result; 
        for (int i = 0; i < original.size(); i++) {
            result.push_back(original[i] + " " + needAppend);
        }
        return result; 
    }
    
    vector<string> wordBreak(const string& s, const unordered_set<string>& wordSet) {
        //If in memory, return 
        if (memory_.find(s) != memory_.end()) {
            return memory_[s];
        }
        
        //Store the solution of s 
        vector<string> result;
        
        //If the string s is a word in the wordSet, store in the memory
        if (wordSet.find(s) != wordSet.end()) {
            result.push_back(s);
        }
        
        //Try every break point 
        for (int i = 1; i < s.size(); i++) {
            //Check if left part is a word
            const string right = s.substr(i);
            if (wordSet.find(right) == wordSet.end()) {
                continue; 
            }
            const string left = s.substr(0, i);
            vector<string> left_ans = resultAdd(wordBreak(left, wordSet), right);
            result.insert(result.end(), left_ans.begin(), left_ans.end());
        }
        memory_[s].swap(result);
        return memory_[s];
    }
private: 
    unordered_map<string, vector<string>> memory_; 
};
