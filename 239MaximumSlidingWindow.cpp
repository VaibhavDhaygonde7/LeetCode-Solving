#include <iostream>
#include <deque>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        // creating the basic skeleton of deque
        vector<int> ans; 
        for(int i = 0;i<k; i++){
            newElemToWindow(dq, nums[i]);
        }
        ans.push_back(dq.front()); 
        for(int i = k; i < nums.size(); i++){
            // we are inserting ith elem and removing (i-k)th elem 
            if(nums[i-k] == dq.front()){
                dq.pop_front(); 
                newElemToWindow(dq, nums[i]); 
                // ans[i] = dq.front(); 
                ans.push_back(dq.front()); 
            }
            else{
                newElemToWindow(dq, nums[i]); 
                // ans[i] = dq.front(); 
                ans.push_back(dq.front()); 
            }
        }
        return ans; 
    }

    void newElemToWindow(deque<int>& dq, int elem){
        while(!dq.empty() && dq.back() < elem) dq.pop_back(); 
        dq.push_back(elem); 
    }

};

int main(){

    vector<int> nums = {9,4,9,6,2,5}; 

    Solution s = Solution(); 

    vector<int> ans = s.maxSlidingWindow(nums, 2); 

    for(int n : ans) cout << n << " " ; 
    cout << endl; 


    return 0 ;
}
