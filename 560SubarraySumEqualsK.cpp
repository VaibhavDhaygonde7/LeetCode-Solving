#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int answer = 0; 

        unordered_map<int, int> map; 
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; 
            if(map.find(sum) == map.end()){
                map.insert({sum, 1}); 
            }
            else{
                map[sum] += 1; 
            }
            if(sum == k) answer++; 
            if(map.find(sum - k) != map.end() && k!=0) answer = answer + map[sum-k];
            if(map.find(sum - k) != map.end() && k == 0) answer += map[sum-k] - 1;   
        }


        return answer; 
    }
};
class Solution2{
public:
    int subarraySum(vector<int>& nums, int k) {
        // vector<int> prefixSum(nums.size()+1); 
        int prefix = 0; 
        unordered_map<int,int> map; 
        map.insert({0,1}); 
        long long answer = 0; 
        for(int i = 0; i<nums.size(); i++){
            // prefixSum[i+1] = nums[i] + prefixSum[i];
            prefix+=nums[i];  
            // cout << prefixSum[i+1] <<" "; 
            if(map.find(prefix - k) != map.end()){
                // if(k==0) answer--; // as we will count the current sub-array itself, which means we are considering empty sub-array with sum = 0
                answer += map[prefix - k]; 
            }

            if(map.find(prefix) != map.end()) map[prefix]++; 
            else map[prefix] = 1; 
            // for(auto i : map){
            //     cout << i.first <<" " << i.second << ", ";
            // }
            // cout << endl; 
        }
        // cout << endl; 
        return answer; 
    }
};

int main(){ 

    Solution2 s2 = Solution2(); 

    vector<int> nums = {1,2,3}; 
    int k = 3; 

    cout << s2.subarraySum(nums, k) << endl; 

    return 0; 
}
