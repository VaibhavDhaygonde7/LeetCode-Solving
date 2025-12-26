/*

Sample test-cases - 
1) num = 134152, k = 4 
   so as we know that the resultant will definitely contain m - k digits, we wish to have these digits in the ascending order which may result in the smallest number 
   so what do we wish to have as the first digit. 1,3,4,1,5,2??.. Ig the right option will be 1!
   so res = 1 
   what shall be the next digit??... here m = 6, k = 4, so m-k = 2, hence we need only one digit
   Obviously we shall select 1 again 

2) num = 134152, k = 3 
   res = 112 

3) num = 134152, k = 2 
   res = 1152

4) num = 134152, k = 1
   res = 13152

5) num = 134521, k = 2 
   we can select 1 as the first digit because there still are 5 digits to the right of 1 and we need only 3 more 
   logically we may try to select 2, but we can't because there is only 1 digit to the right of 2 and we need 2 more.
   So Ig we shall try to find 3 and yes here it is. we need 2 more digits and there are 4 digits to the right of 2.
   res = 1321 

6) num = 53731859, k = 3
   m = 8, m - k = 5
   res = 31859

7) num = 6839175930, k = 4
   m = 10, m - k = 6
   available digits = 6,8,3,9,1
   select 1. remaining digits = 5
   res = 1, available digits = 
*/

/*
Observations: 
1) Let's say num contains m digits, so after performing the given operation we will have m - k digits
2) We are having a parameter like remainingDigits, and we can only select a few of the digits from the available digits - Vague, right?
*/

#include <iostream>
#include <stack>
using namespace std; 

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0"; 
        int m = num.length(); 
        int remainingDigits = m - k; 
        int ind = 0; 
        string ans(m-k, '0'); 
        int ansInd = 0; 
        while(ind < m && remainingDigits > 0){
            cout << "Remaining Digits: " << remainingDigits << endl; 
            cout << "Available Choices are: "; 
            // m-ind-1 represents number of digits on the right 
            // instead of cancelling 1 on both sides, I'm keeping them as it is as it helps understand the equation
            int smallestDigit = num[ind] - '0'; 
            int smallestDigitInd = ind; 
            while((m - ind - 1) >= (remainingDigits - 1)){
                if(smallestDigit > (num[ind] - '0')){
                    smallestDigit = num[ind] - '0'; 
                    smallestDigitInd = ind; 
                }
                cout << num[ind] << " "; 
                ind++; 
            }
            cout << endl; 
            cout << "Digit selected: " << num[smallestDigitInd] << endl; 
            ans[ansInd] = num[smallestDigitInd]; 
            ind = smallestDigitInd+1; 
            remainingDigits--; 
            ansInd++; 
        }
        return ans; 
    }
};

// Have a look at this insightful conversation - https://chatgpt.com/c/694e3af3-9d70-8324-9d6c-13af45d260c1

class Solution2{
    public: 
    string removeKdigits(string num, int k){
        int originalK = k; 
        stack<char> st; 
        for(int i = 0; i < num.size() && k > 0; i++){
            // cout << "Element to be pushed: " << num[i] << endl;
            // cout << "Popped elements: "; 
            while(!st.empty() && k > 0 && st.top() > (num[i])){
                // cout << st.top() << " " ; 
                st.pop(); 
                k--; 
            }
            // cout << endl; 
            if(!(k > 0)){
                while(i < num.size()){
                    st.push(num[i]); 
                    i++; 
                }
                break; 
            }
            st.push(num[i]); 
        }
        string ansWithLeadingZeroes;
        while(!st.empty()){
            ansWithLeadingZeroes.push_back(st.top()); 
            st.pop(); 
        }
        // cout << ansWithLeadingZeroes << endl; 
        revStr(ansWithLeadingZeroes); 
        // cout << ansWithLeadingZeroes << endl; 


        // cout << endl ;
        // cout << endInd << endl; 
        // cout << (num.size() - originalK)<< endl; 

        string ans; 
        for(int i = 0; i < (num.size() - originalK); i++){
            if(ans.size() == 0 && ansWithLeadingZeroes[i] == '0'){
                continue;
            }
            ans.push_back(ansWithLeadingZeroes[i]); 
        }
        if(ans.size() == 0) return "0"; 
        return ans;
    }
    void revStr(string& s){
        for(int i = 0; i < s.length()/2; i++){
            swap(s, i, s.length()-i-1); 
        }
    }
    void swap(string& s, int ind1, int ind2){
        char temp = s[ind1]; 
        s[ind1] = s[ind2]; 
        s[ind2] = temp; 
    }
}; 

int main(){

    Solution s = Solution(); 
    Solution2 s2 = Solution2(); 

    // cout << s.removeKdigits("134521", 2) << endl; 
    cout << s2.removeKdigits("10200", 1) << endl; 

    return 0; 
}
