#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size()); 
        int number_of_provinces = 0; 

        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                findProvince(isConnected, visited, i); 
                number_of_provinces++; 
            }
        }

        return number_of_provinces; 

    }
    void findProvince(vector<vector<int>> &isConnected, vector<int>& visited, int startingPoint){
    
        visited[startingPoint] = 1 ;

        for(int i = 0; i < isConnected[startingPoint].size(); i++){
            if(i != startingPoint && isConnected[startingPoint][i] && !visited[i]){
                findProvince(isConnected, visited, i); 
            }
        }

    }
};

int main(){

    vector<vector<int>> isConected = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    }; 

    Solution s = Solution(); 

    cout << s.findCircleNum(isConected) << endl; 

    return 0; 
}