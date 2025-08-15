#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

void prettyPrint(vector<vector<char>> board){
    for(vector<char> vec : board){
        for(char c : vec){
            cout << c << " "; 
        }
        cout << endl; 
    }
}


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X'; 
            return board; 
        }
        
        int countOfMines = numberOfMinesInVicinity(board, click[0], click[1]); 
        if(countOfMines != 0){
            board[click[0]][click[1]] = 48 + countOfMines; 
        }
        else{
            revealBlankSquares(board, click[0], click[1]); 
        }

        return board; 
    }
    
    int numberOfMinesInVicinity(vector<vector<char>>& board, int x, int y){
        vector<pair<int,int>> directions = { {-1,0}, {1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1, 1}, {-1,-1} }; 

        int countOfMines = 0; 

        for(pair<int,int> p : directions){
            int newX = x + p.first; 
            int newY = y + p.second; 
            
            if(newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == 'M'){
                countOfMines++; 
            }

        }

        return countOfMines; 

    }

    void revealBlankSquares(vector<vector<char>>& board, int x, int y){
        // here we are assuming that we are sure that all the neighbours adjacent as well as diagonal are not surrounded by a bomb 
        board[x][y] = 'B'; 
        queue<pair<int,int>> q; 
        q.push({x,y}); 

        vector<pair<int,int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} }; 

        while(!q.empty()){
            int x = q.front().first; 
            int y = q.front().second; 
            
            q.pop(); 

            for(pair<int,int> p : directions){
                int newX = x + p.first; 
                int newY = y + p.second; 

                if(newX>=0 && newX<board.size() && newY>=0 && newY < board[0].size() && board[newX][newY] == 'E'){
                    int countOfMines = numberOfMinesInVicinity(board, newX, newY); 
                    if(countOfMines != 0){
                        board[newX][newY] = 48 + countOfMines; 
                    }
                    else{
                        board[newX][newY] = 'B'; 
                        q.push({newX, newY}); 
                    }
                }

            } 

        }   
    }

};



int main(){

    vector<vector<char>> board = {
        {'E','E','E','E','E'},
        {'E','E','M','E','E'},
        {'E','E','E','E','E'},
        {'E','E','E','E','E'}
    }; 

    prettyPrint(board); 
    
    cout << endl; 
    
    Solution s = Solution(); 
    vector<int> click = {3,0}; 
    
    s.updateBoard(board, click); 
    
    prettyPrint(board); 

    return 0; 
}