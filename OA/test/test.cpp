#include<iostream> 
#include<vector> 

using namespace std; 

class Solution {
public: 
	void moveZeros(vector<int>& nums) {
		int len = nums.size(); 
		int left = len-1;
        int right = len-1;
        
        while(right >= 0){
        	if (nums[right] != 0){     //if the right pointer number is not zero, then swap the number of left pointer and right p    ointer. Then move the left pointer.
                 int temp = nums[right];
                 nums[right] = nums[left];
                 nums[left] = temp;
                 left--;
              }
              right--;
          }

	}
};

int main() {
	vector<int> nums{0,0,-2,5,0,3,0};
	//Want to output 0, 0, 0, 0, -2, 5, 3 
	Solution sol; 
	sol.moveZeros(nums);
	for (auto i: nums){
		cout << i << ", "; 	
	} 
	 
	return 0; 
}
