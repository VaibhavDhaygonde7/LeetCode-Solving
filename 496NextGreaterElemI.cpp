#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std; 



unordered_map<int, int> nextGreaterElem(vector<int>& arr){
    stack<int> st; 
    unordered_map<int, int> map; 
    for(int i = arr.size() - 1; i >= 0; i--){
        while(st.size() && st.top() < arr[i]) st.pop(); 
        if(st.size()){
            map.insert({arr[i], st.top()});
            
        }
        else{
            map.insert({arr[i], -1});
        }
        st.push(arr[i]); 
    }
    return map; 
}


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map = nextGreaterElem(nums2);
    for(int i = 0; i < nums1.size(); i++){
        nums1[i] = map[nums1[i]]; 
    }   
    return nums1; 
}

int main(){

    vector<int> arr = {1,3,4,2}; 

    nextGreaterElem(arr); 

    return 0; 
}
