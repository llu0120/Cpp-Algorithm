/* 
Concatenation is an operation that joins strings. For example, the  concatenation of strings "smart" and "phone" is "smartphone". Concatentation
can be exapnded to more than two strings; for example, concatenating  "co", "dil", and "ity" results in "codility".

Given an array A consisting of strings, your function should be calculate 
the length of the longest sring S such that: 
    1. S is a concatenation of some of the strings from A;
    2. every letter in S is different. 
Write a function: 
    int solution(vector<string>& A) 
that, given an array A consisting of N strings, calculates the length of the  longest string S fulfilling the conditions above. If no such string exists, 
your function should return 0. 

Examples: 
1. Given A = ["co", "dil", "ity"], your function should return 5. The resulting string S could be "codil", "coity" or "ityco".

2. Given A = ["abc", "kkk", "def", "csv"], your function should return 6. The  resulting string S could be "abcdef", "defabc", "defcsv" or "csvdef". 

3. Given A = ["potato", "kayak", "banana", "racecar"], your function should return 0.  
It is impossible to choose any of these strings as each of them contains repeating letters. 

4. Given A = ["eva", "jqw", "tyn", "jan"], your function should return 9. One of  the possible strings of this lenght is "evajqwtyn".

Assume that: 
    1. N is an integer within the range[1...8];
    2. each string in A consists of lowercase English letters; 
    3. the sum of lengths of strings in A does not exceed 100. 

In you solution, focus on correctness. The performance of your solution will not be the focus of the assessment.  
*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map> 
using namespace std;

class Solution {
    public:
        int solution (vector<string>& a) {
            //Iterate through all string, if it is self-repeated --> remove 
            vector<string> new_a;
            for (int i = 0; i < a.size(); i++) {
                if (!isRepeat(a[i])) {
                    new_a.push_back(a[i]);
                }
            }
            
            vector<bool> isVisited(new_a.size(), false);
            string result; 
            int maxLen = 0; 

            //All the string is in the map now 
            dfs(new_a, isVisited, result, maxLen);

            return maxLen; 
        }

        bool isRepeat(string a) {
            unordered_map<char, int> map; 
            for (int i = 0; i < a.size(); i++) {
                if (map.find(a[i]) == map.end()) {
                    map[a[i]] = 1; 
                } else {
                    return true;
                }
            }
            return false; 
        }

        void dfs(vector<string>& a, vector<bool>& isVisited, string result, int &maxLen) {
            //To see if all the string are visited --> if yes, maxLen will be the answer
            int count = 0; 
            for (int i = 0; i < isVisited.size(); i++) {
                if (isVisited[i]) {
                    count++;
                }
            }
            if (count == a.size()) {
                int result_size = result.size();
                maxLen = max(maxLen, result_size);
                return;
            }

            //Iterate through all the possible add candidates
            for (int i = 0; i < a.size(); i++) {
                if (isVisited[i]) continue;

                string candidate = a[i];
                //if the candidate has repeat element in the result 
                bool needAdd = true;
                for (int c = 0; c < candidate.size(); c++) {
                    if (result.find(candidate[c]) != string::npos) {
                        needAdd = false;
                    }
                } 

                string tmp_result = result;
                //if not repeat --> add to the result
                if (needAdd) {
                    for (int c = 0; c < candidate.size(); c++) {
                        result += candidate[c];
                    }
                }

                isVisited[i] = true;
                dfs(a, isVisited, result, maxLen);
                isVisited[i] = false; 
                result = tmp_result;
            }

        }

};


int main() {
    Solution sol; 
    vector<string> a = {"co", "dil", "ity"};
    int ans = sol.solution(a);
    cout << ans << endl;

    a = {"abc", "kkk", "def", "csv"};
    ans = sol.solution(a);
    cout << ans << endl;

    a = {"potato", "kayak", "banana", "racecar"};
    ans = sol.solution(a);
    cout << ans << endl;

    a = {"eva", "jqw", "tyn", "jan"};
    ans = sol.solution(a);
    cout << ans << endl;

    return 0; 
}