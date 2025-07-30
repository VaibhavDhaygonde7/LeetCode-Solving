#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea, findAreaOfIsland(grid, i, j)); 
                }
            }
        }

        return maxArea; 
    }
    int findAreaOfIsland(vector<vector<int>>& grid, int x, int y){
        // here grid[x][y] == 1, which means island 
        queue<pair<int,int>> q; 
        pair<int,int> p (x,y); 
        q.push(p); 
        int area = 1; // as grid[x][y] == 1, area will begin with 1 
        while(!q.empty()){
            // cout << "x: " << q.front().first << ", y: " << q.front().second << endl; 
            area = findNeighbouringIslands(grid, q, area); 
            q.pop(); 
        }
        return area; 
    }
    int findNeighbouringIslands(vector<vector<int>>& grid, queue<pair<int,int>>& q, int area){

        // this function finds the neighbouring islands and adds the area of this islands to the area which is passed in this function

        int x = q.front().first; 
        int y = q.front().second; 

        
        if(x>0){
            if(grid[x-1][y] == 1){
                pair<int,int> p(x-1, y); 
                q.push(p); 
                grid[x-1][y] = 2; 
                area++; 
            }
        }
        if(x<grid.size()-1){
            if(grid[x+1][y] == 1){
                pair<int,int> p(x+1, y); 
                q.push(p); 
                grid[x+1][y] = 2; 
                area++; 
            }
        }

        if(y>0){
            if(grid[x][y-1] == 1){
                pair<int,int> p(x, y-1); 
                q.push(p); 
                grid[x][y-1] = 2; 
                area++; 
            }
        }
        if(y<grid[x].size()-1){
            if(grid[x][y+1] == 1){
                pair<int,int> p(x, y+1); 
                q.push(p); 
                grid[x][y+1] = 2; 
                area++; 
            }
        }

        grid[x][y] = 2; 

        return area; 
    }
};

int main(){

    vector<vector<int>> vec = {
                               {0,0,1,0,0,0,0,1,0,0,0,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,1,1,0,1,0,0,0,0,0,0,0,0},
                               {0,1,0,0,1,1,0,0,1,0,1,0,0},
                               {0,1,0,0,1,1,0,0,1,1,1,0,0},
                               {0,0,0,0,0,0,0,0,0,0,1,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,0,0,0,0,0,0,1,1,0,0,0,0}
                            }; 

    Solution s = Solution(); 
                        
    cout << s.maxAreaOfIsland(vec) << endl; 

                            
    return 0; 
}