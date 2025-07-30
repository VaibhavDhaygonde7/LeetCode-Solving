#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> answers; 
        int ind = 0; 
        while(ind < nums.size()){
            int target = -nums[ind]; 
            int low = ind+1; 
            int high = nums.size()-1; 
            while(low < high){
                if(nums[low] + nums[high] > target){
                    high--; 
                }
                else if(nums[low] + nums[high] < target){
                    low++; 
                }
                else{
                    vector<int> small_arr(3); 
                    small_arr[0] = nums[ind]; 
                    small_arr[1] = nums[low]; 
                    small_arr[2] = nums[high]; 
                    answers.push_back(small_arr); 
                    low++; 
                    while(low < nums.size() && nums[low] == nums[low-1]){
                        low++; 
                    }
                }
            }
            ind++; 
            while(ind < nums.size() && nums[ind] == nums[ind-1]){
                ind++; 
            }
        }
        return answers; 
    }
};

int main(){

    vector<int> arr = {-4,-1,-1,0,1,2};
    Solution s = Solution(); 

    vector<vector<int>> answers = s.threeSum(arr); 

    for(vector<int> v : answers){
        for(int n : v){
            cout << n << " "; 
        }
        cout << endl; 
    }

    return 0; 
}