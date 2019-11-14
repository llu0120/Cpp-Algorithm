/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
//See Combination.cpp 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result; 
        //Corner Case: 
        if (digits.size() == 0) {
            return result;
        }
        //General Case: 
        string out; 
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //the index is the phone number , value is the possible letter correspond to the number
        letterCombinationDFS(digits, dict, 0, out, result);
        return result;
    }
    
    void letterCombinationDFS(string digits, vector<string>& dict, int level, string out, vector<string>& result) {
        if (level == digits.size()) {
            result.push_back(out);
            return; 
        }
        string str = dict[digits[level] - '0']; 
        
        for (int i = 0; i < str.size(); i++) { //Iterate over every possible letter
            letterCombinationDFS(digits, dict, level+1, out+str[i], result);
        }
    }
    
};
