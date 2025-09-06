#include <iostream>
#include <vector>
#include <climits>
using namespace std; 

// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         bool foundMinSum = false; 
//         int minimumSum = INT_MAX; 
//         if(l-r == 0){
//             int instantSum = 0; 
//             int low = 0; 
//             int high = l-1; 
        

//             for(int i = 0; i <= high; i++){
//                 instantSum += nums[i]; 
//             }
//             if(instantSum > 0 && minimumSum > instantSum){ 
//                 minimumSum = instantSum;
//                 foundMinSum = true; 
//             } 

//             while(high < nums.size()){
//                 // instantSum -= nums[high]; 
//                 instantSum -= nums[low];
//                 high++; 
//                 if(high == nums.size()) break; 
//                 low++; 
//                 instantSum += nums[high]; 
//                 if(instantSum > 0 && minimumSum > instantSum){ 
//                     minimumSum = instantSum;
//                     foundMinSum = true; 
//                 } 
//             }
//             if(!foundMinSum) return -1; 
//             return minimumSum; 
//         }
//         int low = 0; 
//         int high = l-1; 
//         if(high >= nums.size()) return 0; 
//         int instantSum = 0; 

//         for(int i = 0; i <= high; i++){
//             instantSum += nums[i]; 
//         }
//         cout << instantSum << endl; 
//         if(instantSum > 0 && minimumSum > instantSum){ 
//             minimumSum = instantSum;
//             foundMinSum = true; 
//         } 
//         cout << endl; 
//         while(high < nums.size()){
//             while(high < nums.size() && high-low+1< r){
//                 high++; 
//                 if(high == nums.size()){
//                     while(high-low > l){
//                         instantSum -= nums[low]; 
//                         if(instantSum > 0 && minimumSum > instantSum){ 
//                             minimumSum = instantSum;
//                             foundMinSum = true; 
//                         } 
//                         low++; 
//                     }
//                     if(!foundMinSum) return -1; 
//                     return minimumSum; 
//                 }
//                 instantSum += nums[high];         
//                 if(instantSum > 0 && minimumSum > instantSum){ 
//                     minimumSum = instantSum;
//                     foundMinSum = true; 
//                 }
//                 cout << instantSum << " ";  
//             }
//             cout << endl; 
//             while(high-low+1 > l){
//                 instantSum -= nums[low]; 
//                 low++; 
//                 if(instantSum > 0 && minimumSum > instantSum){ 
//                     minimumSum = instantSum;
//                     foundMinSum = true; 
//                 } 
//                 cout << instantSum << " " ; 
//             }
//             cout << endl; 
//         }
        
//         if(!foundMinSum) return -1; 
        
//         return minimumSum; 
//     }
// };


class Solution2 {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = __INT_MAX__; 
        bool foundMinSum = false; 

        for(int i = 0; i < nums.size(); i++){
            int instantSmallestSum = smallestSumWithInitialInd(nums, i, l, r); 
            if(instantSmallestSum != -1){
                minSum = min(minSum, instantSmallestSum); 
                foundMinSum = true; 
            }
        }

        if(!foundMinSum) return -1; 
        return minSum; 
    }
    int smallestSumWithInitialInd(vector<int>& nums, int ind, int l, int r){
        int low = ind; 
        int high = ind + l - 1; 
        if(high >= nums.size()) return -1; 
        int smallestSum = __INT_MAX__; 
        int instantSum = 0; 
        bool foundMinSum = false; 
        for(int i = low; i <= high; i++){
            instantSum += nums[i]; 
        }

        if(instantSum > 0 && smallestSum > instantSum){
            smallestSum = instantSum; 
            foundMinSum = true; 
        }

        for(int i = 0; i < r-l && high < nums.size(); i++){
            high ++ ; 
            if(high == nums.size()) break; 
            instantSum += nums[high]; 
            if(instantSum > 0 && smallestSum > instantSum){
                smallestSum = instantSum; 
                foundMinSum = true; 
            }
        }

        if(!foundMinSum) return -1; 
        return smallestSum; 
    }
};

int main(){

    Solution2 s = Solution2();  

    vector<int> nums = {1,2,3,4}; 

    cout << s.minimumSumSubarray(nums, 2, 4) << endl ;

    return 0; 
}
