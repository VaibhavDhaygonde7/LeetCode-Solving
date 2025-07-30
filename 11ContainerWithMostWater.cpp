#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> left_indices = farthestLeftIndGreaterThanCurrentElem(height); 
        vector<int> right_indices = farthestRightIndGreaterThanCurrentElem(height); 

        int max_water = 0; 
        for(int i = 0; i < height.size(); i++){
            max_water = max(max_water, height[i] * (i - left_indices[i])); 
            max_water = max(max_water, height[i] * (right_indices[i] - i)); 
        }

        return max_water; 
    }
    vector<int> farthestRightIndGreaterThanCurrentElem(vector<int>& height){
        vector<int> answers(height.size()); 
        answers[answers.size()-1] = answers.size()-1; 

        for(int i = answers.size()-2; i >= 0; i--){
            if(height[i] == height[i+1]){
                answers[i] = answers[i+1]; 
            }
            else if(height[i] > height[i+1]){
                int ind = answers[i+1]; 
                while(ind > i){
                    if(height[ind] >= height[i]){
                        break; 
                    }
                    ind--; 
                }
                answers[i] = ind; 
            }
            else{
                int ind = answers.size()-1; 
                while(ind > i){
                    if(height[ind] >= height[i]){
                        break; 
                    }
                    ind--; 
                }
                answers[i] = ind; 
            }
        }

        return answers; 

    }
    vector<int> farthestLeftIndGreaterThanCurrentElem(vector<int>& height){
        vector<int> answers(height.size()); 
        answers[0] = 0; 
        for(int i = 1; i < answers.size(); i++){
            if(height[i] == height[i-1]){
                answers[i] = answers[i-1]; 
            }
            else if(height[i] < height[i-1]){
                int ind = 0; 
                while(ind < i){
                    if(height[ind] >= height[i]){
                        break; 
                    }
                    ind++; 
                }
                answers[i] = ind; 
            }
            else{
                int ind = answers[i-1]; 
                while(ind < i){
                    if(height[ind] >= height[i]){
                        break; 
                    }
                    ind++; 
                }
                answers[i] = ind; 
            }
        }  
        
        return answers; 
    }

    int max(int n1, int n2){
        if(n1 > n2) return n1; 
        return n2; 
    }

};

int main(){

    vector<int> arr = {2,1,4,4,4,3}; 

    Solution s = Solution(); 

    cout << s.maxArea(arr) << endl; 

    return 0; 
}