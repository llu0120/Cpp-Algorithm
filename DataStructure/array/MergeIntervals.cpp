/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/ 
//O(nlogn) --> because of the sort 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        //Default: sort the first column in the vector of vectors
        //I can write the below in this problem because we want to sort the every first number in the vector
        //sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; } );
        vector<vector<int>> result{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] < intervals[i][0]) { //If the second number of the interval in the result is smaller than the first number of the next interval --> This is a new interval.
                result.push_back(intervals[i]);
            } else { //This means overlapped we need to determine the second number of this interval by taking the maximum of the second number of the interval in the result or the second number in the next interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};
