#include <iostream>
#include <vector>
using namespace std; 

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        int totalSum = 0; 
    
        
        for(int n : arr) totalSum += n; 
        
        vector<vector<int>> dp(totalSum + 1, vector<int> (arr.size()+1, -1)); 

        return recursion(arr, dp, d, 0, totalSum, 0); 

    }

    int recursion(vector<int>& arr,  vector<vector<int>>& dp, int d, int instantSum, int totalSum, int ind){
        if(ind == arr.size()){
            if((2*instantSum) - totalSum == d) return 1; 
            return 0; 
        }

    
        int take = dp[instantSum + arr[ind]][ind+1]; 
        int notTake = dp[instantSum][ind+1]; 
        
        if(take == -1){
            take = recursion(arr, dp, d, instantSum + arr[ind], totalSum, ind+1); 
            dp[instantSum + arr[ind]][ind+1] = take; 
        }    
            
        if(notTake == -1){
            notTake = recursion(arr, dp, d, instantSum, totalSum, ind+1); 
            dp[instantSum][ind+1] = notTake; 
        }
            

        return take + notTake; 
    }
};

class Solution2{
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum = 0; 
        for(int n : arr) totalSum += n; 

        vector<vector<int>> dp(totalSum+1, vector<int>(arr.size()+1, 0));
        
        if((totalSum + d)%2 == 0 && totalSum >= (totalSum + d)/2){
            dp[(totalSum + d)/2][arr.size()] = 1; 
        }
        else{
            return 0; 
        }

        for(int i = arr.size()-1; i>=0; i--){
            updateInd(arr, dp, i); 
        }
        
        return dp[0][0]; 
    }

    void updateInd(vector<int>& arr, vector<vector<int>>& dp, int ind){

        for(int i = 0; i < dp.size(); i++){
            dp[i][ind] = dp[i][ind+1]; 
            if(i + arr[ind] < dp.size()){
                dp[i][ind] += dp[i+arr[ind]][ind+1]; 
            }
        }

    }
};

class Solution3{
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum = 0; 
        for(int n : arr) totalSum += n; 

        vector<int> prev(totalSum + 1, 0); 
        vector<int> curr(totalSum + 1, 0); 



        if((totalSum + d)%2 == 0 && totalSum >= (totalSum + d)/2){
            curr[(totalSum + d)/2] = 1; 
        }
        else{
            return 0; 
        }

        for(int i = arr.size()-1; i >= 0; i--){
            for(int j = 0; j <= totalSum; j++){
                prev[j] = curr[j]; 
                if(j + arr[i] <= totalSum){
                    prev[j] += curr[j + arr[i]]; 
                }
            }
            prev = curr; 
        }
        
        return prev[0]; 
    }

};

int main(){

    Solution s = Solution(); 

    vector<int> nums = {5, 2, 6, 4}; 

    cout << s.countPartitions(nums,3) << endl; 

    Solution2 s2 = Solution2(); 

    cout << s2.countPartitions(nums, 3) << endl; 

    return 0; 
}
