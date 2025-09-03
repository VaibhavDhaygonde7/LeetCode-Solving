#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int minPath = __INT_MAX__; 
        recursion(grid, 0, 0, 0, minPath); 

        return minPath; 
    }
    void recursion(vector<vector<int>>& grid, int x, int y, int instantPathSum, int& minPathSum){
        if(x == grid.size() - 1 && y == grid[0].size() - 1){
            cout << grid[x][y] << endl; 
            instantPathSum += grid[x][y]; 
            if(instantPathSum < minPathSum) minPathSum = instantPathSum; 

            return; 
        }

        if(x + 1 < grid.size()){
            cout << grid[x][y] << endl; 
            recursion(grid, x+1, y, instantPathSum + grid[x][y], minPathSum); 
        }

        if(y + 1 < grid[0].size()){
            cout << grid[x][y] << endl; 
            recursion(grid, x, y+1, instantPathSum + grid[x][y], minPathSum); 
        }
    }
};

class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {

        // updating the last row 
        for(int i = grid[0].size()-2; i >= 0; i--){
            grid[grid.size()-1][i] = grid[grid.size()-1][i] + grid[grid.size()-1][i+1];  
        }

        
        for(int i = grid.size()-2; i>=0; i--){
            updateRow(grid, i); 
        }
        
        return grid[0][0]; 
    }
    void updateRow(vector<vector<int>>& grid, int ind){
        grid[ind][grid[0].size() - 1] = grid[ind][grid[0].size() - 1] + grid[ind+1][grid[0].size()-1]; 

        for(int i = grid[0].size() - 2; i >= 0; i--){
            grid[ind][i] = grid[ind][i] + min(grid[ind+1][i], grid[ind][i+1]); 
        }
    }
};

int main(){

    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6}
    }; 

    Solution2 s2 = Solution2(); 

    cout << s2.minPathSum(grid) << endl; 

    return 0; 
}
