
/*
okay so here are my key observations:
1) We are going to flip the bits in a sequential order. I really don't think there's any point in flipping a 0 which has 0's on both the sides. Let's call this as "isolated zero".
Let's say index i is an isolated zero. I'm not trying to imply that we should discard the flipping of this index completely, as it may not be isolated zero any more in the future.

2) Initially I thought about the greedy approach of expanding the existing longest sub-array let's say of size of m. But let's say there are two sub-arrays of size m-1 which only have a single 0 in between them. Flipping such bit will result in 2*m - 1 sub-array. So yeah, greedy won't always work.

3) We can have a list of potential candidates, meaning indices pointing to zero and the impact of flipping of each index.
Let's say there's a sub-array 1110000. Flipping of the first zero will result in a sub-array of size 4, hence it's impact is decent.
But let's say there's a sub-array 1110111, the flipping of such bit will result with sub-array 7, hence impact is profound.

I know not the most optimal way, but throwing it out here, that we can iterate through the complete potential list and flip bits according to the potential resultant. But, again we have update to the complete potential list, which will be really really expensive.

4) I don't know how to implement this but, we can try to find a sub-array which is just short of k flips.
Here's my vague idea.
Let's say we are at index ind, and [0,ind] contains m zeroes, let m>k
Then we can find out the index of the sub-array having m-k indices, which will give us another index, say ind2.
Now [ind2, ind] contains exactly k zeroes which can be flipped and the resulting sub-array will be of the size ind-ind2 + 1. We can do this for each sub-array and we may get our answer

My brain was mostly going through the idea of dp, flip a bit, don't flip a bit, check the resultant, but it will take hell of a time. 4th point seems to be key, but should be more refined
*/


#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0; 
        int r = 1; 
        int numOfZeroes = (nums[l] == 0) ? 1 : 0; 

        int answer = 0; 

        while(r < nums.size()){
            if(numOfZeroes <= k){
                // window is valid 
                answer = max(answer, r-l); 
                numOfZeroes += (nums[r] == 0) ? 1 : 0;
                r++; 
            }
            else{
                numOfZeroes -= (nums[l] == 0) ? 1 : 0; 
                l++; 
            }
        }

        if(numOfZeroes <= k) answer = max(answer, r-l); 

        return answer; 
    }   
};

int main(){

    Solution s = Solution(); 

    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; 
    int k=3; 

    cout << s.longestOnes(nums, k) << endl; 

    return 0;   
}
