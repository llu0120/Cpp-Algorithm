/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int ptr1 = num1.size()-1;
        int ptr2 = num2.size()-1; 
        int carry = 0;
        int sum = 0;
        string result;
        while(ptr1 >= 0 || ptr2 >= 0) {
            sum = 0; 
            sum += carry ;
            if (ptr1 >= 0) {
                sum += num1[ptr1] - '0';
                ptr1--;
            }
            if (ptr2 >= 0) {
                sum += num2[ptr2] - '0';
                ptr2--;
            }         
            int digit = sum % 10; 
            carry = sum / 10; 
            result.insert(result.begin(), digit +'0');  
        }
        if (carry != 0) {
            result.insert(result.begin(), carry+'0');
        } 
        return result;
    }
};
