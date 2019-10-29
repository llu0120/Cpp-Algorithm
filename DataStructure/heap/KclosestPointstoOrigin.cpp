/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //Originally the priority queue will pop out the largest value if I program like 
        //priority_queue<vector<int>>
        //The three member in this priority queue is: 
        //1. the type of element in the queue, 
        //2. the type of the container
        //3. the comparison type of the element
        //This will make the priority queue pop out a vector with the smallest first element in the vector
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq; 
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist,i});
        }    
        vector<vector<int>> result;
        while(K > 0) {
            result.push_back(points[pq.top()[1]]);
            pq.pop();
            K--;
        }
        return result;
    }
        
};
