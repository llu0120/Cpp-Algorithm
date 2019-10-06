/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0; 
        //If the number x is out of bound of  [−2^31,  2^31 − 1] --> return 0
        if (x >= pow(2,31) - 1 || x <= -pow(2,31)) {
            return 0;
        }
        int a = abs(x);
        while (a != 0) {
            //result = 0 and a = 123
            //result = 3 and a = 12
            //result = 32 and a = 1
            //result = 321 and a = 0
            int tmp = a % 10;
            if (abs(result) > INT_MAX / 10) {
                return 0;
            }
            result = result*10 + tmp;
            a = (int)(a / 10);
        }
        
        if (x < 0 && result <= pow(2,31)) {
            return -result;
        } else if (x > 0 && result <= pow(2,31)-1) {
            return result;
        } else { //integers over flow
            return 0;
        }
        
    }
};
