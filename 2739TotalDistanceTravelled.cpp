#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        // let's try to be near 5L in main Tank 
        int actualPetrolUsed = 0; 
        if((mainTank-5)/4 >= additionalTank){
            // this is the condition were the additionalTank will be emptied 
            // actualPetrolUsed += additionalTank*5; 
            // mainTank -= additionalTank*4; 
            // additionalTank = 0; // as this tank is completely emptied 
            // actualPetrolUsed += mainTank; 
            // mainTank = 0; // mainTank is also now emptied 
            actualPetrolUsed = mainTank + additionalTank; 
        }
        else{
            actualPetrolUsed += ((mainTank-5)/4)*5; 
            additionalTank -= (mainTank-5)/4;
            mainTank -= ((mainTank-5)/4)*4; 
            actualPetrolUsed += calculatingPetrol(mainTank, additionalTank);  
        }
        return actualPetrolUsed; 
    }
    int calculatingPetrol(int mainTank, int additionalTank){
        int petrolUsed = 0; 
        while(mainTank > 0 && additionalTank > 0){
            if(mainTank < 5){
                break; 
            }
            mainTank -= 4; 
            additionalTank--; 
            petrolUsed += 5; 
        }
        if(additionalTank == 0 || mainTank < 5){
            petrolUsed += mainTank; 
        }
        return petrolUsed; 
    }
};

int main(){

    Solution s = Solution(); 

    cout << s.distanceTraveled(11, 5) << endl; 

    return 0; 
}