#include <iostream>
#include <vector>
#include <algorithm>
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
