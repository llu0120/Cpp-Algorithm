/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/ 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result; 
        
        vector<int> empty;
        vector<vector<int>> graph(numCourses, empty);
        vector<int> inDegree(numCourses, 0); 
        //Construct graph 
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        queue<int> q; 
        //Push all the node that has inDegree == 0 
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int tmp = q.front(); 
            q.pop(); 
            //If the traverse a new connected point --> inDegree--;
            result.push_back(tmp);
            for (int i = 0; i < graph[tmp].size(); i++) {
                int tmp_node = graph[tmp][i];
                inDegree[tmp_node]--;
                if (inDegree[tmp_node] == 0) {
                    q.push(tmp_node);
                }
            }
            
        }
        
         //If there is node with inDegree != 0 --> cycle exist --> clear result and return empty vector
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] != 0) {
                result.clear(); 
                return result; 
            }            
        }
        return result;
    }
};
