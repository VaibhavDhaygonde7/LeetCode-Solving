#include <iostream>
#include <vector>
using namespace std; 


// this is wrong 
class Solution {
public:
    int mod = 1000000007;
    int totalStrength(vector<int>& strength) {
        vector<long long> pSum = createPrefixSum(strength);
        
        vector<long long> sumOfAllSubArr = calculateSumOfAllSubArraysTillInd(strength, pSum); 

        // for(int i = 0; i < strength.size(); i++){
        //     for(int j = i; j < strength.size(); j++){
        //         for(int k = j; k < strength.size(); k++){
        //             cout << "[i,j,k]" << ": [" << i << "," << j << "," << k << "], " << toFind(pSum, i, j, k, sumOfAllSubArr[k], (j-1 < 0) ? 0 : sumOfAllSubArr[j-1]) << endl;
        //         }
        //     }
        // }

        
        vector<pair<int, long long>> st; 
        long long answer = 0; 

        vector<int> NSE = createNSE(strength); 
        vector<int> PSE = createPSE(strength); 

        for(int j = 0; j < strength.size(); j++){
            cout << "Element: " << strength[j] << "[" << PSE[j] << ", " << NSE[j] << "]" << endl; 
            int i, k;
            if(PSE[j] == -1){
                // there's no previous smaller element
                i = 0; 
            }
            else{
                i = PSE[j] + 1; // as our sub-array's startingPoint will not include PSE's index 
            }
            // j is j...
            if(NSE[j] == -1){
                // there's not Next Smaller Element
                k = strength.size()-1; // as everything ends here ;)
            }
            else{
                k = NSE[j] - 1; // as our sub-array's endingPoint will not include NSE's index 
            }
            cout << "i,j,k: " << i << " " << j << " " << k << endl;
            long long contribution = strength[j]*toFind(pSum, i, j, k, sumOfAllSubArr[k], (j-1 < 0) ? 0 : sumOfAllSubArr[j-1]); 

            cout << contribution << endl; 
            answer+= contribution; 
        }


        return answer; 
    }

    vector<int> createNSE(vector<int>& arr){
        vector<int> NSE(arr.size()); 
        vector<int> st; 
        for(int i = arr.size() - 1; i>= 0; i--){
            while(!st.empty() && arr[i] <= arr[st[st.size()-1]]) st.pop_back(); 
            NSE[i] = (st.empty()) ? -1 : st[st.size()-1]; 
            st.push_back(i); 
        }
        return NSE; 
    }
    vector<int> createPSE(vector<int>& arr){
        vector<int> PSE(arr.size()); 
        vector<int> st; 
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[i] <= arr[st[st.size()-1]]) st.pop_back(); 
            PSE[i] = (st.empty()) ? -1 : st[st.size()-1]; 
            st.push_back(i); 
        }
        return PSE; 
    }

    long long toFind(vector<long long>& pSum, int i, int j, int k, long long bk, long long bjMinus1){
        // returns the following
        /*
        arr[i] + arr[i+1]... arr[j-1] + arr[j] +
        arr[i] + arr[i+1]... arr[j-1] + arr[j] + arr[j+1]
        ...
        arr[i] + arr[i+1]... arr[j-1] + arr[j] + arr[j+1] + ... arr[k-1] + arr[k]
        */
        int m = k-j+1;
        return (subArrSum(pSum, i,j-1)*m) + bk - bjMinus1 - (subArrSum(pSum,0,j-1)*m); 
    }

    long long subArrSum(vector<long long>& pSum, int ind1, int ind2){
        // returns arr[ind1] + arr[ind1+1] + ... arr[ind2-1] + arr[ind2]
        return ((ind2 < 0) ? 0 : pSum[ind2]) - ((ind1-1 < 0) ? 0 : pSum[ind1-1]); 
    }

    vector<long long> createPrefixSum(vector<int>& arr){
        vector<long long> pSum(arr.size()); 
        pSum[0] = arr[0]; 

        for(int i = 1; i < arr.size(); i++){
            pSum[i] = arr[i] + pSum[i-1];  
        }

        return pSum; 
    }

    vector<long long> calculateSumOfAllSubArraysTillInd(vector<int>& arr, vector<long long>& pSum){
        vector<long long> sumOfAllSubArr(arr.size()); 
        // sumOfAllSubArr[i] indicates sum of all sub-arrays with the startingPoint 0 till index i 
        /*
        // sumOfAllSubArr[i] = arr[0] +
                               arr[0] + arr[1] + 
                               arr[0] + arr[1] + arr[2]
                               .
                               . 
                               arr[0] + arr[1] + arr[2]... arr[i]
        */

        sumOfAllSubArr[0] = arr[0]; 

        for(int i = 1; i < arr.size(); i++){
            cout << pSum[i] << " " << sumOfAllSubArr[i-1] << endl; 
            sumOfAllSubArr[i] = pSum[i] + sumOfAllSubArr[i-1]; 
        }
                               
        return sumOfAllSubArr; 
    }

};

/*
Okay so hear me out!!... I've solved the damn question and here's my explanation

So basically we have to find all the sub-arrays and multiply with the sub-array's minimum
So what I did was: ... I assumed that the current element is the smallest element and and found the next and previous smaller element

But here's the catch... while finding previous smaller element, I did stop even when I got an element which is equal to the current element... Why?? Because I'm going to simply repeat the sub-arrays, as I have already counted the sub-arrays when I was at that element in one of my previous iterations
But I didn't do the same while finding out next smaller element because, you know what I mean, that's common sense.

Let's say I'm on index j.
I've PSE index as i and NSE's index as k 
So the thing is.... the startingPoint of the sub-array can be i<=ind<j and endingPoint can be j<=ind<=k

So what I did is.... calculate all the sub-arrays starting from j and ending in the range j <= ind <= k
More formally I calcuated: 
a[j]
a[j] + a[j+1]
a[j] + a[j+1] + a[j+2]
....
a[j] + a[j+1] + a[j+2].....+ a[k-1] + a[k]......... (1)
Now how did I do it?
Basically I've pSumOfSubarrayToRight which represent
pSumOfSubarrayToRight[i] = a[0] + 
                                                            a[0] + a[1]
                                                             ....
                                                            a[0] + a[1] .... + a[i]
So I simply subtracted: pSumOfSubarrayToRight[k] - pSumOfSubarrayToRight[j-1] and also trimmed out the extra a[0] + a[1]... a[j-1] which appear k-j+1 times.

Now I did the same for i to j-1, you know what the function returns, just read the comment
so we have our answers as : 
                           a[j-1] + 
              a[j-2]+a[j-1] + 
                    ....
a[i] + ....a[j-2]+a[j-1]................(2)

Now the thing which I described above will appear k-j+1 times because we have that many endingPoints. On the other hand, the additions on the point (1) will appead (j-1) - i + 1 + (1)
This "(1)" in the bracket is special as even if there are startingPoints available, the addition at point 2 will still be responsible for contribution

Got an AC as well :)
Great question, I struggled with it for a lot of time

Okay so hear me out!!... I've solved the damn question and here's my explanation

So basically we have to find all the sub-arrays and multiply with the sub-array's minimum
So what I did was: ... I assumed that the current element is the smallest element and and found the next and previous smaller element

But here's the catch... while finding previous smaller element, I did stop even when I got an element which is equal to the current element... Why?? Because I'm going to simply repeat the sub-arrays, as I have already counted the sub-arrays when I was at that element in one of my previous iterations
But I didn't do the same while finding out next smaller element because, you know what I mean, that's common sense.

Let's say I'm on index j.
I've PSE index as i and NSE's index as k 
So the thing is.... the startingPoint of the sub-array can be i<=ind<j and endingPoint can be j<=ind<=k

So what I did is.... calculate all the sub-arrays starting from j and ending in the range j <= ind <= k
More formally I calcuated: 
a[j]
a[j] + a[j+1]
a[j] + a[j+1] + a[j+2]
....
a[j] + a[j+1] + a[j+2].....+ a[k-1] + a[k]......... (1)
Now how did I do it?
Basically I've pSumOfSubarrayToRight which represent
pSumOfSubarrayToRight[i] = a[0] + 
                                                            a[0] + a[1]
                                                             ....
                                                            a[0] + a[1] .... + a[i]
So I simply subtracted: pSumOfSubarrayToRight[k] - pSumOfSubarrayToRight[j-1] and also trimmed out the extra a[0] + a[1]... a[j-1] which appear k-j+1 times.

Now I did the same for i to j-1, you know what the function returns, just read the comment
so we have our answers as : 
                           a[j-1] + 
              a[j-2]+a[j-1] + 
                    ....
a[i] + ....a[j-2]+a[j-1]................(2)

Now the thing which I described above will appear k-j+1 times because we have that many endingPoints. On the other hand, the additions on the point (1) will appead (j-1) - i + 1 + (1)
This "(1)" in the bracket is special as even if there are startingPoints available, the addition at point 2 will still be responsible for contribution

Got an AC as well :)
Great question, I struggled with it for a lot of time


*/






class Solution2{
public: 

    int mod = 1000000007;
    int totalStrength(vector<int>& strength) {
        vector<long long> pSum = createPrefixSum(strength); 
        vector<long long> pSumOfSubArrToRight = createPrefixSumOfSubArraysToRight(pSum); 
        vector<long long> pSumOfSubArrToLeft = createPrefixSumOfSubArraysToLeft(pSum); 

        vector<int> NSE = createNSE(strength); 
        vector<int> PSE = createPSE(strength);  

        long long answer = 0; 

        for(int j = 0; j < strength.size(); j++){
            // cout << "Element: " << strength[j] << endl;
            int i, k; 
            if(PSE[j] == -1){
                i = 0;
            }
            else i = PSE[j] + 1; 
            if(NSE[j] == -1){
                k = strength.size()-1; 
            }
            else k = NSE[j] - 1; 
            long long contribution; 
            // if(i != j){
            //     contribution = strength[j] * (ItoJ(pSumOfSubArrToLeft, pSum, i, j-1) * JtoK(pSumOfSubArrToRight, pSum, j, k) +); 
            // }
            // else{
            //     contribution = strength[j] * (JtoK(pSumOfSubArrToRight, pSum, j, k)); 
            // // }
            // cout << "ItoJ-1: " << ItoJ(pSumOfSubArrToLeft, pSum, i, j-1) << endl; 
            // cout << "How many endingPoints?: " << k-j+1 << endl; 
            // cout << "JtoK: " << JtoK(pSumOfSubArrToRight, pSum, j, k) << endl; 
            // cout << "How many startingPoints?: " << (j-1) - i + 1 + (1) << endl; 

            contribution = ItoJ(pSumOfSubArrToLeft, pSum, i, j-1)*(k-j+1) + JtoK(pSumOfSubArrToRight, pSum, j, k)*((j-1) - i + 1 + (1)); 
            answer += contribution*strength[j];

            // cout << endl;
        }

        return answer; 
    }


    vector<int> createNSE(vector<int>& arr){
        vector<int> NSE(arr.size()); 
        vector<int> st; 
        for(int i = arr.size() - 1; i>= 0; i--){
            while(!st.empty() && arr[i] <= arr[st[st.size()-1]]) st.pop_back(); 
            NSE[i] = (st.empty()) ? -1 : st[st.size()-1]; 
            st.push_back(i); 
        }
        return NSE; 
    }
    vector<int> createPSE(vector<int>& arr){
        vector<int> PSE(arr.size()); 
        vector<int> st; 
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[i] < arr[st[st.size()-1]]) st.pop_back(); 
            PSE[i] = (st.empty()) ? -1 : st[st.size()-1]; 
            st.push_back(i); 
        }
        return PSE; 
    }


    long long JtoK(vector<long long>& pSumOfSubArrToRight, vector<long long>& pSum, int j, int k){
        /*
        returns arr[j]
                arr[j] + arr[j+1]
                ....
                arr[j] + arr[j+1] ... arr[k]
        */
    //    if(j == k) return subArrSum(pSum, j, j) ;
        return pSumOfSubArrToRight[k] - ((j-1 < 0) ? 0 : pSumOfSubArrToRight[j-1]) - ((k-j+1)*subArrSum(pSum, 0, j-1)); 
    }   

    long long subArrSum(vector<long long>& pSum, int ind1, int ind2){
        return ((ind2 < 0) ? 0 : pSum[ind2]) - ((ind1-1 < 0) ? 0 : pSum[ind1-1]);
    }

    long long ItoJ(vector<long long>& pSumOfSubArrToLeft, vector<long long>& pSum, int i, int j){
        /*
            returns                     arr[j]+
                               arr[j-1]+arr[j]+
                    arr[i]+....arr[j-1]+arr[j]
        */

        return pSumOfSubArrToLeft[i] - ((j+1 >= pSum.size()) ? 0 : pSumOfSubArrToLeft[j+1]) - ((j-i+1)*subArrSum(pSum, j+1, pSum.size()-1)); 
    }

    vector<long long> createPrefixSum(vector<int>& arr){
        /*
        pSum[i] = arr[0] + arr[1] + ... arr[i]
        */
        vector<long long> pSum(arr.size()); 
        pSum[0] = arr[0]; 

        for(int i = 1; i < arr.size(); i++){
            pSum[i] = arr[i] + pSum[i-1]; 
        }
        return pSum; 
    }

    vector<long long> createPrefixSumOfSubArraysToRight(vector<long long>& pSum){
        /*
        // pSumOfSubArrayRight[i] = arr[0] + 
                                    arr[0] + arr[1] + 
                                    ...
                                    arr[0] + arr[1] + ... + arr[i]
        */
        vector<long long> pSumOfSubArrToRight(pSum.size()); 
        pSumOfSubArrToRight[0] = pSum[0]; 

        for(int i = 1; i < pSum.size(); i++){
            pSumOfSubArrToRight[i] = pSumOfSubArrToRight[i-1] + pSum[i]; 
        }
        return pSumOfSubArrToRight;
    }

    vector<long long> createPrefixSumOfSubArraysToLeft(vector<long long>& pSum){
        /*
        pSumOfSubArrToLeft[i] =                      a[n-1]+
                                              a[n-2]+a[n-1]+
                                a[i]+.. ....  a[n-2]+a[n-1]
        */
        vector<long long> pSumOfSubArrToLeft(pSum.size()); 
        pSumOfSubArrToLeft[pSumOfSubArrToLeft.size()-1] = pSum[pSum.size()-1] - ((pSum.size()-2 < 0) ? 0 : pSum[pSum.size()-2]); 
        // cout << (pSum[pSum.size()-1] - (pSum.size()-2 < 0) ? 0 : pSum[pSum.size()-2]) << endl;
        for(int i = pSum.size()-2; i>=0; i--){
            pSumOfSubArrToLeft[i] = pSumOfSubArrToLeft[i+1] + pSum[pSum.size()-1] - ((i-1 < 0) ? 0 : pSum[i-1]); 
        }
        return pSumOfSubArrToLeft; 
    }

};

int main(){


    vector<int> strength = {1}; 

    /*
        3 + 1 = 4
        1 = 1
        1 + 2 = 3
        3 + 1 + 2 = 6
    */

    Solution2 s2 = Solution2(); 

    cout << s2.totalStrength(strength) << endl; 

    return 0;
}
