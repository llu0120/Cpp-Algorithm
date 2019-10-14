/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/ 
//O(n)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num_size = digits.size();
        for (int i = num_size - 1; i >= 0; i--) {
            if (digits[i] == 9) { //If the last digits is 9 --> make it into 0 and +1 to the next iteration digits[i]
                digits[i] = 0;
            } else { //If the last digits is not 9 --> the last digits+1 and return the digits
                digits[i]++;
                return digits;
            }
        }
        if (digits[0] == 0) { //After adding one to the number if the first digit is 0 --> insert a 1 in the beginning of the number
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
}; 
