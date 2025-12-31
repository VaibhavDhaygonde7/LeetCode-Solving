#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubArrayMaximum(nums) - sumOfSubArrayMinimum(nums); 
    }

    long long sumOfSubArrayMinimum(vector<int>& nums){

        vector<pair<int, long long>> st; 
        long long answer = 0;

        for(int i = nums.size() - 1; i >= 0; i--){

            while(!st.empty() && nums[st[st.size()-1].first] > nums[i]) st.pop_back(); 

            long long contribution = -1; 
            if(st.empty()){
                contribution = ((long long)nums[i]) * ((nums.size() - 1) - i + 1); 
            }
            else{
                // accumulating contribution 
                contribution = (((long long)nums[i]) * ((st[st.size()-1].first - 1) - i + 1)) + st[st.size()-1].second; 
            }

            st.push_back({i, contribution}); 
            answer += contribution; // adding contribution 
        }

        return answer; 
    }

    long long sumOfSubArrayMaximum(vector<int>& nums){

        vector<pair<int, long long>> st; 
        long long answer = 0;

        for(int i = nums.size() - 1; i >= 0; i--){

            while(!st.empty() && nums[st[st.size()-1].first] < nums[i]) st.pop_back(); 

            long long contribution = -1; 
            if(st.empty()){
                contribution = ((long long)nums[i]) * ((nums.size() - 1) - i + 1); 
            }
            else{
                // accumulating contribution 
                contribution = (((long long)nums[i]) * ((st[st.size()-1].first - 1) - i + 1)) + st[st.size()-1].second; 
            }

            st.push_back({i, contribution}); 
            answer += contribution; // adding contribution 
        }

        return answer; 
    }

};

int main(){

    Solution s = Solution(); 

    vector<int> nums = {4,-2,-3,4,1}; 

    cout << s.subArrayRanges(nums) << endl; 


    return 0;   
}
