/* 
okay so here's my reasoning
Okay so let's say I've a window from l to r-1, which is valid.
Now I'm planning to include r, by including r there can only be two possibilities - either it will make the window invalid or keep it valid.
If it is still valid, then no worries we can proceed even further
But let's say it makes the new window invalid. This only because of one element which is just included in the window. This element's frequency will be k+1, violating the condition.
So we start to shrink the window until we exclude on elem from the left which is equal to the element which made the window invalid. After this exclusion the window will become valid again and we can continue expanding our window.

Now the question - Are we missing out on windows while we are expanding / shrinking?
Okay so there's no problem we expanding as we are literally increasing the size of the window.
So the problem is with shrinking.
Let's say that the window again becomes valid for index = k. So we are actually worrying about the indices (l,k). The thing to note here is the indices (l,k) are invalid so in-order to make the window valid we have to decrease r. Let's say in a very good situation, we have got the window [l+1, r-1]. This is the maximum window possible for the invalid indices (if we are to include r) mentioned earlier.
Even this window is smaller than the window which we have previously found.
So, there's no need to worry about these indices

*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0; 
        int r = 1; // points to the index which is not included in the window YET
        int troublingElem = -1; // -1 represent that no element is violating the condition 
        unordered_map<int,int> map; // {key, value} --> {elem, freq} 
        map.insert({nums[l], 1});
        int answer = 0; 
        while(r < nums.size()){
            // cout << troublingElem << endl; 
            if(troublingElem == -1){
                // valid window
                answer = max(answer, r-l); 
                if(map.find(nums[r]) != map.end()){
                    map[nums[r]]++; 
                    // cout << nums[r] << ": " << map[nums[r]] << endl; 
                    if(map[nums[r]] > k) troublingElem = nums[r]; 
                }
                else{
                    map[nums[r]] = 1; 
                }
                r++; 
            }
            else{
                // cout << nums[l] << endl; 
                if(nums[l] == troublingElem){
                    troublingElem = -1; 
                }
                map[nums[l]]--; 
                l++; 
            }
        }
        
        if(troublingElem == -1) answer = max(answer, r-l); 
        
        return answer; 
    }
};

int main(){

    vector<int> nums = {5,5,5,5,5,5,5}; 
    int k = 3; 

    Solution s = Solution(); 

    cout << s.maxSubarrayLength(nums, k) << endl;

    return 0; 
}
