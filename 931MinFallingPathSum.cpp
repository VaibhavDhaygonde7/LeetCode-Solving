class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        for(int i = matrix.size()-2; i >= 0; i--){
            updateRow(matrix, i); 
        }

        int lowestPathSum = 10001; 
        
        for(int i = 0; i < matrix[0].size(); i++){
            if(lowestPathSum > matrix[0][i]){
                lowestPathSum = matrix[0][i]; 
            }
        }
        
        return lowestPathSum; 
    }
    void updateRow(vector<vector<int>>& matrix, int i){
        // basically we have to select a path for each element of the ith row and i+1 th row already contains minimum falling path till that
        for(int j = 0; j < matrix[0].size(); j++){
            int minFallingPath = 10001; 

            if(j+1 < matrix.size() && minFallingPath > matrix[i+1][j+1]){
                minFallingPath = matrix[i+1][j+1]; 
            }

            if(minFallingPath > matrix[i+1][j]){
                minFallingPath = matrix[i+1][j]; 
            }

            if(j-1 >= 0 && minFallingPath > matrix[i+1][j-1]){
                minFallingPath = matrix[i+1][j-1]; 
            }

            matrix[i][j] = matrix[i][j] + minFallingPath; 
        }
    }
};
