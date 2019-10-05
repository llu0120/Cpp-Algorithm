/* dynamic programming 
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n+1);
        result[0] = 1; //O step of stair -> one solution 
        result[1] = 1; //1 step of stair -> one solution
        //For number of solutions to n steps the solution will be the number of solutions of (n-1) steps + the number of solutions of (n-2)
        for (int i = 2; i <= n; i++) {
            result[i] = result[i-1] + result[i-2];
        }
        return result[n];
    }
};


class Solution {
public:
    int climbStairs(int n) { 
	if (n <= 2){    //if number of stairs n smaller than 2, directly return the number because the number of stair == method
        return n;
    }
	//The number of solutions of n will be the number of solutions of (n-1) + the number of solutions of (n-2)
    else{
        int n1 = 1;
        int n2 = 2;
        for (int i=3; i<=n; i++){
            int temp = n1 + n2;     //dynamic programming using recursive to seperate 3 into 1 and 2, for example n into (n-1) and (n-2), then add them all 
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }

    }   
};
