/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/ 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k); 
        //Build frequency and word correspondence 
        unordered_map<string, int> map; //key: word, value: frequency 
        for (int i = 0; i < words.size(); i++) {
            if (map.find(words[i]) == map.end()) {
                map[words[i]] = 1; 
            } else {
                map[words[i]]++;
            }
        }
        //add to heap
        //Self define compare into priority queue 
        
        /*
        auto compare = [](pair<string, int>&a, pair<string, int>&b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first); //less
        };
        */
        //priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> pq(compare);

        struct cmp {
            bool operator()(pair<string, int>&a, pair<string, int>&b) {
                return a.second < b.second || (a.second == b.second && a.first > b.first); //less;
            }
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

        for (auto m: map) {
            pair<string, int> tmp_element{m.first, m.second};
            pq.push(tmp_element);
        }
        
        //find k biggest frequency 
        for (int i = k; i > 0; i--) {
            pair<string, int> tmp = pq.top();
            pq.pop();
            result[k-i] = tmp.first; 
        }
        return result; 
    }
};
