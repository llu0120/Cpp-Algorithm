/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

1. S will have length in range [1, 500].
2. S will consist of lowercase letters ('a' to 'z') only.

*/ 


class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m; 
        vector<int> result; 
        
		//Construct char last position map 
		for (int i = 0; i < S.size(); ++i) {
            m[S[i]] = i; 
        }
		
		//Two Pointers interate 
        int start = 0; 
        int last = 0; 
        for (int i = 0; i < S.size(); ++i) {
            last = max(m[S[i]], last); 
            if (last == i) {
                string tmp = S.substr(start, i-start+1); 
                result.push_back(tmp.size());
                start = i+1; 
            }
        }
        return result; 
    }
};
