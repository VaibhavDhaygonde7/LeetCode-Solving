#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        // vector<int> solutions_to_right_of_index(nums.size()); // basically this array is the max cash which can be obtained from ind till end. Let's say we are at last index then the maximum amount we can steal is nums[nums.size()-1]. If we are at the second last index then we can steal either nums[nums.size()-2] or nums[nums.size()-1] depending on the wealth of both the neighbourhood
        // solutions_to_right_of_index[nums.size()-1] = nums[nums.size()-1]; 
        // solutions_to_right_of_index[nums.size()-2] = max(nums[nums.size()-2], nums[nums.size()-1]); 
        int next_to_next = nums[nums.size()-1]; 
        int next = max(nums[nums.size()-1], nums[nums.size()-2]); 
        for(int i = nums.size()-3; i >= 0; i--){
            // solutions_to_right_of_index[i] = max(nums[i] + solutions_to_right_of_index[i+2], solutions_to_right_of_index[i+1]);
            int temp_next_to_next = next_to_next;  
            next_to_next = next; 
            next = max(nums[i] + temp_next_to_next, next); 
        }

        return next; 

    }
};
