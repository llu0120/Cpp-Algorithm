/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int s_size = s.size();
        unordered_map<int, bool> map;
        for (int i = 0; i < s_size; i++) {
            if (map.find(s[i]) != map.end()) {
                map.erase(s[i]);
            } else {
                map[s[i]] = true;
            }
        }
        int remove_size = map.size();
        //Two cases:
        //If the remove_size == 0 --> the origin string s is already a palindrome.
        //But if the remove_size > 0, The palindrome can include a "single" alphabet, so need to add one to the size of the palidrome (remove_size--)
        if (remove_size > 0) {
            remove_size--;
        }
        return (s_size - remove_size);
    }
};
