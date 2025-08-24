#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n; 
        }
        int prev_of_prev = 1; 
        int prev = 2; 
        int current_possibility = prev_of_prev + prev; 
        for(int i = 3; i <= n; i++){
            current_possibility = prev_of_prev + prev; 
            prev_of_prev = prev; 
            prev = current_possibility; 
        }

        return current_possibility; 
    }
};