#include <iostream> 
#include <stack> 
#include <vector>
using namespace std; 


// my attempted solution  
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int,int>> nextSmallerElems(arr.size());
        int ptr = arr.size(); // points to the last unfilled cell 
        int count = 0 ;
        for(int i = arr.size() - 1; i >=0; i--){
            while(ptr != arr.size() && arr[i] <= nextSmallerElems[ptr].first){
                ptr++; 
            }
            ptr--; 
            nextSmallerElems[ptr] = {arr[i], i}; 
            // cout << arr[i] << ": \n"; 
            // basically we are considering ith element as the starting-point of the sub-array.
            // the following loop chops all the sub-arrays based on minimum elements of the sub-array
            for(int i = ptr; i < arr.size(); i++){
                // cout << "["<< nextSmallerElems[i].first << ", " << nextSmallerElems[i].second << "], "; 
                int lastInd; 
                if(i + 1 < arr.size()){
                    lastInd = nextSmallerElems[i+1].second - 1;
                }
                else{
                    lastInd = arr.size() - 1; 
                }
                // cout << "Contribution: " << (nextSmallerElems[i].first*(lastInd - nextSmallerElems[i].second + 1));  
                count+= nextSmallerElems[i].first*(lastInd - nextSmallerElems[i].second + 1); 
            }
            // cout << endl; 
        }
        return count; 
    }
};

// one more attempt - but with stack 
struct Node{
    int elem; 
    int ind; 
    long long sum; 
}; 

class Solution2{
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<Node> st; 
        long long count = 0; 
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top().elem >= arr[i]){
                st.pop(); 
            }
            int lastInd; 
            long long contribution = 0; 
            if(!st.empty()){
                lastInd = st.top().ind - 1; 
                contribution += st.top().sum; 
            }
            else{
                lastInd = arr.size() - 1; 
            }
            contribution %= 1000000007; 
            contribution += (arr[i] * (lastInd - i + 1)); 
            contribution %= 1000000007; 
            count += contribution; 
            count %= 1000000007; 
            st.push({arr[i], i, contribution}); 
        }
        return count; 
    }
};

int main(){

    vector<int> arr = {3,1,2,4}; 
    
    Solution2 s2 = Solution2(); 
    Solution s = Solution(); 

    cout << s2.sumSubarrayMins(arr) << endl; 

    return 0;  
}
