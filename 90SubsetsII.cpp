#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s; 
        vector<int> instantSubs; 

        recursion(nums, s, instantSubs, 0); 

        return s; 
    }
    void recursion(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& instantSubset, int ind){
        subsets.push_back(instantSubset); 

        for(int i = ind; i < nums.size(); i++){
            if(i == ind || (i > ind && nums[i] != nums[i-1])){
                instantSubset.push_back(nums[i]); 
                recursion(nums, subsets, instantSubset, i+1);
                instantSubset.pop_back(); 
            }
        }

    }
};

int main(){

    vector<int> nums = {1,2,3}; 

    Solution s = Solution(); 

    vector<vector<int>> subsets = s.subsets(nums); 

    for(vector<int> v : subsets){
        for(int n : v){
            cout << n << " "; 
        }
        cout << endl;   
    }

    return 0; 
}

