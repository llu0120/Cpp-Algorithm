/*
Given n lottery tickets, each one with numbers 1, 2, 3, ... ,n written on it. The value of the ticket is the sum of all digits. So value of 1 is 1, value of 12 is 3(1+2), value of 99 is 18(9+9). A lottery ticket wins if the value of the ticket is the expected one. Determine the possibilities of ticket values that make the most tickets win.

Example: n=12
Analysis: the tickets are [1,2,3,4,5,6,7,8,9,10,11,12], the values are [1,2,3,4,5,6,7,8,9,1,2,3], there could be maximum of 2 tickets wins, and there are 3 possibilities of ticket values for this situation: 1,2,3
*/

#include<vector> 
#include<iostream> 
#include<unordered_map>  
#include<queue> 
using namespace std; 
class solution {
public: 
	vector<int> maxProb(int n) {
		vector<int> result; 
		vector<int> value(n,0); 
		unordered_map<int, int> m;
 
		//Construct value matrix
		for (int i = 1; i <= n; i++) {
			string tmp = to_string(i);
			//cout << tmp << endl;
			for (int j = 0; j < tmp.size(); j++) {
				value[i-1] += tmp[j] - '0';
			} 
		}
		
		//build map: key:value, value:frequency 
		for (int i = 0; i < n; i++) {
			if (m.find(value[i]) == m.end()) {
				m[value[i]] = 1; 
				continue;
			}
			m[value[i]]++; 
		}
		
		//priority queue <int,int> freq, value 
		priority_queue<pair<int, int>, vector<pair<int, int>> > pq; 
		for (auto ele: m) {
			pair<int, int> tmp_ele{ele.second, ele.first};
			pq.push(tmp_ele); 
		}

		//add the biggest frequecny into result; 
		
		auto tmp = pq.top(); 
		int maxFreq = tmp.first; 

		pq.pop(); 
		result.push_back(tmp.second); 
		while (pq.top().first == maxFreq) {
			result.push_back(pq.top().second); 
			pq.pop();
		} 
       	
		return result; 
	}	

};

int main() {
	solution sol;
	int n = 12; 
    vector<int> result = sol.maxProb(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl; 	
	}			
	
	return 0; 
}


