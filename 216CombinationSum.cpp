#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> possible_solutions ;
        vector<int> permutations; 

        permutation(possible_solutions, permutations, k, 1, 0, n);

        return possible_solutions; 
    }

    void permutation(vector<vector<int>>& possible_solutions, vector<int> answer, int k, int elem, int sum, int target){
        if(sum > target) return ; 
        if(k == 0){
            // for(int n : answer) cout << n << " "; 
            // cout << ", Sum = " << sum << endl; 
            if(sum == target){
                possible_solutions.push_back(answer); 
            }
            return; 
        }

        for(int i = elem; i < 10; i++){
            answer.push_back(i); 
            sum += i; 
            permutation(possible_solutions, answer, k-1, i+1, sum, target); 
            answer.pop_back(); 
            sum -= i; 
        }

    }

};

int main(){

    Solution s = Solution(); 

    vector<vector<int>> solutions = s.combinationSum3(4, 1); 

    for(vector<int> vec : solutions){
        for(int n : vec){
            cout << n << " " ; 
        }
        cout << endl; 
    }

    
    return 0; 
}