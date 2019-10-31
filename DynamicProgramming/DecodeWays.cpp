/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    unordered_map<string,int> m_ways;
    
    int numDecodings(string s) {
        //Corner Case: 
        if (s.size() == 0) {
            return 0; 
        }
        //The string is empty --> don't need to decode = 1
        m_ways[""] = 1;
        return waysCounter(s);
    }
    
    int waysCounter(string s) {
        //If the count of certain string exists --> directly use it 
        if (m_ways.find(s) != m_ways.end()) {
            return m_ways[s];
        }
        //If the first element of the string is 0 --> meaningless code 
        if (s[0] == '0') {
            return 0;
        }
        //If there is only one element left --> return 1 for 1 way 
        if (s.size() == 1) {
            return 1;
        }
        
        //Take the substr with 1 or 2 element 
        int wayCount = 0;
        int count1 = waysCounter(s.substr(1)); // This means the substring will start from index 1 to the end 
        wayCount += count1;
        
        int first2ele = stoi(s.substr(0,2)); //This means the substring will start from 0 with the length 2 
        //See if the first 2 element is a number that can encoded to an alphabet
        if (first2ele <= 26) {
            int count2 = waysCounter(s.substr(2)); // This means the substring will start from index 2 to the end
            wayCount += count2;
        }
        m_ways[s] = wayCount; 
        
        return wayCount;
    }
};
