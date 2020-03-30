/*
There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

1. cells.length == 8
2. cells[i] is in {0, 1}
3. 1 <= N <= 10^9
*/ 

//Construct Hash Function 
//Note that you can use any kind of operation to generate a hash. You just need to be creative so that collisions are minimized. For example, hash^=V[i], hash|=V[i], hash+=V[i]*V[i] or even hash+=(V[i]<<i)*(V[i]<<i)*(V[i]<<i) are all valid until of course, your hash doesn't overflows.

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> tmp (cells.size(), 0); 
        struct VectorHasher {
            int operator()(const vector<int> &V) const {
                int hash=0;
                for(int i=0;i<V.size();i++) {
                    hash+=V[i]; // Can be anything
                }
                return hash;
            }
        };
        
        unordered_map<vector<int>, int, VectorHasher> m; 
        int count = 0; 
        while (N > 0) {
            m[cells] = N; 
            if (cells[0] == 1) {
                tmp[0] == 0; 
            }
            for (int i = 1; i < cells.size()-1; ++i) {
                if (cells[i-1] == cells[i+1]) {
                    tmp[i] = 1; 
                    continue; 
                } 
                if (cells[i] == 1 && (cells[i-1] != cells[i+1])) {
                    tmp[i] = 0; 
                }
            }
            
            if (cells[cells.size()-1] == 1) {
                tmp[cells.size()-1] == 0; 
            }
            N--; 
            cells = tmp; 
            if (m.find(cells) != m.end()) {
                N %= m[cells] - N; 
            }
        }
        return cells; 
    }
};
