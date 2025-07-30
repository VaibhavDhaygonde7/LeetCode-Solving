#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
    }
    int minutesForRottingOtherOranges(vector<vector<int>>& grid, int rottenX, int rottenY){
        // here grid[x][y] is a rotten orange and we will calculate the total number of minutes required for the other oranges to rot which are neighbouring this rotten orange directly or indirectly 
        queue<pair<int,int>> q; 
        int minutes = 0; 
        q.push({rottenX,rottenY}); 

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}}; 

        while(!q.empty()){

            for(vector<int> v : grid){
                for(int n : v){
                    cout << n << " " ;  
                }
                cout << endl; 
            }

            cout << "\n" << endl; 
            minutes++; // as this current rotten orange can spoil all the other neighbouring oranges in a single minute 

            int x = q.front().first; 
            int y = q.front().second; 
            q.pop(); 

            for(auto direction : directions){
                int dx = direction.first; 
                int dy = direction.second; 

                int newX = x + dx; 
                int newY = y + dy; 

                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && grid[newX][newY] == 1){
                    q.push({newX, newY}); 
                    grid[newX][newY] = 2; // now this orange is rotten as well -_- 
                }

            }

        }

        return minutes; 
    }
};

int main(){

    vector<vector<int>> grid = {
        {2,1,1}, 
        {1,1,0},
        {0,1,1}
    }; 

    Solution s = Solution();  

    cout << s.minutesForRottingOtherOranges(grid, 0, 0) << endl; 

    return 0; 
}