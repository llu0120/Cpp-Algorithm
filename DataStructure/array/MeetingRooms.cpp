/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/ 

//brute force O(n^2) 
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                //The condition that the person can attend both meetings
                if ((intervals[j][0] >= intervals[i][1]) || (intervals[j][1] <= intervals[i][0])) {
                        continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

//Sort O(nlogn)
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //sort with the start time in each interval
        sort(intervals.begin(), intervals.end());
        //sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};
