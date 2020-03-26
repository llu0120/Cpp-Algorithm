/*
Write a function solution that, given an interger N, returns th maximum possible value obtained  
by inserting one '5' digit inside the dcimal representation of integer N. 
Examples:
1. Given N = 268, the function should return 5268.
2. Given N = 670, the function should return 6750.
3. Given N = 0, the function should return 50.
4. GIven N = -999, the function should return -5999.

Assume that: 
N is an integer within the range [-8000, 8000].

In your solution, focus on correctness. The performance of your solution will not be the focuss of the assessment. 
*/

#include <iostream> 
#include <string> 
using namespace std;

int solution(int N) {
    string tmp = to_string(N);
    string result; 
    if (N >= 0) {
        for (int i = 0; i < tmp.size(); i++) {
            int cur = tmp[i] - '0';
            if (cur < 5) {
                string str1 = tmp.substr(0, i) + '5';
                int pos = tmp.find(tmp[i]);
                string str2 = tmp.substr(pos); 
                str1 += str2; 
                result = str1; 
                break; 
            } 
        }
    } else { //N < 0
        for (int i = 1; i < tmp.size(); i++) {
            int cur = tmp[i] - '0';
            if (cur > 5) {
                string str1 = tmp.substr(0, i) + '5';
                int pos = tmp.find(tmp[i]);
                string str2 = tmp.substr(pos);
                str1 += str2; 
                result = str1; 
                break;
            }
        }
    }
    
    return atoi(result.c_str());
}

int main() {
    int ans = solution(268);
    cout << ans << endl;

    ans = solution(670);
    cout << ans << endl;

    ans = solution(0);
    cout << ans << endl;

    ans = solution(-999);
    cout << ans << endl;

    return 0; 
}