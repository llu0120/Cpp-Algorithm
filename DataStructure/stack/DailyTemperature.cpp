/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/ 

//Stack O(n) 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size(); 
        vector<int> result(n, 0);
        stack<pair<int, int>> s; //pair<int, int> index value 
        s.push(make_pair(T[n-1], 0)); 
        
        for (int i = n - 2; i >= 0; --i) {
            int counter = 1; 
            //Keep popping until T[i] < s.top().first(temperature)
            while (!s.empty() && T[i] >= s.top().first) {
                counter += s.top().second; 
                s.pop(); 
            }
            if (s.empty()) {
                s.push(make_pair(T[i], 0));           
            } else {
                s.push(make_pair(T[i], counter));
                result[i] = counter; 
            }
            
        }
        return result;
    }
};

//Brute Force 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            int cur = T[i];
            int j = i+1; 
            while (j < T.size()) {
                if (T[i] < T[j]) {
                    result[i] = j - i;
                    break; 
                } 
                ++j;
            }
        }
        return result;
    }
};
