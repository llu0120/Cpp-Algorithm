/* 
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

1. 0 <= logs.length <= 100
2. 3 <= logs[i].length <= 100
3. logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/ 

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result; 
        vector<pair<string,string>> letterLogs; 
        vector<string> digitLogs; 
    	//Seperate Letter Logs and Digit Logs     
		for (int i = 0; i < logs.size(); ++i) {
            string word = logs[i];
            for (int j = 0; j < word.size(); ++j) {
                if (isalpha(word[j])) {
                    continue; 
                }
                if (word[j] == ' ') {
                    j++;
                    if (isalpha(word[j])) {
                        letterLogs.push_back(make_pair(logs[i].substr(0,j), logs[i].substr(j)));
                    } else {
                        digitLogs.push_back(logs[i]);
                    }
                    break; 
                }
            }
        }
        //Letter log need to sort
        struct cmp {
            bool operator()(pair<string,string>&a, pair<string, string>&b) {
                if (a.second == b.second) {
                    return a.first < b.first; 
                } else {
                    return a.second < b.second;
                }
            }
        };
        sort(letterLogs.begin(), letterLogs.end(), cmp()); 
        //Digit log don't need to sort 
        
        for (int i = 0; i < letterLogs.size(); ++i) {
            result.push_back(letterLogs[i].first + letterLogs[i].second); 
        }
        for (int i = 0; i < digitLogs.size(); ++i) {
            result.push_back(digitLogs[i]);
        }
        return result; 
    }
};
