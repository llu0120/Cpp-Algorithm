/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> patternMap; //Key: pattern, value: words
        unordered_map<string, bool> MapValue; //This is to prevent the two different patterns point to the same string
        //parse str into vector
        vector<string> str_vec; 
        istringstream words(str);
        for(string s; words >> s;){ //parse string method
            str_vec.push_back(s);
        }
        //Corner Case 
        if (pattern.size() != str_vec.size()) {
            return false;
        }
        //General Case:
        for (int i = 0; i < pattern.size(); i++) {
            //If the pattern already exist in the patternMap
            if (patternMap.find(pattern[i]) != patternMap.end()) {
                if (patternMap[pattern[i]] != str_vec[i]) {
                    return false; 
                }
            }
            else { //If the pattern never appears (doesn't exist in the patternMap)
                if (MapValue.find(str_vec[i]) != MapValue.end()) { //ex: if a--> dog, and the new pattern --> dog this is a false case 
                    return false;
                }
                patternMap[pattern[i]] = str_vec[i];
                MapValue[str_vec[i]] = true;
            }
        }
        return true;
    }
};
