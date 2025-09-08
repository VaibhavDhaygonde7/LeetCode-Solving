#include <iostream>
#include <vector>
using namespace std; 

// recursive solution 
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
