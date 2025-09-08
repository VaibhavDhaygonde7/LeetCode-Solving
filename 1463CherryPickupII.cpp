#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int maxScore = 0 ; 
        int instantScore = grid[0][0] + grid[0][grid[0].size()-1]; 

        traversal(grid, 0, 0, 0, grid[0].size()-1, instantScore, maxScore) ; 

        return maxScore; 
    }

    void traversal(vector<vector<int>>& grid, int x1, int y1, int x2, int y2, int instantScore, int& maxScore){

        if(x1 == grid.size()-1 && x2 == grid.size()-1){
            if(instantScore > maxScore) maxScore = instantScore; 
            return; 
        }

        vector<int> directions = {-1, 0, 1}; 

        for(int n1 : directions){
            if(x1 + 1 < grid.size() && y1 + n1 >= 0 && y1 + n1 < grid[0].size()){
                for(int n2 : directions){
                    if(x2 + 1 < grid.size() && y2 + n2 >= 0 && y2 + n2 < grid[0].size()){
                        if(y1 + n1 != y2 + n2){
                            traversal(grid, x1 + 1, y1 + n1, x2 + 1, y2 + n2, instantScore + grid[x1 + 1][y1 + n1] + grid[x2 + 1][y2 + n2], maxScore);
                        }
                        else{
                            traversal(grid, x1 + 1, y1 + n1, x2 + 1, y2 + n2, instantScore + grid[x1 + 1][y1 + n1], maxScore);
                        }
                    }
                }
            }
        }

    }
};


class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size()); 
        vector<int> one_d(grid[0].size(), -1); 
        vector<vector<int>> two_d(grid[0].size()); 

        for(int i = 0; i < grid[0].size(); i++){
            two_d[i] = one_d; 
        }

        for(int i = 0; i < grid.size(); i++){
            dp[i] = two_d; 
        }

        secondLastRow(grid, dp); 

        // for(int i = 0; i < grid[0].size(); i++){
        //     for(int j = i+1; j < grid[0].size(); j++){
        //         cout << "[" << i << ", " << j << "] = " << dp[grid.size()-2][i][j] << endl; 
        //     }
        // }

        // updateRow(grid, dp, 1); 

        // for(int i = 0; i < grid[0].size(); i++){
        //     for(int j = i+1; j < grid[0].size(); j++){
        //         cout << "[" << i << ", " << j << "] = " << dp[1][i][j] << endl; 
        //     }
        // }

        for(int i = grid.size() - 3; i >= 0; i--){
            updateRow(grid, dp, i); 
        }

        return dp[0][0][grid[0].size()-1]; 

    }

    void updateRow(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int ind){
        vector<int> directions = {-1,0,1}; 

        for(int i = 0; i < grid[0].size(); i++){
            for(int j = i+1; j < grid[0].size(); j++){
                for(int n1 : directions){
                    if(i + n1 >= 0 && i + n1 < grid[0].size()){
                        for(int n2 : directions){
                            if(j + n2 >= 0 && j + n2 < grid[0].size() && i + n1 < j + n2){
                                dp[ind][i][j] = max(dp[ind][i][j], grid[ind][i] + grid[ind][j] + dp[ind+1][i+n1][j+n2]); 
                            }
                        }
                    }
                }
            }
        }

    }

    void secondLastRow(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        vector<int> directions = {-1, 0, 1}; 

        int x = grid.size() - 2; 

        for(int i = 0; i < grid[0].size(); i++){
            for(int j = i+1; j < grid[0].size(); j++){
                for(int n1 : directions){
                    if(i + n1 >= 0 && i + n1 < grid[0].size()){
                        for(int n2: directions){
                            if(j + n2 >= 0 && j + n2 < grid[0].size() && i + n1 < j + n2){
                                dp[x][i][j] = max(dp[x][i][j], grid[x][i] + grid[x][j] + grid[x+1][i+n1] + grid[x+1][j+n2]); 
                                // cout << grid[x][i] << " " << grid[x][j] << " " << grid[x+1][i+n1] << " " << grid[x+1][j+n2] << endl; 
                                // cout << "x: " << x << ", i: " << i << ", j: " << j << ", dp[x][i][j] = " << dp[x][i][j] << endl; 
                            }
                        }
                    }
                }
            }
        }
    }

};



// optimizing space 
class Solution3 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size()); 
        vector<int> one_d(grid[0].size(), -1); 
        vector<vector<int>> next(grid[0].size()); 
        vector<vector<int>> curr(grid[0].size()); 

        for(int i = 0; i < grid[0].size(); i++){
            next[i] = one_d; 
            curr[i] = one_d; 
        }

        secondLastRow(grid, next); 

        // for(int i = 0; i < grid[0].size(); i++){
        //     for(int j = i+1; j < grid[0].size(); j++){
        //         cout << "[" << i << ", " << j << "] = " << next[i][j] << endl; 
        //     }
        // }

        // updateRow(grid, curr, next, 1); 
    

        
        // for(int i = 0; i < grid[0].size(); i++){
        //     for(int j = i+1; j < grid[0].size(); j++){
        //         cout << "[" << i << ", " << j << "] = " << curr[i][j] << endl; 
        //     }
        // }

        // updateRow(grid, curr, next, 0); 
    

        
        // for(int i = 0; i < grid[0].size(); i++){
        //     for(int j = i+1; j < grid[0].size(); j++){
        //         cout << "[" << i << ", " << j << "] = " << curr[i][j] << endl; 
        //     }
        // }


        for(int i = grid.size() - 3; i >= 0; i--){
            updateRow(grid, curr, next, i); 
        }

        return next[0][grid[0].size()-1]; 

    }

    void updateRow(vector<vector<int>>& grid, vector<vector<int>>& curr, vector<vector<int>>& next, int ind){
        vector<int> directions = {-1,0,1}; 

        for(int i = 0; i < grid[0].size(); i++){
            for(int j = i+1; j < grid[0].size(); j++){
                for(int n1 : directions){
                    if(i + n1 >= 0 && i + n1 < grid[0].size()){
                        for(int n2 : directions){
                            if(j + n2 >= 0 && j + n2 < grid[0].size() && i + n1 < j + n2){
                                curr[i][j] = max(curr[i][j], grid[ind][i] + grid[ind][j] + next[i+n1][j+n2]); 
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < grid[0].size(); i++){
            for(int j = i+1; j < grid[0].size(); j++){
                next[i][j] = curr[i][j]; 
            }
        }



    }

    void secondLastRow(vector<vector<int>>& grid, vector<vector<int>>& dp){
        vector<int> directions = {-1, 0, 1}; 

        int x = grid.size() - 2; 

        for(int i = 0; i < grid[0].size(); i++){
            for(int j = i+1; j < grid[0].size(); j++){
                for(int n1 : directions){
                    if(i + n1 >= 0 && i + n1 < grid[0].size()){
                        for(int n2: directions){
                            if(j + n2 >= 0 && j + n2 < grid[0].size() && i + n1 < j + n2){
                                dp[i][j] = max(dp[i][j], grid[x][i] + grid[x][j] + grid[x+1][i+n1] + grid[x+1][j+n2]); 
                            }
                        }
                    }
                }
            }
        }
    }

};



int main(){

    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    }; 

    Solution3 s = Solution3(); 

    cout << s.cherryPickup(grid) << endl; 

    return 0;   
}
