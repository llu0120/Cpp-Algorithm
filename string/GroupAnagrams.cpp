/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/ 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; 
        unordered_map<string, vector<string>> wordMap;
        for (int i = 0; i < strs.size(); i++) {
            string cur_str = strs[i];
            sort(cur_str.begin(), cur_str.end()); //sort every string and make it into the key of the unordered_map
            wordMap[cur_str].push_back(strs[i]);
        }
        
        /* Traverse the unordered_map
        //There are 2 method to traverse the unordered_map
        for (auto a : wordMap) { 
            result.push_back(a.second);
        }
        */
        
        //for(unordered_map<key,T>::iterator iter = wordMap.begin();iter!=wordMap.end();iter++) {
        for(auto iter = wordMap.begin(); iter!=wordMap.end(); iter++) {
            result.push_back(iter->second);
        }
        //cout<<"key value is"<<iter->first<<" the mapped value is "<< iter->second;
            

        return result;
    }
};
