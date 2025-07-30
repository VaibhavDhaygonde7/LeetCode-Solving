#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answers(rowIndex+1); 
        answers[0] = 1; 
        int num = 1; 
        int k = 1; 
        while(k <= rowIndex){
            num *= (rowIndex-k+1); 
            num /= k; 
            answers[k] = num; 
            k++; 
        }
        return answers; 
        
    }
};

int main(){

    Solution s = Solution(); 

    vector<int> answers = s.getRow(0); 

    for(int n : answers){
        cout << n << " "; 
    }

    cout << endl; 

    return 0; 
}