/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/ 
//Brute Force 
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0; 
        for (int i = 0; i < height.size(); ++i) {
            int cur = i;
            int left_max = 0; 
            int right_max = 0; 
            int left = 0; 
            int right = 0; 
            //iterate left
            for (int j = i; j >= 0; --j) {
                if (height[j] > left_max) {
                    left_max = height[j];
                    left = j; 
                }
            } 
            //iterate right
            for(int j = i; j < height.size(); ++j) {
                if (height[j]> right_max) {
                    right_max = height[j];
                    right = j; 
                }
            }
            //add the unit of water to result 
            result += min(left_max, right_max)-height[i];
        }
        return result; 
    }
};

//DP 
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int n = height.size(); 
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int maxVal = 0; 
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, height[i]);
            dp1[i] = maxVal; 

        }
        
        maxVal = 0; 
        for (int i = n-1; i >= 0; i--) { 
            maxVal = max(maxVal, height[i]); 
            dp2[i] = maxVal;
        }

        for (int i = 0; i < n; ++i) {
            result += min(dp1[i],dp2[i]) - height[i]; 
        }
        return result; 
    }
};

//Stack 
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int i = 0; 
        stack<int> st; //index 
        while (i < height.size()) {
            if (st.empty() || height[st.top()] >= height[i]) {
                st.push(i);
                i++; 
            } else {
                int low = st.top();
                st.pop();
                if (st.empty()) {
                    continue;
                }
                int left = st.top(); 
                int right = i; 
                result += (min(height[right], height[left]) - height[low]) * (right - left - 1);   
            }
        }
        return result;
    }
};
