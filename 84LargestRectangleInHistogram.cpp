#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left_indices = left_ind(heights); 
        vector<int> right_indices = right_ind(heights); 

        int max_area = 0; 

        for(int i = 0; i < heights.size(); i++){
            max_area = max(max_area, heights[i] * (right_indices[i] - left_indices[i] + 1)); 
        }

        return max_area; 
    }

    int max(int n1, int n2){
        if(n1 > n2) return n1; 
        return n2; 
    }
    vector<int> left_ind(vector<int>& arr){
        vector<int> left_indices(arr.size()); 
        left_indices[0] = 0; 

        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] < arr[i]){
                left_indices[i] = i; 
            }
            else{
                int ind = i-1; // pointing to the previous element which is greater than or equal to the current element 
                while(ind >= 0){
                    ind = left_indices[ind]; // this will point to the min index which at-least has the value of arr[ind]
                    if(ind == 0){
                        left_indices[i] = 0; 
                        break; 
                    }
                    if(arr[ind-1] < arr[i]){
                        left_indices[i] = ind; 
                        break;
                    }
                    else{
                        ind = ind-1; 
                    }
                }
            }
        }

        return left_indices;
    }

    vector<int> right_ind(vector<int>& arr){
        vector<int> right_indices(arr.size()); 
        right_indices[arr.size()-1] = arr.size()-1; 

        for(int i = arr.size()-2; i >= 0; i--){
            if(arr[i+1] < arr[i]){
                right_indices[i] = i; 
            }
            else{
                int ind = i+1; 

                while(ind < arr.size()){
                    ind = right_indices[ind]; 
                    if(ind == arr.size()-1){
                        right_indices[i] = arr.size()-1; 
                        break; 
                    }
                    if(arr[ind+1] < arr[i]){
                        right_indices[i] = ind; 
                        break; 
                    }
                    else{
                        ind++; 
                    }
                }
            }
        }

        return right_indices; 
    }

};

int main(){

    Solution s = Solution(); 

    vector<int> arr = {2,1,5,6,2,3}; 

    vector<int> left = s.left_ind(arr); 
    vector<int> right = s.right_ind(arr); 

    cout << "LEFT INDICES" << endl; 

    for(int n : left){
        cout << n << " "; 
    }
    cout << endl; 

    cout << "RIGHT INDICES" << endl; 
    for(int n : right){
        cout << n << " ";
    }
    cout << endl; 

    return 0; 
}