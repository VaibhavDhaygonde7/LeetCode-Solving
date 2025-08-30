#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        sort(nums.begin(), nums.end()); 

        vector<int> costs(nums.size(), -1); 

        int ind = 0; 
        int count = 1; 

        for(int i = 1; i < nums.size(); i++){
            if(nums[ind] != nums[i]){
                costs[ind] = count*nums[ind]; 
                ind++; 
                nums[ind] = nums[i];
                count = 0;  
            }
            count++; 
        }

        costs[ind] = count*nums[ind]; // as last element won't be counted because the loop will be exited

        // for(int n : nums) cout << n << " " ; 
        // cout << endl; 
        // for(int n : costs) cout << n << " "; 

        int prev_of_prev = costs[0];
        int prev;  
        if(nums[1] - nums[0] > 1) prev = costs[0] + costs[1]; 
        else prev = max(costs[1], costs[0]); 

        for(int i = 2; i < nums.size() && costs[i] != -1; i++){
            int current; 
            if(nums[i] - nums[i-1] != 1){
                current = max(prev + costs[i], prev_of_prev + costs[i]); 
            }
            else{
                current = max(prev, prev_of_prev + costs[i]); 
            }
            prev_of_prev = prev; 
            prev = current; 
        }

        return prev; 
    }
};
