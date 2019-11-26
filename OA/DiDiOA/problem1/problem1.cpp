//Because of the incorrect implementation of find_min: 
//Generate the counter example of the find_min function by writing a function.

#include <iostream> 
#include <vector> 
using namespace std; 

int find_min(vector<int>& A) {
    int ans = 0; 
    for (int i = 0; i < A.size(); i++) {
        if (ans > A[i]) {
            ans = A[i];
        }
    }
    return ans; 
} 

class Solution {
    public: 
        vector<int> solution1(int N) {
            vector<int> counterExample;
            for (int i = 0; i < N; i++) {
                counterExample.push_back(i+1); 
            }
            return counterExample;
        }
        vector<int> solution2(int N) {
            vector<int> counterExample;
            for (int i = 0; i < N; i++) {
                counterExample.push_back(abs(rand())); 
            }
            return counterExample;
        }
};

int main() {
    //test case
    vector<int> a = {4, 2, 4, 5};
    int ans = find_min(a);
    cout << ans << endl;

    //Generate Counter Example 
    int N = 4; 
    Solution sol; 
    vector<int> counterExample = sol.solution2(N);
    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << counterExample[i] << endl;
        } else {
            cout << counterExample[i] << ", ";
        }
    }
    
    //Test Counter Example 
    int ans_counter = find_min(counterExample);
    cout << ans << endl;

    return 0; 
}