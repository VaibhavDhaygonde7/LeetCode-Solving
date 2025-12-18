#include <iostream>
#include <vector>
#include <stack>
using namespace std; 


class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>> prefixMax = prefixMaxFromRight(height); 
        vector<int> pSum = prefixSum(height); 
        vector<pair<int,int>> NGE = nextGreaterElem(height); 

        int ind = 0; 
        while(ind < height.size() && height[ind] == 0) ind++; 

        int area = 0;  

        while(ind < height.size() - 1){
            if(NGE[ind].first != -1){
                // NGE exists
                area += (height[ind] * (NGE[ind].second - ind - 1)); 
                area -= areaCoveredBetweenTwoPoles(pSum, ind, NGE[ind].second); 
                // cout << "Area: " << (height[ind] * (NGE[ind].second - ind - 1)) -  areaCoveredBetweenTwoPoles(pSum, ind, NGE[ind].second) << ", i = " << ind << ", j = " << NGE[ind].second << endl; 
                ind = NGE[ind].second;
            }
            else{
                area += (prefixMax[ind+1].first * (prefixMax[ind+1].second - ind - 1)); 
                area -= areaCoveredBetweenTwoPoles(pSum, ind, prefixMax[ind+1].second);
                // cout << "Area: " << (prefixMax[ind+1].first * (prefixMax[ind+1].second - ind - 1)) - areaCoveredBetweenTwoPoles(pSum, ind, prefixMax[ind+1].second) << ", i = " << ind << ", j = " << prefixMax[ind+1].second << endl; 
                ind = prefixMax[ind+1].second; 
            }
        }

        return area; 
    }
    vector<pair<int,int>> prefixMaxFromRight(vector<int>& arr){
        // represents maxElem from ith to (n-1)th index 
        vector<pair<int,int>> prefixMax(arr.size()); 

        int maxElem = -1; // as height cannot be negative 
        int maxInd = -1; 
        for(int i = arr.size() - 1; i >= 0; i--){
            if(maxElem < arr[i]){
                maxElem = arr[i]; 
                maxInd = i; 
            }
            prefixMax[i] = {maxElem, maxInd}; 
        }

        return prefixMax; 
    }

    vector<int> prefixSum(vector<int>& arr){
        vector<int> pSum(arr.size(), 0);
        pSum[0] = arr[0]; 
        for(int i = 1; i < arr.size(); i++){
            pSum[i] += (pSum[i-1] + arr[i]);
        }
        return pSum; 
    }

    int areaCoveredBetweenTwoPoles(vector<int>& pSum, int i, int j){
        if(j - i == 1 || i == j) return 0; 

        return (pSum[j-1] - pSum[i])*1; // 1 represents width of the pole 
    }

    vector<pair<int,int>> nextGreaterElem(vector<int>& arr){
        vector<pair<int,int>> NGE(arr.size()); 
        stack<pair<int,int>> st; 

        for(int i = arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[i] > st.top().first){
                st.pop() ;
            }
            if(st.empty()){
                NGE[i] = {-1,-1}; 
            }
            else{
                NGE[i] = {st.top().first, st.top().second}; 
            }
            st.push({arr[i], i});
        }
        return NGE; 
    }

};



int main(){

    vector<int> arr = {1,0,2,0,3,0,1,0,2,0,0,5}; 

    Solution s = Solution(); 

    cout << s.trap(arr) << endl; 

    return 0; 
}
