/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/ 
//Time Complexity -  n * Catalan number (n) ~ O(4n)， Space Complexity O(n2)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        vector<string> result; 
        
        generateParenthesesDFS(n, n, "", result);
        return result;
        
    }
    
    void generateParenthesesDFS(int left, int right, string output, vector<string> &result)  {
        if (left > right) { //if the number of rest of the left > the number of rest of the right --> not well-form --> )( 
            return;
        }
        if (left == 0 && right == 0) {
            result.push_back(output);
        }
        if (left > 0) {
            generateParenthesesDFS(left-1, right, output + '(', result);
        } 
        if (right > 0) {
            generateParenthesesDFS(left, right-1, output + ')', result);
        }
        
    }
};
