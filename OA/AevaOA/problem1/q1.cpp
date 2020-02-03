/*
Given two integers represents lower and upper ends of a range, given an array of integers as bad numbers. Find the maximum length of an array inside the given range that does not contain any of the bad numbers. The ends of given range [lower, upper] are inclusive.

Example: lower=1, upper=10, badNumbers=[3,8,11]
Analysis: the possible ranges are [1,2], [4,7], [9,10], so the maximum length is 4 from [4,7]
*/

#include <vector> 
#include <iostream> 
#include <unordered_set> 

using namespace std; 
class solution {
public: 
	int maxLength(int lower, int upper, vector<int> badNumbers) {
		unordered_set<int> us(badNumbers.begin(), badNumbers.end()); 
		int result = 0;
		int left = lower; 
		int right = lower;
		vector<vector<int>> ranges;   
		for (int i = lower+1; i <= upper; i++) {
			if (us.find(i) == us.end()) {
				right++;
				continue; 
			} 
			ranges.push_back({left, right}); 
			left = i; 
			right = left; 
		}
		for (auto i: ranges) {
			int tmp = i[1] - i[0];
			result = max(result, tmp); 
		}		
		return result; 
	}
};



int main() {
	int lower = 1; 
	int upper = 10; 
	vector<int> badNumbers{3, 8, 11};
	solution sol; 
	int result = sol.maxLength(lower, upper, badNumbers); 
	cout << result << endl; 
	
	return 0;
}
