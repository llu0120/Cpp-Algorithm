/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
//Check if cycle exist 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Construct a directed graph 
        vector<int> empty; 
        vector<vector<int>> graph(numCourses, empty); //index: course, vector<int> prerequisites 
        
        //Construct a in-degree vector
        vector<int> inDegree(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            //For example [1,0] ---> first take 0 then take 1 ---> the graph is 0--->1, the indegree of node 1++ 
            //The graph representation: graph[0] = 1 
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
            for (int i = 0; i < graph[tmp].size(); i++) {
                int tmp_node = graph[tmp][i];
                inDegree[tmp_node]--;
                if (inDegree[tmp_node] == 0) {
                    q.push(tmp_node);
                }
            }
        }
        
        //If there is node with inDegree != 0 --> cycle exist  
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
