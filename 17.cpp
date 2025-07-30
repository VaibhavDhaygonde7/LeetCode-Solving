#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> key_value_pairs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        vector<string> answers; 

        string instantaneous_combination(digits.length(), 'a'); // this will create a string of length digits.length() filled with a's 
        
        int ind = digits.length() - 1; 

        find(digits, answers, key_value_pairs, instantaneous_combination, ind); 

        return answers; 
    }

    void find(string digits, vector<string>& answers, vector<string>& key_value_pairs, string instantaneous_combination, int ind){
        if(ind < 0){
            if(instantaneous_combination != "") answers.push_back(instantaneous_combination); 
            return ; 
        }


        for(int i = 0; i < key_value_pairs[digits[ind] - '2'].length(); i++){
            instantaneous_combination[ind] = key_value_pairs[digits[ind] - '2'][i]; 
            find(digits, answers, key_value_pairs, instantaneous_combination, ind-1); 
        }

    }
};

int main(){

    Solution s = Solution(); 

    vector<string> answers = s.letterCombinations("253"); 

    for(string s : answers){
        cout << s << endl;  
    }

    return 0;   
}