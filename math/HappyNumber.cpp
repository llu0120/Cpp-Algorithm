/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set; 
        while (n != 1) {
            int sum = 0;
            //Calculate the sqaure sum of each digit
            while (n != 0) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
            //If n is already exist in the set --> check this number is 1 or not to know n is a happy number or not
            if (set.find(n) != set.end()) {
                break;
            }
            set.insert(n);
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};
