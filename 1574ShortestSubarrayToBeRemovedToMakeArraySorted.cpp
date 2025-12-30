#include <iostream>
#include <vector>
using namespace std; 

// failed solution as I'm fixing the startingPoint too early
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int startingPoint = -1; // indicates starting index of the sub-array which is to be removed
        int endingPoint = -1; 

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1] && endingPoint != i-1){
                // dip encountered!
                if(startingPoint == -1){
                    startingPoint = i; 
                }
                int instantEndingPoint = indOfNextGreaterOrEqual(arr, i, arr[startingPoint-1]) - 1; // reducing by -1, as the index returned by the function won't make the resultant arr unsorted 
                if(instantEndingPoint == -2){
                    return arr.size() - startingPoint; 
                }
                endingPoint = instantEndingPoint;
                i = endingPoint; // for skipping these steps
                cout << startingPoint << " " << endingPoint << endl;  
            }
        }

        return (startingPoint == endingPoint) ? 0 : endingPoint - startingPoint+1; 
    }
    int indOfNextGreaterOrEqual(vector<int>& arr, int dipInd, int minElem){
        // returns index of the next greater or equal elem
        for(int i = dipInd; i < arr.size(); i++){
            if(arr[i] >= minElem) return i; 
        }   
        return -1; 
    }
};

// using bs in third portion of the array
class Solution2{
public: 
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // [0,ind1] no dips, [ind2, arr.size()-1] no dips
        int ind1 = -1;  
        int ind2 = -1; 
        int n = arr.size(); 
        int shortestSubArray = 1000000; 
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                if(ind1 == -1) ind1 = i-1; 
                ind2 = i; 
            }
        }
        if(ind1 == -1) return 0; 

        shortestSubArray = min(shortestSubArray, (n-1) - (ind1+1) + 1); // removing [ind1+1,n-1]
        shortestSubArray = min(shortestSubArray, (ind2 -1) - (0) + 1); // removing [0, ind2-1] 

        cout << "ind1: " << ind1 << ", ind2: " << ind2 << endl; 

        for(int i = 0; i <= ind1; i++){
            int j = findIndexOfGreaterEqualElem(arr, ind2, arr[i]);
            if(j==-1){
                shortestSubArray = min(shortestSubArray, n - (i - 0 + 1)); // [0,i] will be resultant array
                continue;
            }
            cout << i << " " << j << endl; 
            ind2 = j; // narrowing down search for the upcoming iterations 
            //[0,i]..[j..arr.size()-1].. will be resultant array
            shortestSubArray = min(shortestSubArray, (j-1) - (i+1) + 1); 
        }
        return shortestSubArray; 
    }

    int findIndexOfGreaterEqualElem(vector<int>& arr, int j, int elem){
        // here [j, arr.size()-1] is sorted 
        if(arr[arr.size()-1] < elem) return -1; // not including the typical condition of elem > arr[j] because we just want to find out the element which is just greater than or equal to elem
        int low = j; 
        int high = arr.size()-1; 
        while(low <= high){
            int mid = (low + high)/2; 

            if(arr[mid] == elem){
                while(mid >= j && arr[mid] == elem) mid--;
                return mid+1; 
            } 
            
            if(arr[mid] < elem) low = mid+1; 
            else high = mid-1;
        }
        return low; 
    }

}; 

// using two pointers in first and third array
class Solution3{
public: 
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // [0,ind1] no dips, [ind2, arr.size()-1] no dips
        int ind1 = -1;  
        int ind2 = -1; 
        int n = arr.size(); 
        int shortestSubArray = 1000000; 
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                if(ind1 == -1) ind1 = i-1; 
                ind2 = i; 
            }
        }
        if(ind1 == -1) return 0; 

        shortestSubArray = min(shortestSubArray, (n-1) - (ind1+1) + 1); // removing [ind1+1,n-1]
        shortestSubArray = min(shortestSubArray, (ind2 -1) - (0) + 1); // removing [0, ind2-1] 

        cout << "ind1: " << ind1 << ", ind2: " << ind2 << endl; 

        int j = ind2;

        for(int i = 0; i <= ind1; i++){
            while(j < arr.size() && arr[j] < arr[i]) j++; 
            if(j == arr.size()) break; 
            shortestSubArray = min(shortestSubArray, (j-1) - (i+1) + 1); 
        }
        return shortestSubArray; 
    }

}; 

int main(){

    Solution s = Solution(); 
    Solution2 s2 = Solution2(); 

    vector<int> arr = {1,2,3,3,10,1,3,3,5}; 

    // cout << s.findLengthOfShortestSubarray(arr) << endl; 
    cout << s2.findLengthOfShortestSubarray(arr) << endl; 

    cout << s2.findIndexOfGreaterEqualElem(arr, 6, 3) << endl; 

    return 0; 
}
