/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    string reorganizeString(string S) {
        string result = ""; 
        //Build hash map: key --> the character, value --> times 
        unordered_map<char, int> map; 
        for (int i = 0; i < S.size(); i++) {
            if (map.find(S[i]) == map.end()) {
                map[S[i]] = 1;
            } else {
                map[S[i]]++; 
            }
        }
        
        //Push all the pair of <times, char> into the pq 
        priority_queue<pair<int, char>> pq; 
        for (auto m: map) {
            if (m.second > (S.size()+1) / 2) {
                return result; //Cannot reorganize string 
            }
            pq.push({m.second, m.first});
        }
        
        while(pq.size() >= 2) {
            //Take two biggest times out to construct the result 
            auto tmp1 = pq.top(); 
            pq.pop(); 
            auto tmp2 = pq.top(); 
            pq.pop(); 
            result.push_back(tmp1.second); 
            result.push_back(tmp2.second); 
            
            tmp1.first--;
            tmp2.first--;
            if (tmp1.first > 0) {
                pq.push(tmp1);
            } 
            if (tmp2.first > 0) {
                pq.push(tmp2);
            }
        }
        
        //If there is still a last element inside the pq 
        if (!pq.empty()) {
            result.push_back(pq.top().second);
        }
        
        return result;
    }
};
