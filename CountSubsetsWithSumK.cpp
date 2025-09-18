#include <iostream>
#include <vector>
using namespace std; 

// not the most optimal approach 
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here    
        int count = 0; 
        recursion(arr, 0, 0, target, count); 

        return count; 
    }

    void recursion(vector<int>& arr, int instantSum, int ind, int target, int& count){
        // for(int n : instantSubset) cout << n << " "; 
        // cout << ", InstantSum: " << instantSum << endl; 

        if(instantSum == target) count++; 

        for(int i = ind; i < arr.size(); i++){
            recursion(arr, instantSum + arr[i], i+1, target, count); 
        }
    }

};

// trying to get better 
class Solution2 {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here    

        int totalSum = 0; 
        for(int n : arr) totalSum += n; 

        vector<vector<int>> dp(totalSum+1, vector<int>(arr.size()+1, -1)); 

        return recursion(arr, target,dp, 0, 0); 
        
    }

    int recursion(vector<int>& arr, int target, vector<vector<int>>& dp, int ind, int instantSum){

        if(ind == arr.size()){
            if(instantSum == target) return 1;  
            return 0; 
        }

        int notTake = dp[instantSum][ind+1]; 

        if(notTake == -1){
            notTake = recursion(arr, target, dp, ind+1, instantSum); 
            dp[instantSum][ind+1] = notTake; 
        }

        int take = dp[instantSum+arr[ind]][ind+1]; 
        if(take == -1){
            take = recursion(arr, target, dp, ind+1, instantSum + arr[ind]); 
            dp[instantSum+arr[ind]][ind+1] = take; 
        }
        

        return take + notTake; 
    }

};

// getting better again!
class Solution3 {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int totalSum = 0; 
        for(int n : arr){
            totalSum += n; 
        }

        if(target > totalSum) return 0; 

        vector<vector<int>> dp(arr.size()+1, vector<int>(totalSum+1, 0)); 
        dp[arr.size()][target] = 1; 

        for(int i = arr.size()-1; i >= 0; i--){
            for(int j = 0; j <= totalSum; j++){
                dp[i][j] = dp[i+1][j]; 
                if(j + arr[i] <= totalSum){
                    dp[i][j] += dp[i+1][j+arr[i]]; 
                }
            }
        }

        return dp[0][0]; 

    }
};


// can't get better than this
class Solution4 {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        int totalSum = 0; 
        for(int n : arr) totalSum += n; 
        
        if(target > totalSum) return 0; 

        vector<int> curr(totalSum+1, 0); 
        vector<int> prev(totalSum+1, 0); 

        curr[target] = 1; 

        for(int i = arr.size()-1; i >= 0; i--){
            for(int j = 0; j <= totalSum; j++){
                prev[j] = curr[j]; 
                if(j + arr[i] <= totalSum){
                    prev[j] += curr[j+arr[i]]; 
                }
            }
            curr = prev; 
        }

        return prev[0]; 
        
    }
};



int main(){

    vector<int> nums = {1,2,3}; 

    Solution4 s = Solution4(); 

    cout << s.perfectSum(nums, 3) << endl; 

    return 0; 
}