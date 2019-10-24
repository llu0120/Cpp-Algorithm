/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) {
        //if x < 0 or the last number of x is 0 --> these cases cannot be palidrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int num = 0; 
        int a = abs(x);
        //We only want to reverse a half
        while (a > num) {
            int tmp = a % 10;
            num = num * 10 + tmp;
            a = (int)(a / 10);
        }
        //if x is even --> num == a
        //if x is odd --> (int)(num/10) == a
        if ((num == a) || ((int)(num / 10) == a)) {
            return true;
        }
        return false;
    }
};
