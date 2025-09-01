#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = triangle.size()-1; i > 0; i--){
            findLowestCostsForAllElemsOfLayer(triangle, i); 
        }

        return triangle[0][0];  
    }
    void findLowestCostsForAllElemsOfLayer(vector<vector<int>>& triangle, int layer){
        // here layer is the nth layer of the triangle. Noteworthy point is that the last layer of minPaths is always solved 
        /*
        1     --> layer 1
        2 3   --> layer 2
        4 5 6 --> layer 3
        */
        for(int i = 0; i < layer; i++){
            triangle[layer-1][i] = triangle[layer-1][i] + min(triangle[layer][i], triangle[layer][i+1]); 
        }
    }
};
