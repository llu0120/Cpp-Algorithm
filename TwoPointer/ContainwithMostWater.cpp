/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0; 
        int right = height.size() - 1;
        while (left < right) {
            result = max(result, min(height[left], height[right])*(right-left));
            //Disgard the shorter wall to see if a heigher wall can replace this to get more water
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
