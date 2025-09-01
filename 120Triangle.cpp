#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minPaths; 
        for(int i = 1; i <= triangle.size(); i++){
            minPaths.push_back(vector<int>(i)); 
        }

        for(int i = 0; i < triangle.size(); i++){
            minPaths[triangle.size()-1][i] = triangle[triangle.size()-1][i]; 
        }
        
        for(int i = triangle.size()-1; i > 0; i--){
            findLowestCostsForAllElemsOfLayer(triangle, minPaths, i); 
        }

        return minPaths[0][0];  
    }
    void findLowestCostsForAllElemsOfLayer(vector<vector<int>>& triangle, vector<vector<int>>& minPaths, int layer){
        // here layer is the nth layer of the triangle. Noteworthy point is that the last layer of minPaths is always solved 
        /*
        1     --> layer 1
        2 3   --> layer 2
        4 5 6 --> layer 3
        */
        for(int i = 0; i < layer; i++){
            minPaths[layer-1][i] = triangle[layer-1][i] + min(minPaths[layer][i], minPaths[layer][i+1]); 
        }
    }
};

class Solution2 {
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

int main(){

    vector<vector<int>> vec = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    }; 

    Solution s = Solution(); 

    cout << s.minimumTotal(vec) << endl;  


    Solution2 s2 = Solution2(); 

    cout << s2.minimumTotal(vec) << endl; 

    return 0; 
}
