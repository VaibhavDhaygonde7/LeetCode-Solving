#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        vector<pair<int,int>> directions = {{-1,0}, {0,-1}} ;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'X'){
                    bool hasNeighbour = false; 
                    for(pair<int,int> p : directions){
                        int x = i + p.first; 
                        int y = j + p.second; 

                        if(x >= 0 && x < board.size() && y >= 0 && j < board[0].size() && board[x][y] == 'X'){
                            hasNeighbour = true; 
                        }

                    }
                    if(!hasNeighbour) count++; 
                }
            }
        }   
        return count; 
    }
};


int main(){

    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    }; 

    Solution s = Solution(); 

    cout << s.countBattleships(board) << endl; 

    return 0; 
}