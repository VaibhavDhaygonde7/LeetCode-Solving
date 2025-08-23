#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int findNthDigit(int n) {

        int low = 1; 
        int high = n;
        if(high > 10000){
            high = high/2; 
        } 
        while(low <= high){
            int mid = (low + high)/2; 

            long digitsBefore = numberOfDigitsBeforeNum(mid); 

            if(digitsBefore < n){
                low = mid+1; 
            }
            else{
                high = mid-1; 
            }

        }

        // low - 1 is the number which has the Nth digit 

        int digitsBefore = numberOfDigitsBeforeNum(low-1); 

        // cout << "Number: " << low - 1 << ", Digits Before this number: " << numberOfDigitsBeforeNum(low-1) << endl; 
        // cout << n - digitsBefore << "th digits of " << low-1 << endl; 
        // cout << digitsOfNum(low-1) << ": Number of digits in " << low-1 << endl; 
        // cout << digitsOfNum(low-1) - (n - digitsBefore) + 1 << "th digit in reverse direction" << endl; 

        return nthDigitFromBehind(low-1, digitsOfNum(low-1) - (n-digitsBefore) + 1); 
    }

    int nthDigitFromBehind(int num, int nth_digit){
        int count = 1; 
        while(num > 0){
            if(count == nth_digit){
                return num % 10; 
            }
            num /= 10; 
            // cout << count << ", " << num % 10 << endl; 
            count++; 
        }
        return 0; 
    }

    long numberOfDigitsBeforeNum(int num){
        // this function will return the number of digits appearing before the current number 
        // 10 --> 9, 11 --> 11, 12 --> 13 

        long n = 10; 
        long no_of_digits = 0; 
        int numOfDigitsPresent = 1; 
        while(n <= num){
            no_of_digits += ((n - n/10) * numOfDigitsPresent); 
            n *= 10; 
            numOfDigitsPresent++; 
        }

        no_of_digits += ((num - (n/10)) * numOfDigitsPresent); 

        return no_of_digits; 
    }

    int digitsOfNum(int n){
        int count = 0; 
        while(n > 0){ 
            n /= 10; 
            count++; 
        }
        return count; 
    }

};

int main(){

    Solution s = Solution(); 
    
    cout << s.findNthDigit(1000000000) << endl ;


    return 0; 
}

// 1,2,3,4,5,6,7,8,9,10,11