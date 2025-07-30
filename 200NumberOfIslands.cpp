#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    numOfIslands++; 
                    measureIsland(grid, i, j); 
                }
            }
        }
        return numOfIslands; 
    }
    void measureIsland(vector<vector<char>>& grid, int startX, int startY){
        // here grid[x][y] == '1'
        // this function will find the complete island by checking the horizontal and vertical units and assign the value '2' to them 

        queue<pair<int,int>> q; 
        q.push({startX,startY}); 

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}}; 

        while(!q.empty()){
            int x = q.front().first; 
            int y = q.front().second; 

            q.pop(); 

            for(auto p : directions){
                int newX = x + p.first; 
                int newY = y + p.second; 

                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[x].size() && grid[newX][newY] == '1'){
                    q.push({newX, newY}); 
                    grid[newX][newY] = '2'; 
                }

            }

        }
        

    }
};

int main(){

    Solution s = Solution(); 

    vector<vector<char>> vec = 
    {
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','1'},
        {'0','0','0','0','0'}
    }; 

    
    cout << s.numIslands(vec) << endl;          

    return 0; 
}