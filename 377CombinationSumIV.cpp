#include <iostream>
#include <vector>
using namespace std; 

// unfortunately this method doesn't work for large numbers :(
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> instant_arr; 
        return recursion(nums, instant_arr, target, 0);  
    }

    int recursion(vector<int>& nums, vector<int>& instant_arr, int target, int ind){
        if(target == 0) return perm(instant_arr); 
        if(target < 0) return 0; 

        if(ind == nums.size()) return 0; 

        instant_arr.push_back(nums[ind]); 
        int take = recursion(nums, instant_arr, target-nums[ind], ind); 
        instant_arr.pop_back(); 
        int notTake = recursion(nums, instant_arr, target, ind+1); 

        return take + notTake;
    }

    int permutations(vector<int>& nums){
        int noOfDistinctIntegers = 0; 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]) noOfDistinctIntegers++; 
        }
        noOfDistinctIntegers++;
        vector<int> map(noOfDistinctIntegers); 

        int count = 1; 
        int ind = 0;  
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                map[ind] = count; 
                count = 0; 
                ind++; 
            }
            count++;
        }

        map[ind] = count; 
        
        int numerator = fac(nums.size()); 
        int denominator = 1; 
        for(int i = 0 ; i < noOfDistinctIntegers; i++){
            denominator *= fac(map[i]); 
        }
        return numerator/denominator; 

    }
    int fac(int x){
        int res = 1; 
        for(int i = x; i > 0; i--){
            res *= i; 
        }
        return res; 
    }

    int perm(vector<int> nums){

        int noOfDistinctIntegers = 0; 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]) noOfDistinctIntegers++; 
        }
        noOfDistinctIntegers++;
        vector<int> map(noOfDistinctIntegers); 

        int count = 1; 
        int ind = 0;  
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                map[ind] = count; 
                count = 0; 
                ind++; 
            }
            count++;
        }

        map[ind] = count; 

        int res = 1; 

        int numerator = nums.size(); 

        for(int j = 0; j < map.size(); j++){
            for(int k = 1; k < map[j]; k++){
                res *= numerator; 
                res /= k; 
                numerator--; 
            }
        }

        return res; 

    }


};

int perm(vector<int> nums){

    int noOfDistinctIntegers = 0; 
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]) noOfDistinctIntegers++; 
    }
    noOfDistinctIntegers++;
    vector<int> map(noOfDistinctIntegers); 

    int count = 1; 
    int ind = 0;  
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]){
            map[ind] = count; 
            count = 0; 
            ind++; 
        }
        count++;
    }

    map[ind] = count; 

    int res = 1; 

    int numerator = nums.size(); 

    for(int j = 0; j < map.size(); j++){
        for(int k = 1; k <= map[j]; k++){
            res *= numerator; 
            res /= k; 
            numerator--; 
        }
    }

    if(numerator > 0){
        res*= numerator; 
        numerator--; 
    }

    return res; 

}

// recursion 
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return recursion(nums, target); 
    }

    int recursion(vector<int>& nums, int target){
        if(target == 0) return 1; 

        int res = 0; 

        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                res += recursion(nums, target-nums[i]); 
            }
        }
        return res; 
    }
};


// memoization - best solution 
class Solution3 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1); 
        return recursion(nums, target, dp); 
    }

    int recursion(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) return 1; 

        int res = 0; 

        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                if(dp[target - nums[i]] == -1){
                    int waysAtTarget = recursion(nums, target-nums[i], dp); 
                    res += waysAtTarget; 
                    dp[target-nums[i]] = waysAtTarget; 
                }
                else{
                    res += dp[target-nums[i]]; 
                }
            }
        }
        return res; 
    }
};


// memoization 
class Solution4 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1); 
        dp[0] = 1; 

        for(int i = 1; i <= target; i++){
            dp[i] = updateIthIndex(nums, dp, i); 
        }

        return dp[target]; 
    }
    int updateIthIndex(vector<int>& nums, vector<int>& dp, int target){
        int total_number_of_ways = 0; 

        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                total_number_of_ways += dp[target-nums[i]]; 
            }
        }

        return total_number_of_ways; 
    }
};

int main(){

    Solution s = Solution(); 

    vector<int> nums = {1,2,3}; 

    // cout << s.combinationSum4(nums, 3) << endl; 

    Solution2 s2 = Solution2() ;
    Solution3 s3 = Solution3() ;
    Solution4 s4 = Solution4() ;

    cout << s2.combinationSum4(nums, 4) << endl; 
    cout << s3.combinationSum4(nums, 4) << endl; 
    cout << s4.combinationSum4(nums, 4) << endl; 
    
    return 0; 
}
