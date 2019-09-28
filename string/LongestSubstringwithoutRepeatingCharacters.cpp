/*
O(n), hash_map, sliding window
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0; 
        int left = -1;
        int size_s = s.size();
        unordered_map<int, int> map;
        for (int i = 0; i < size_s; i++) {
            //The character is in the unordered_map (appeared before)
            if (map.find(s[i]) != map.end() && map[s[i]] > left) { 
                //Check the character is exist in the unordered_map: map.find(s[i]) != map.end()
                //Check the existed character in the unordered_map index is in the sliding window or not: map[s[i]] > left
                left = map[s[i]];
            }
            //The character is not in the unordered_map (first appear)
            map[s[i]] = i; //Save the index of the first appear character(key)
            result = max(result, i - left); //Compute the length of the sliding window is bigger than before or not.
        }
        return result;
            
    }
};
