/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        //Corner Case: 
        if (wordDict.find(endWord) == wordDict.end()) {
            return 0;
        }
        
        //General Case: 
        queue<string> q; 
        q.push(beginWord);
        int wordLen = beginWord.size(); 
        int result = 1; 
        
        while (!q.empty()) {
            result++; //To the next level --> result + 1
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                string wordNow = q.front(); 
                q.pop();
                for (int i = 0; i < wordLen; i++) {
                    //Store the char temp 
                    char tmp = wordNow[i];
                    for (int j = 'a'; j <= 'z'; j++) {     //Iterate through a~z (26)

                        wordNow[i] = j;
                        //If find the endWord
                        if (wordNow == endWord) {
                            return result++;    
                        }
                        //If not in the dict 
                        if (wordDict.find(wordNow) == wordDict:.end()) {
                            continue;
                        }
                        wordDict.erase(wordNow);
                        q.push(wordNow);
                    }
                    wordNow[i] = tmp; 
                    }
                }
            }
            return 0;
        }
};
