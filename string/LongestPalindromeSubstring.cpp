/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int s_size = s.size();
        //Corner Case: 
        if (s_size < 2) {
            return s;
        } 
        //General Case:
        string longest = "";
        for (int i = 0; i < s_size; i++) {
            string substring = findPalindrome(s, i, i); //For palidrome with size is odd number
            if (longest.size() < substring.size()) {
                longest = substring;
            } 
            substring = findPalindrome(s, i, i+1); //For palidrome with size is even number
            if (longest.size() < substring.size()) {
                longest = substring; 
            }
        }
        return longest;
    }
    
    string findPalindrome(string s, int left, int right) {
        int s_size = s.size();
        while (left >= 0 && right < s_size && s[left] == s[right]) { 
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1); //s.substr(pos,len)
    }
};
