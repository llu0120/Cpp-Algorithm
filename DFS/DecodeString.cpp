/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
//induce the 2nd example to understand the algorithm

//Iterative
class Solution {
public:
    string decodeString(string s) {
        stack<string> str_stack;
        stack<int> num_stack;
        string current;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                //loop over the digits till "["
                int start = i; 
                while (i < s.size() && isdigit(s[i])) {
                    i++;
                }
                int num = stoi(s.substr(start, i-start));
                num_stack.push(num);
                str_stack.push(current);
                current ="";
            } else if (s[i] == ']') {
                int num = num_stack.top();
                string tmp = current; 
                for (int i = 0; i < num-1; i++) { //Don't need to loop to num because the original current already includes one set of string
                    current += tmp;
                }
                num_stack.pop();
                current = str_stack.top() + current;
                str_stack.pop();
            } else {
                current.push_back(s[i]);
            }
            
        }
        return current;
    }
};

//Recursive
//Take 3[a]2[bc] to understand the code 
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(pos, s);
    }
    
    string dfs(int &pos, string s) {
        int num = 0;
        string current = "";
        while (pos < s.size()) {
            if (isdigit(s[pos])) {
                int start = pos; 
                while (pos < s.size() && isdigit(s[pos])) {
                    pos++;
                }
                num = stoi(s.substr(start, pos-start)); 
            } else if (s[pos] == '[') {
                pos++;
                string tmp = dfs(pos, s);
                for (int i = 0; i < num ; i++) {
                    current += tmp;
                }
            } else if (s[pos] == ']') {
                pos++;
                return current;
            } else {
                current.push_back(s[pos]);
                pos++;
            }
        }
        return current;
    }
    
};
