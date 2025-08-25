#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 1){
            return true; 
        }

        if(stones[1] != 1) return false; 

        vector<int> not_valid_jumps(stones.size(), -1); // this is the array which will initially contain all elements as -1,  
        unordered_map<int, int> map; 
        for(int i = 0; i < stones.size(); i++){
            map.insert({stones[i], i}); 
        }
        return recursion(stones, map, 1, 1, not_valid_jumps);
    }
    bool recursion(vector<int>& stones, unordered_map<int, int>& map, int ind, int k, vector<int>& not_valid_jumps){
        if(ind == stones.size() - 1){
            return true; 
        } 

        // here ind indicates the index we are currently standing at and we wish to jump forward 
        if(map.find(stones[ind] + k) != map.end()){
            if(not_valid_jumps[ind] != k){
                if(recursion(stones, map, map[stones[ind] + k], k, not_valid_jumps)) return true; 
                not_valid_jumps[ind] = k; 
            }
        }

        if(k-1 != 0 && map.find(stones[ind] + k - 1) != map.end()){
            if(not_valid_jumps[ind] != k-1){
                if(recursion(stones, map, map[stones[ind] + k - 1], k-1, not_valid_jumps)) return true; 
                not_valid_jumps[ind] = k-1; 
            }
        }

        if(map.find(stones[ind] + k + 1) != map.end()){
            if(not_valid_jumps[ind] != k+1){
                if(recursion(stones, map, map[stones[ind] + k + 1], k+1, not_valid_jumps)) return true; 
                not_valid_jumps[ind] = k+1; 
            }
        }

        return false; 
    }
};

int main(){

    vector<int> stones = {0,1,3,5,6,8,12,17}; 

    Solution s = Solution(); 

    cout << s.canCross(stones) << endl; 

    return 0; 
}