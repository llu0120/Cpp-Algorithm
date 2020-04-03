/*
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result; 
        
        //Save the graph in to map: key: node, value: vector of neighbor nodes
        unordered_map<int, vector<int>> m; 
        for (auto c: connections) {
            m[c[0]].push_back(c[1]);
            m[c[1]].push_back(c[0]);
        }
        
        vector<int> jump(n, -1); 
        
        dfs(0, -1, 0, jump, result, m);
        return result;
    }
    
    /*
    Starting from the current node, explore all the node connecting to this node except its parent, and return the minum value node
    */
    int dfs(int current, int parent, int level, vector<int>& jump, vector<vector<int>>& result, unordered_map<int, vector<int>>& m) {
        jump[current] = level;
        for (auto child: m[current]) {
            if (child == parent) { //0---2
                continue;
            } else if (jump[child] == -1) { //Child node is not visited
                jump[current] = min(jump[current], dfs(child, current, level+1, jump, result, m));
            } else { //Child node is already visited
                jump[current] = min(jump[current], jump[child]);
            }
        }
        //if the current node is not updated 
        if (jump[current] == level && current != 0) {
            result.push_back({parent, current});
        }
        
        return jump[current];
    }
};
