#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std; 

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // startingPoint == image[sr][sc]
        // here we will need a queue which will store the possible positions which are to be coloured  
        if(image[sr][sc]==color){
            return image; 
        }
        queue<pair<int,int>> q; 
        pair<int, int> p(sr,sc); 
        q.push(p);
        while(!q.empty()){
            floodFillPosition(image, q, color); 
            // cout << q.front().first << " " << q.front().second << endl; 
            q.pop(); 
        } 

        return image; 
    }

    void floodFillPosition(vector<vector<int>>& image, queue<pair<int, int>>& q, int colour){
        // I won't use 'color' lol 
        // here image[x][y] is the startingPoint
        // this function will first push the directly adjacent positions and at the end will change the colour of the starting point to colour
        int x = q.front().first; 
        int y = q.front().second;
        if(image[x][y] == colour){
            return; 
        }
        if(x > 0){
            if(image[x-1][y] == image[x][y]){
                pair<int, int> p(x-1,y); 
                q.push(p); 
            }
        }
        if(x < image.size()-1){
            if(image[x+1][y] == image[x][y]){
                pair<int, int> p(x+1,y); 
                q.push(p);         
            }
        }
        if(y > 0){
            if(image[x][y-1] == image[x][y]){
                pair<int, int> p(x,y-1); 
                q.push(p); 
            }
        }
        if(y < image[x].size()-1){
            if(image[x][y+1] == image[x][y]){
                pair<int, int> p(x,y+1); 
                q.push(p);         
            }
        }
        image[x][y] = colour; 
    }
};

int main(){

    vector<vector<int>> vec(2); 
    vec[0] = {0,0,0}; 
    vec[1] = {0,0,0}; 

    Solution s = Solution(); 

    s.floodFill(vec, 1, 1, 0); 

    for(vector<int> v : vec){
        for(int n : v){
            cout << n << " "; 
        }
        cout << endl; 
    }

    return 0; 
}