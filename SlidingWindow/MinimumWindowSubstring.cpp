/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
//Time: O(n) for traversing all the character in s, Space: O(n) for storing all target in the map

//https://www.youtube.com/watch?v=9qFR2WQGqkU
class Solution {
public: 
    string minWindow(string s, string t) {
        //Corner Case: 
        if (s.size() < t.size()) {
            return "";
        }
        //General Case: 
        //Construct word dictionary in T        
        unordered_map<char,int> map = constructTargetDict(t);
        //Start matching
        int slow = 0; 
        int match_count = 0; 
        int min_len = INT_MAX; 
        int substring_start = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            char cur_char = s[fast];
            //If cur_char is not in the target map --> directly move fast pointer forward and continue to next iteration
            if (map.find(cur_char) == map.end()) {
                continue;
            }
            
            //If cur_char is in the target map --> target map value-- and if equals to 0, this means the character has been match --> match_count++
            if (map.find(cur_char) != map.end()) {
                map[cur_char]--;
                if (map[cur_char] == 0) { //how many times the character needs to be matched --> if 0 --> match_count++
                    match_count++;
                }
            }
            //If the match_count is the same as the target --> found a valid string --> make the sliding window smaller 
            while (match_count == map.size()) {
                //Update the length and the start index of the valid string
                if (fast - slow + 1 < min_len) { //ex: slow = 0, fast = 5 --> the length will be 6 = 5 - 1 + 1
                    min_len = fast - slow + 1;
                    substring_start = slow; 
                }
                char left_most = s[slow];
                //if the left most character is not in the target map --> directly make the sliding window smaller
                if (map.find(left_most) == map.end()) {
                    slow++;
                    continue;
                }
                //if the character is in the target map --> the string will be unvalid --> match_count--
                map[left_most]++;
                if (map[left_most] == 1) {
                    match_count--;
                }
                slow++;
            }
            
        }
        //If the min_len didn't change at all --> doesn't exist a substring that includes all the target
        if (min_len == INT_MAX) {
            return "";
        }

        return s.substr (substring_start, min_len); //substr(index, len)
    }
    
    unordered_map<char,int> constructTargetDict(string t){
        //Construct word dictionary in T
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++) {
            if (map.find(t[i]) == map.end()) {
                map[t[i]] = 1;
            } else {
                map[t[i]]++;
            }
        }
        return map;
    }
};
