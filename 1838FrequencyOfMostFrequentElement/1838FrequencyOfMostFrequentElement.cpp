#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int r = 1; // the element which is considered as most frequent element 
        int l = 0; // pointing to the elements which are not made equal yet
        int instantK = 0; 
        int maxPossibleFrequency = 1; 

        while(r < nums.size()){
            cout << "InstantK at the start of loop: " << instantK << endl; 
            if(l < 0){
                if(instantK > k){
                    instantK -= (nums[r] - nums[l+1]); 
                    l++; 
                }
                else{
                    maxPossibleFrequency = max(maxPossibleFrequency, r-(l+1)+1); 
                    if(r+1 >= nums.size()) break; 
                    // we have [l+1, r] all equal to nums[r] 
                    int equalElems = nums[r]; 

                    cout << "InstantK: " << instantK << ", Equal Plateau: " << equalElems << endl; 
                    cout << "nums[r+1]: " << nums[r+1] << " nums[r]: " << nums[r] << endl;
                    // so we have to increase all these elements to nums[r+1] given it exists
                    instantK += ((nums[r+1] - nums[r])*(r - (l+1) + 1)); 
                    r++; 
                }
            }
            else if(instantK <= k){
                maxPossibleFrequency = max(maxPossibleFrequency, r - (l+1) + 1); 
                instantK += (nums[r] - nums[l]); 
                l--;
                if(instantK > k){
                    // means we have just broke the window and extend the window here itself
                    l++; 
                    instantK -= (nums[r] - nums[l]); 
                    if(r+1 >= nums.size()) break; 
                    // we have [l+1, r] all equal to nums[r] 
                    int equalElems = nums[r]; 
                    // so we have to increase all these elements to nums[r+1] given it exists
                    instantK += ((nums[r+1] - nums[r])*(r - (l+1) + 1)); 
                    r++; 
                }
            }
            else{
                // we have to shorten the window 
                instantK -= (nums[r] - nums[l+1]); 
                l++; 
            }
            cout << "l: " << l << ", r: " << r << endl; 
        }
        return maxPossibleFrequency; 
    }
};

int main(){

    Solution s = Solution(); 

    vector<int> arr = {3,9,6}; 
    int k = 8; 

    cout << s.maxFrequency(arr, k) << endl; 

    return 0;   
}
