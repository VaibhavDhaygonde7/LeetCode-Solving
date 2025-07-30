#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int **visited = new int*[grid.size()]; 
        for(int i = 0; i < grid.size(); i++){
            visited[i] = new int[grid[0].size()]; 
        }

        int* pos = firstLandPosition(grid); 

        if(pos == nullptr){
            return 0; 
        }

        pair<int, int> p(pos[0], pos[1]); 

        visited[pos[0]][pos[1]] = 1; 

        queue<pair<int,int>> q; 
        q.push(p); 

        int perimeter = 0; 

        while(!q.empty()){
            calculatePerimeter(grid, perimeter, q, visited); 
            q.pop(); 
        }

        return perimeter; 
    }
    void calculatePerimeter(vector<vector<int>>& grid, int& perimeter, queue<pair<int, int>>& q, int** visited){
        int x = q.front().first; 
        int y = q.front().second; 
        if(x > 0){
            if(grid[x-1][y] == 1){
                if(visited[x-1][y] != 1){
                    pair<int, int> p(x-1, y); 
                    q.push(p); 
                    visited[x-1][y] = 1; 
                }
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(x < grid.size()-1){
            if(grid[x+1][y] == 1){
                if(visited[x+1][y] != 1){
                    pair<int, int> p(x+1,y); 
                    q.push(p); 
                    visited[x+1][y] = 1; 
                }
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(y > 0){
            if(grid[x][y-1] == 1){
                if(visited[x][y-1] != 1){
                    pair<int, int> p(x, y-1); 
                    q.push(p); 
                    visited[x][y-1] = 1; 
                }
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(y < grid[x].size()-1){
            if(grid[x][y+1] == 1){
                if(visited[x][y+1] != 1){
                    pair<int, int> p(x,y+1); 
                    q.push(p); 
                    visited[x][y+1] = 1; 
                }
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

    }

    int* firstLandPosition(vector<vector<int>>& grid){
        int* arr = nullptr; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    arr = new int[2]; 
                    arr[0] = i; 
                    arr[1] = j; 
                    return arr; 
                }
            }
        }
        return arr; 
    }

};

class Solution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int* pos = firstLandPosition(grid); 

        if(pos == nullptr){
            return 0; 
        }

        pair<int, int> p(pos[0], pos[1]); 

        grid[pos[0]][pos[1]] = 0; 

        queue<pair<int,int>> q; 
        q.push(p); 

        int perimeter = 0; 

        while(!q.empty()){
            calculatePerimeter(grid, perimeter, q); 
            q.pop(); 
        }

        return perimeter; 
    }
    void calculatePerimeter(vector<vector<int>>& grid, int& perimeter, queue<pair<int, int>>& q){
        int x = q.front().first; 
        int y = q.front().second; 
        if(x > 0){
            if(grid[x-1][y] == 1){
                pair<int, int> p(x-1, y); 
                q.push(p); 
                grid[x-1][y] = 0; 
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(x < grid.size()-1){
            if(grid[x+1][y] == 1){
                pair<int, int> p(x+1, y); 
                q.push(p); 
                grid[x+1][y] = 0; 
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(y > 0){
            if(grid[x][y-1] == 1){
                pair<int, int> p(x, y-1); 
                q.push(p); 
                grid[x][y-1] = 0; 
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

        if(y < grid[x].size()-1){
            if(grid[x][y+1] == 1){
                pair<int, int> p(x, y+1); 
                q.push(p); 
                grid[x][y+1] = 0; 
            }
            else{
                perimeter++; 
            }
        }else perimeter++; 

    }

    int* firstLandPosition(vector<vector<int>>& grid){
        int* arr = nullptr; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    arr = new int[2]; 
                    arr[0] = i; 
                    arr[1] = j; 
                    return arr; 
                }
            }
        }
        return arr; 
    }

};



int main(){

    Solution2 s2 = Solution2(); 

    vector<vector<int>> grid(4); 

    grid[0] = {0,1,0,0};   
    grid[1] = {1,1,1,0};   
    grid[2] = {0,1,0,0};   
    grid[3] = {1,1,0,0};   

    cout << s2.islandPerimeter(grid) << endl; 

    return 0; 
}