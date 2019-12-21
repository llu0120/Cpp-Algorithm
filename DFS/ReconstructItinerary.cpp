/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/
//Time O(n + nlogn + n!)
// --> (traverse all the tickets + sort the tickets in lexical order + dfs every time the tickets options will decrease by 1) 
//Space O(n) --> the graph 

class Solution {
public:
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result; 
        //Corner Case 
        if (tickets.size() == 0) {
            return result; 
        }
        
        //Construct Graph: Map: key --> the start of the ticket (string), value --> the possible destination of the tickets (vector<string>)   
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < tickets.size(); i++) {
            if (graph.find(tickets[i][0]) == graph.end()) {
                vector<string> tmp_val;
                tmp_val.push_back(tickets[i][1]);
                graph[tickets[i][0]] = tmp_val;
                continue;
            }
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        //Sort the value of the map to make it in lexical order 
        for (auto& val : graph) {
            sort(val.second.begin(), val.second.end());
        }
        
        //result is a list of string (vector<string>)
        int pathLen = tickets.size() + 1;  //The length of the result should be 
        
        string start = "JFK";
        result.push_back(start);
        
        /*A better way to check if dfs will return a solution 
        if (dfs()) {
            return result;
        }
        return NULL;
        */
        
        //Since the problem says there is at least one valid itinerary 
        dfs(start, result, graph, pathLen); 
        return result; 
        
    }
    
    bool dfs(string& start, vector<string>& result, unordered_map<string, vector<string>>& graph, int& pathLen) {
        //If the result length is the path len --> this means I get a result
        if (result.size() == pathLen) {
            return true; 
        }
        
        //If there is no tickets start with the start
        if (graph.find(start) == graph.end()) {
            return false;
            
        }
        
        vector<string>& destinations = graph[start];

        for (int i = 0; i < destinations.size(); i++) {
            string dest = destinations[i];
            //remove dest from the destinations 
            destinations.erase(destinations.begin() + i);
            //add dest into the path 
            result.push_back(dest);
            //recursive dfs 
            if (dfs(dest, result, graph, pathLen)) {
                return true;
            }
            result.erase(result.end());
            destinations.insert(destinations.begin() + i, dest);
            
        }
        return false;
    }
};
