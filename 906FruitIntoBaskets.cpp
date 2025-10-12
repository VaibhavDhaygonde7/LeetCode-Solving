#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std; 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int> set; 

        int l = 0; 
        int r = 0; 

        int maxFruits = 0; 

        while(r < fruits.size()){
            if(set.find(fruits[r]) != set.end()){
                maxFruits = max(maxFruits, r-l+1); 
                r++; 
            }
            else{
                if(set.size() < 2){
                    set.insert(fruits[r]); 
                    maxFruits = max(maxFruits, r-l+1); 
                    r++; 
                }
                else{
                    // cout << "HEy I'm here" << endl; 
                    set.clear(); 
                    set.insert(fruits[r-1]); 
                    set.insert(fruits[r]); 
                    l = r-1; 
                    while(fruits[l] == fruits[r-1]){
                        l--; 
                    }
                    l++; 
                    maxFruits = max(maxFruits, r-l+1); 
                    // cout << l << " "  << r << endl;  
                }
            }
        }

        return maxFruits; 

    }

};

int main(){

    Solution s = Solution(); 

    vector<int> fruits = {1,2,3,2,2}; 

    cout << s.totalFruit(fruits) << endl; 

    return 0; 
}
