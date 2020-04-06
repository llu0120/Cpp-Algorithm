/*
Get the minimum number of operations of the matrix multiplication chain 
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int matrixChainOrder(vector<int>& matrixOrder) {
        int n = matrixOrder.size();
        vector<int> col(n, -1);
        vector<vector<int>> dp(n, col);
        
        //Initialize the (1,1), (2,2), (3,3)... to 0
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 0;
        }
        
        //Start dynamic programming
        for (int L = 2; L < n; ++L) { //Upper Triangular of the matrix
            for (int i = 1; i < n-L+1; ++i) { //(1,2), (2,3), (3,4), (4,5)
                int j = i+L-1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j-1; ++k) {
                    int tmp = dp[i][k] + dp[k+1][j] + matrixOrder[i-1] * matrixOrder[k] * matrixOrder[j];
                    if (tmp < dp[i][j]) {
                        dp[i][j] = tmp;
                    }
                }
            }
        }
        return dp[1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> matrixOrder{5, 4, 6, 2, 7};
    Solution sol;
    int result = sol.matrixChainOrder(matrixOrder);
    cout << "Total Operation: " << result << endl;
    return 0;
}

