/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        //Initialize the priority queue to make the smallest value at the front
        priority_queue<int, vector<int>, greater<int>> heap;
        //Push the end time into the heap 
        heap.push(intervals[0][1]);
        //Store all the end time into the heap and if the end time on the top is bigger than the new interval --> need to directly push a new interval(room) into the heap
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= heap.top()) {
                heap.pop();
                heap.push(intervals[i][1]);
            } else {
                heap.push(intervals[i][1]);
            }
        }
        return heap.size();
    }
};

