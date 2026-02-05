#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ll = long long; 
struct State{
    ll peak; 
    ll valley; 
    ll totalSum ; 
    ll maxSum; 
    int state; // 0 --> down-wards, 1 --> upwards, 2 --> flat , 3 --> last elem
    int startInd; 
    int endInd; 
    ll maxSumWhileIncreasing; 
}; 

void setMaxSumWhileIncreasing(struct State* instantState, vector<int>& nums){
    ll maxSum = 0; 
    bool maxSumSet = false; 
    ll instantSum = 0; 
    int ind = instantState->startInd+1; 
    while(ind <= instantState->endInd){
        instantSum += nums[ind]; 
        if(!maxSumSet){
            maxSum = instantSum; 
            maxSumSet = true; 
        }
        else{
            maxSum = max(maxSum, instantSum); 
        }
        ind++; 
    }
    instantState->maxSumWhileIncreasing = maxSum; 
}

void setMaxSum(struct State* instantState, vector<int>& nums){
    if(instantState->state == 1){
        int numOfElemsInMiddle = (instantState->endInd - 1) - (instantState->startInd + 1) + 1; 
        instantState->maxSum = nums[instantState->endInd-1]; 
        int ind = instantState->endInd-2; 
        while(ind >= instantState->startInd){
            if(nums[ind] < 0) break; 
            instantState->maxSum += nums[ind]; 
            ind--; 
        }
    }
    else if(instantState->state == 0){
        instantState->maxSum = 0; 
        int ind = instantState->startInd ; 
        while(ind <= instantState->endInd){
            instantState->maxSum+=nums[ind]; 
            ind++; 
        }
    }
}

struct State* getCurrState(vector<int>& nums, int ind){
    struct State* instantState = new struct State; 
    if(ind + 1 < nums.size()){
        if(nums[ind+1] == nums[ind]){
            instantState->state = 2; 
            int endInd = ind+1; 
            while(endInd < nums.size() && nums[ind] == nums[endInd]){
                endInd++; 
            }
            instantState->endInd = endInd-1; 
        }
        else if(nums[ind+1] > nums[ind]){
            instantState->state = 1; 
            instantState->startInd = ind; 
            instantState->valley = nums[ind]; 
            instantState->totalSum = nums[ind]; 
            int endInd = ind+1; 
            while(endInd < nums.size() && nums[endInd] > nums[endInd-1]){
                instantState->totalSum += nums[endInd]; 
                endInd++; 
            }
            instantState->endInd = endInd - 1; 
            instantState->peak = nums[endInd-1]; 
            setMaxSum(instantState, nums); 
            setMaxSumWhileIncreasing(instantState, nums); 
        }
        else{
            // nums[ind+1] < nums[ind]
            instantState->state = 0; 
            instantState->startInd = ind; 
            instantState->peak = nums[ind]; 
            instantState->totalSum = nums[ind]; 
            int endInd = ind+1; 
            while(endInd < nums.size() && nums[endInd] < nums[endInd-1]){
                instantState->totalSum += nums[endInd]; 
                endInd++; 
            }
            instantState->endInd = endInd-1; 
            instantState->valley = nums[endInd-1]; 
            setMaxSum(instantState, nums); 
        }
    }
    else{
        instantState->state = 3; 
        instantState->endInd = nums.size(); 
    }
    return instantState; 
}

void printStateInfo(struct State* state){
    cout << "State: " << state->state << endl; 
    cout << "Peak: " << state->peak << endl; 
    cout << "Valley: " << state->valley << endl; 
    cout << "TotalSum: " << state->totalSum << endl; 
    cout << "MaxSum: " << state->maxSum << endl; 
    cout << "MaxSumWhileIncreasing: " << state->maxSumWhileIncreasing << endl; 
    cout << "StartInd: " << state->startInd << endl; 
    cout << "EndInd: " << state->endInd << endl; 
}

bool isValidTriplet(vector<struct State*>& states, int ind){

    if(ind+2 < states.size()){
        if(states[ind]->state == 1 && states[ind+1]->state == 0 && states[ind+2]->state == 1){
            return true; 
        }
    }
    return false; 

}

ll getMaxValueFromTriplet(vector<struct State*>& states, int ind){
    // here the triplets are definitely valid
    ll maxSum = states[ind]->maxSum + states[ind+1]->totalSum + states[ind+2]->maxSumWhileIncreasing;
    return maxSum; 
}



class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        // struct State* instantState = getCurrState(nums, 0); 
        // printStateInfo(instantState); 

        vector<struct State*> states; 
        int ind = 0; 

        while(ind < nums.size()){
            struct State* instantState = getCurrState(nums, ind); 
            states.push_back(instantState);
            printStateInfo(instantState);  
            cout << "---------------------------------" << endl; 
            ind = instantState->endInd; 
        }

        bool isMaxSumSet = false; 
        ll maxSum = -1;
        for(int i = 0; i < states.size(); i++){
            if(isValidTriplet(states, i)){
                ll instantAnswer = getMaxValueFromTriplet(states, i); 
                if(!isMaxSumSet){
                    maxSum = instantAnswer; 
                    isMaxSumSet = true; 
                }
                else{
                    maxSum = max(maxSum, instantAnswer); 
                }
            }
        }

        return maxSum; 
    }
};
int main(){

    // int t;
    // freopen("input.txt", "r", stdin);
    // cin >> t;
/*
    while(t--){
        int n; 
        cin >> n; 
        
        vector<int> nums(n); 

        for(int i = 0; i < n; i++) cin >> nums[i]; 
        for(int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << endl; 

        struct State* instantState = getCurrState(nums, 0); 
        printStateInfo(instantState); 

        vector<struct State*> states; 
        int ind = 0; 

        while(ind < nums.size()){
            struct State* instantState = getCurrState(nums, ind); 
            states.push_back(instantState); 
            ind = instantState->endInd; 
        }

        bool isMaxSumSet = false; 
        int maxSum = -1;
        for(int i = 0; i < states.size(); i++){
            if(isValidTriplet(states, i)){
                int instantAnswer = getMaxValueFromTriplet(states, i); 
                if(!isMaxSumSet){
                    maxSum = instantAnswer; 
                    isMaxSumSet = true; 
                }
                else{
                    maxSum = max(maxSum, instantAnswer); 
                }
            }
        }

        cout << maxSum << endl; 

    }

*/

    vector<int> nums = {1,4,2,7}; 
    Solution s = Solution(); 

    cout << s.maxSumTrionic(nums) << endl; 


    return 0;
}
