/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        //Corner Case:
        if (needle.size() == 0) {
            return 0;
        }
        //General Case:
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        //Need to traverse the haystack string but only to the index (haystack_size - needle_size)
        for (int i = 0; i < (haystack_size - needle_size + 1); i++) {
            int j = 0;
            //Check if the needle fits the haystack
            while (j < needle_size) {
                if (haystack[i + j] != needle[j]) { //If any word didn't fit, then break the while loop
                    break;
                }
                j++;
            }
            //If the needl fits the haystack, then j will be the same as the needle size
            if (j == needle_size) {
                return i;
            }
        }
        return -1;
    }
};
