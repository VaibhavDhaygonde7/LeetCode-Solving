#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std; 

// let current element be x. if we find x-1, then we found a new endingPoint. If we find x+1, then we found new startingPoint. When we don't find both, we will simply add{x,x}; (sp=ep=x)
 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> startToEnd; 
        unordered_map<int,int> endToStart; 

        int longestSequence = 0; 

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i]; 
            if(endToStart.find(x-1)!=endToStart.end() && startToEnd.find(x+1) != startToEnd.end()){
                int sp = endToStart[x-1]; 
                int ep = startToEnd[x+1]; 
                endToStart.erase(x-1); 
                startToEnd.erase(x+1); 
                endToStart[ep] = sp; 
                startToEnd[sp] = ep; 
                longestSequence =  max(longestSequence, ep-sp+1); 
                continue; 
            }
            if(endToStart.find(x-1)!=endToStart.end()){
                int ep = x; 
                int sp = endToStart[x-1]; 
                startToEnd[sp] = x; 
                endToStart.erase(x-1); 
                endToStart.insert({ep, sp}); 
                longestSequence = max(longestSequence, ep-sp+1); 
            }
            else if(startToEnd.find(x+1) != startToEnd.end()){
                int sp = x; 
                int ep = startToEnd[x+1]; 
                endToStart[ep] = x; 
                startToEnd.erase(x+1); 
                startToEnd.insert({sp, ep}); 
                longestSequence = max(longestSequence, ep-sp+1); 
            }
            else{
                startToEnd.insert({x,x}); 
                endToStart.insert({x,x}); 
                longestSequence = max(longestSequence, 1); 
            }
        }

        return longestSequence; 
    }
};

int main(){

    vector<int> nums = {1,0,1,2}; 

    Solution s = Solution(); 

    cout << s.longestConsecutive(nums) << endl; 


    return 0; 
}
