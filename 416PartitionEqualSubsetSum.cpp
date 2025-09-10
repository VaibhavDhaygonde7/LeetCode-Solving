#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0; 
        for(int n : nums) totalSum += n; 

        if(totalSum % 2 != 0) return false;     
        
        return recursion(nums, 0, totalSum/2); 
    }

    bool recursion(vector<int>& nums, int ind, int target){
        if(target == 0) return true; 

        if(ind == nums.size()-1) return target == nums[nums.size()-1]; 

        bool notTake = recursion(nums, ind+1, target); 
        if(notTake) return true; 

        bool take = false; 

        if(target >= nums[ind]){
            take = recursion(nums, ind+1, target-nums[ind]);
        }

        return take; 

    }
};


class Solution2{
    public: 
    bool canPartition(vector<int>& nums){

        int totalSum = 0; 
        
        for(int n : nums) totalSum += n; 

        if(totalSum % 2 != 0) return false; 

        vector<vector<int>> dp(nums.size()); 

        vector<int> one_d_array_for_sum(totalSum/2 + 1, -1); 

        for(int i = 0; i < dp.size(); i++){
            dp[i] = one_d_array_for_sum;  
        }

        return recursion(nums, dp, 0, totalSum/2); 

    }

    bool recursion(vector<int>& nums, vector<vector<int>>& dp, int ind, int target){
        if(target == 0) return true; 

        if(ind == nums.size()-1) return nums[nums.size()-1] == target;
            
        // cout << target << " "; 

        if(dp[ind+1][target] == -1){
            bool notTake = recursion(nums, dp, ind+1, target); 
            if(notTake) return true; 
            dp[ind+1][target] = false; 
        }

        bool take = false; 

        if(target >= nums[ind]){
            if(dp[ind+1][target-nums[ind]] != -1){
                take = dp[ind+1][target-nums[ind]]; 
            }
            else{
                take = recursion(nums, dp, ind+1, target-nums[ind]); 
                dp[ind+1][target-nums[ind]] = take; 
            }
        }

        return take; 
        
    }

}; 

int main(){

    vector<int> nums = {1,2,3,4}; 

    Solution2 s = Solution2(); 

    if(s.canPartition(nums)){
        cout << "Yay" << endl; 
    } 

    return 0; 
}
