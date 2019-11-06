/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int min_diff = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        for (int i = 0; i < timePoints.size(); i++) {
            string t1 = timePoints[i];
            string t2 = timePoints[(i+1)%timePoints.size()];

            int hour1 = (int)(t1[0]) * 10 + (int)(t1[1]);
            int minutes1 = (int)(t1[3]) * 10 + (int)(t1[4]);
            int hour2 = (int)(t2[0]) * 10 + (int)(t2[1]);
            int minutes2 = (int)(t2[3]) * 10 + (int)(t2[4]);

            int minutes_diff = minutes2 - minutes1;

            int hour_diff;
            //For the case of the last and the first time: need to add 24 to the first 
            if (i == timePoints.size() - 1) {
                hour_diff = (hour2+24) - hour1;
            } else {
                hour_diff = hour2 - hour1; 
            }
            int diff = hour_diff * 60 + minutes_diff;
            min_diff = min(min_diff, diff);
        }
        return min_diff;  
    }
};
