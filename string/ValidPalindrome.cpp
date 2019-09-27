/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            //If s[start] or s[end] is not alphabet or number, jump to the next one
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            //If the lower case alphabet of s[start] and s[end], than return false
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
