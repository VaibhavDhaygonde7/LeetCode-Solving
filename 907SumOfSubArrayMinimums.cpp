/*

okay so here are my observations: 1) The first question I should ask myself is, how do I produce all the sub-arrays? I'll have a startingPoint and endingPoint. endPoint will range from [startingPoint, n-1] startingPoint will range from [0, n-1] 2) As we know how to produce all the sub-arrays, we should also try to find the minimum. An element is the minimum of a sub-array until we include an element which is smaller than this instantaneous minimum itself! Let's say I've a sub-array of size 5, and the minimum is 3. By extending the endingPoint of the sub-array, I'll increase this the size and while doing so if I include an element smaller than 3 itself then the new minimum is this new element. Let's say we encounter the new element when sub-array becomes of size 8 So for sizes, 5,6,7 the minimum will be 3. As we wish to count the sum of sub-array minimums, we can simply say 3*(7-5+1) should be added to the answer. Brute Force way. While creating our sub-array in the double for loop, keep the track of minimum element and add it to the answer. Is this the best way? We are iterating through elements multiple times. We don't need to do this. Better approach. Let's say startingPoint points to index ind. arr[startingPoint] will be the minimum of the sub-array which we are going to construct by extending endingPoint. arr[startingPoint] will continue to be the minimum element of the sub-arrays until we include an element smaller than arr[startingPoint]. Let's say when endingPoint = ind1, we encounter next smaller element. Now this new minimum element will continue to be the smallest element in the sub-array until we encounter yet another next smaller element. So, this problem boils down to finding next smaller element and simply multiplying the instant minimum elements with their contribution in the total sub-arrays.

*/

#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> st; // we are going to using vector as stack because we can iterate through the vector and not from the stack 

        long long answer = 0; 
        int mod = 1000000007; 

        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st[st.size() - 1]] > arr[i]) st.pop_back(); 

            // cout << "Element: " << arr[i] << endl; 

            st.push_back(i); 

            for(int j = st.size() - 1; j > 0; j--){
                // st[j] represents index of an element and st[j-1] represents the index of even smaller element
                // it is pretty obvious that st[j-1] > st[j] as we are talking "NEXT SMALLER ELEMENT" 
                // so arr[st[j]] is smallest the in the range [i, [st[j], st[j-1)].

                // cout << "Element: " << arr[st[j]] << ", Contribution: " << (st[j-1] - st[j]) << endl; 

                answer %= mod; 
                answer += (arr[st[j]] * (st[j-1] - st[j])); 
                answer %= mod; 
            }

            // let's add the contribution of smallest element of all arr[st[0]]. We can't simply say arr[st[0]] has contribution of st[0-1] - st[0], because st[0-1] is not defined. So this element is the smallest till the end of the array 

            // cout << "Contribution of Smallest Element: " << arr[st[0]] << " is " << (arr.size() - 1 - (st[0]) + 1) << endl; 
            // cout << endl; 
            answer += ((arr[st[0]]) * ((arr.size()-1) - (st[0]) + 1)); 
            answer %= mod; 

        }

        return answer; 
    }
};


class Solution2 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int, long long>> st; // we are going to using vector as stack because we can iterate through the vector and not from the stack 

        long long answer = 0; 
        int mod = 1000000007; 

        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st[st.size() - 1].first] > arr[i]) st.pop_back(); 

            if(st.empty()){
                // contribution will be arr[i] multiplied by (arr.size()-1 -i + 1) because arr[i] is the smallest element in the range [i, n-1]
                long long contribution = ((long long)arr[i])*((arr.size() - 1) - i + 1); 
                st.push_back({i, contribution}); 
            }
            else{
                // total contribution till now will be arr[i] multiplied by it's frequency and we will add the contribution till the previous element. In this way contribution is stacked for the remaining sub-arrays and we don't we have to re-calculate it everytime like we did in our previous solution 
                // cout << "My contribution: " << (((long long)arr[i]) * (st[st.size()-1].first - i)%mod) << ", Remaining Sub-array's contribution:  " << (st[st.size() - 1].second%mod) << endl; 

                // NOTE: the frequency for minimumElem = arr[i] is st[st.size()-1].first - i.. because it lies in the range [i, st[st.size)()-1].first - 1];
                long long contribution = ((((long long)arr[i]) * (st[st.size()-1].first - i)%mod) + (st[st.size() - 1].second%mod))%mod; 
                st.push_back({i, contribution}); 
            }

            // cout << "Element: " << arr[i] << " " << ", Contribution of all sub-arrays starting from index: " << i << " = " << st[st.size()-1].second << endl;
            
            answer %= mod; 
            answer += st[st.size()-1].second; 
            answer %= mod; 

        }

        return answer; 
    }
};


int main(){

    Solution s = Solution(); 
    Solution2 s2 = Solution2(); 

    vector<int> arr = {3}; 

    cout << s2.sumSubarrayMins(arr) << endl; 

    return 0; 
}
