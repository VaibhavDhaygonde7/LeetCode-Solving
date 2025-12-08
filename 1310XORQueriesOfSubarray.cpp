#include <iostream>
using namespace std; 

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // here we are going to use simple logic of a ^ a = 0, 0 ^ a = a
        vector<int> prefix(arr.size());  
        prefix[0] = arr[0]; 
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = prefix[i-1] ^ arr[i]; 
        }
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0]; 
            int r = queries[i][1]; 
            ans[i] = prefix[r]; 
            if(l >= 1) ans[i] ^= prefix[l-1]; 
        }
        return ans; 
    }
};
