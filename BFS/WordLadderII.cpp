/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result; 
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        //Corner Case: 
        if (wordDict.find(endWord) == wordDict.end()) {
            return result;
        }
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        
        //General Case: 
        queue<string> q; 
        q.push(beginWord);
        int wordLen = beginWord.size(); 
        int step = 1;
        bool found = false; 
        
        //A dictionary for the node and it's parents
        unordered_map<string, vector<string>> parents;
        
        //A dictionary for the node and the shortest step to the node 
        unordered_map<string, int> steps{{beginWord, 1}};
        
        while (!q.empty()) {
            step++;
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                string wordNow = q.front(); 
                q.pop();
                const string wordNow_copy = wordNow;  //Deep copy of wordNow
                for (int i = 0; i < wordLen; i++) {
                    //Store the char temp 
                    const char tmp = wordNow[i];
                    for (int j = 'a'; j <= 'z'; j++) {     //Iterate through a~z (26)
                        wordNow[i] = j;
                        //If find the endWord
                        if (wordNow == endWord) {
                            parents[wordNow].push_back(wordNow_copy); 
                            found = true; 
                        } else {
                            //not a new word --> add new parent if the step is the same (different transform)
                            if (steps.find(wordNow) != steps.end() && step + 1 == steps[wordNow]) {
                                parents[wordNow].push_back(wordNow_copy);
                            }
                        }
                        //If not in the dict 
                        if (wordDict.find(wordNow) == wordDict.end()) {
                            continue;
                        }
                        
                        //New word
                        wordDict.erase(wordNow);
                        q.push(wordNow);
                        steps[wordNow] = step + 1; 
                        parents[wordNow].push_back(wordNow_copy);
                    }
                    wordNow[i] = tmp;  
                }
            }
            if (found) {
                break;
            }
        }
        
        if (found) {
            vector<string> current{endWord};
            dfsGetPath(endWord, beginWord, parents, current, result);
        }
        return result;
    }
    
    void dfsGetPath(string& word, string& beginWord, unordered_map<string, vector<string>>& parents, 
                    vector<string>& current, vector<vector<string>>& result) {
        //Means find the path
        if (word == beginWord) {
            result.push_back(vector<string>(current.rbegin(), current.rend()));
            return;
        }
        
        for (string s : parents[word]) {
            current.push_back(s);
            dfsGetPath(s, beginWord, parents, current, result);
         	//Recover to the prev state to prepare for next dfsGetPath
		    current.pop_back();
        }
    }
     
};
