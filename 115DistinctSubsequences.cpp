#include <iostream>
#include <vector>
using namespace std; 

// recursion
class Solution {
public:
    int numDistinct(string s, string t) {
        int count = recursion(s, t, 0, 0) ;

        return count; 
    }
    
    int recursion(string s, string t, int ind1, int ind2){
        if(ind2 == t.length()){
            return 1; 
        }

        int count = 0; 

        for(int i = ind1; i < s.length(); i++){
            if(s[i] == t[ind2]){
                count += recursion(s, t, i+1, ind2+1); 
            }
        }

        return count; 
    } 

};

// memoization 
class Solution2 {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1)); 
        int count = recursion(s, t,  dp, 0, 0) ;

        return count; 
    }
    
    int recursion(string s, string t, vector<vector<int>>& dp, int ind1, int ind2){
        if(ind2 == t.length()){
            return 1; 
        }

        int count = 0; 

        for(int i = ind1; i < s.length(); i++){
            if(s[i] == t[ind2]){
                if(dp[i+1][ind2+1] == -1){
                    int countFromNextInd = recursion(s, t, dp, i+1, ind2+1); 
                    count += countFromNextInd; 
                    dp[i+1][ind2+1] = countFromNextInd; 
                }
                else{
                    count +=  dp[i+1][ind2+1];  
                }
            }
        }

        return count; 

    } 

};

// tabulation 
class Solution3{
    public:
    int numDistinct(string s, string t) {
        
        if(s.length() < t.length()) return 0; 

        vector<vector<int>> dp(t.length(), vector<int>(s.length(), 0)); 
        updateLastRow(s, t, dp); 

        for(int i = 2; i <= t.length(); i++){
            updateRow(s, t, dp, i); 
        }

        return dp[0][0]; 

    }

    void updateLastRow(string s, string t, vector<vector<int>>& dp){
        if(s[s.length()-1] == t[t.length()-1]) dp[t.length()-1][s.length()-1] = 1; 
        for(int i = s.length()-2; i >= 0; i--){
            dp[t.length()-1][i] = dp[t.length()-1][i+1]; 
            if(s[i] == t[t.length()-1]){
                dp[t.length()-1][i] ++; 
            }
        }
    }

    void updateRow(string s, string t, vector<vector<int>>& dp, int ind){
        for(int i = s.length()-ind; i >= 0; i--){
            if(s[i] == t[t.length()-ind]){
                dp[t.length()-ind][i] = dp[t.length()-ind][i+1] + dp[t.length()-ind+1][i+1]; 
            }
            else{
                dp[t.length()-ind][i] = dp[t.length()-ind][i+1]; 
            }
        }
    }

}; 

int main(){

    Solution3 s = Solution3(); 

    cout << s.numDistinct("babgbag", "bag") << endl; 

    return 0; 
}
