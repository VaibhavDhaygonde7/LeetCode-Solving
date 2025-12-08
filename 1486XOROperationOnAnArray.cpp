#include <iostream>
using namespace std; 

class Solution {
public:

    int xorForFirstNNaturalNumbers(int n){
        if(n % 4 == 0) return n; 
        if(n % 4 == 1) return 1; 
        if(n % 4 == 2) return n+1; 
        if(n % 4 == 3) return 0; 
        return -1; 
    }
    int xorOperation(int n, int start) {
        if(n == 1) return start; 
        int l = 0 + (start/2); 
        int r = (n-1) + (start/2); 
        int ans;

        if(l == 0){
            ans = (xorForFirstNNaturalNumbers(r)) << 1;
        }
        else{
            ans = (xorForFirstNNaturalNumbers(l-1) ^ xorForFirstNNaturalNumbers(r)) << 1;
        }

        if((start & 1) && (n & 1)) ans = ans | 1;

        return ans;         
    }
};
