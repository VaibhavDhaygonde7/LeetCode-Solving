#include <iostream>
using namespace std; 


int totalNumbers(int sn, int en, int k){
    return ((en - sn)/k) + 1; 
}


int lastRemainingNumber(int n){
    int sn = 1; // sn - starting number 
    int en = (n & 1) ? (n-1) : n; // en - ending number 
    // cout << sn << " " << en << endl; 

    int k = 1; 
    bool direction = false; // false means from left to right, true means right to left 
    // condition is not sn == en, because it fails for n = 1, so sn = en safer to say
    while(sn < en){
        int instantNumbers = totalNumbers(sn, en, k); 
        if(instantNumbers & 1){
            sn = sn + k; 
            en = en - k; 
        }
        else{   
            if(!direction){
                // left to right 
                sn = sn + k; 
            }
            else{
                en = en - k; 
            }
        }
        k = (k << 1); 
        direction = !direction;
    }

    return sn; 
}


int main(){

    cout << lastRemainingNumber(20) << endl; 

    return 0; 
}
