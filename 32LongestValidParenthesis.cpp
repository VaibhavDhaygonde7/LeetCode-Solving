#include <iostream>
#include <vector>
using namespace std; 

class Stack{
    public:
    
    int size; 
    int* arr; 
    int ptrInd = -1; 

    Stack(int size){
        this->size = size; 
        arr = new int[size]; 
    }

    int top(){
        if(ptrInd == -1) return -1; 
        return arr[ptrInd]; 
    }

    void push(int c){
        if(ptrInd == size - 1){
            cout << "Stack Overflow" << endl; 
            return;
        }
        ptrInd++; 
        arr[ptrInd] = c; 
    }

    bool isEmpty(){ return ptrInd == -1; }

    void pop(){
        if(ptrInd == -1){
            cout << "Stack is empty" << endl; 
        }
        ptrInd--; 
    }

}; 

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         Stack stack(s.length());

//         int longestValidParentheses = 0; // initially this will be 0 
//         int instantValidParentheses = 0;    

//         vector<int> startingPoints;
//         vector<int> endingPoints;

//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == '('){
//                 if(stack.isEmpty()){
//                     startingPoints.push_back(i); 
//                     instantValidParentheses = 0;
//                     cout << "This is a new start!" << endl;
//                 } 
//                 stack.push('(');
//             }
//             else{
//                 if(stack.isEmpty()){
//                     instantValidParentheses = 0;
//                 }
//                 else{
//                     instantValidParentheses += 2;
//                     longestValidParentheses = max(instantValidParentheses, longestValidParentheses);

//                     stack.pop();

//                     if(stack.isEmpty()){
//                         endingPoints.push_back(i);
//                         instantValidParentheses = 0;
//                         cout << "This is a new start!" << endl;
//                     }

//                 }
//             }
//         }

//         for(int n : startingPoints){
//             cout << n << " "; 
//         }
        
//         cout << endl; 

//         for(int n : endingPoints){
//             cout << n << " " ; 
//         }

//         cout << endl; 

//         int endIndex = min(startingPoints.size(), endingPoints.size());

//         {
//             int ind = 1;
//             while(ind < endIndex){
//                 cout << "Am I even here?" << endl;
//                 int currentInd = ind;
//                 while(currentInd < endIndex && startingPoints[currentInd] - endingPoints[currentInd-1] == 1){
//                     longestValidParentheses = max(longestValidParentheses, endingPoints[currentInd] - startingPoints[ind-1] + 1);
//                     currentInd ++;
//                 }
//                 ind = currentInd + 1;
//             }
//         }

//         return longestValidParentheses;
//     }
//     int max(int n1, int n2){
//         if(n1 > n2) return n1;  
//         return n2;    
//     }
//     int min(int n1, int n2){
//         if(n1 > n2) return n2; 
//         return n1;
//     }
// };



// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         Stack stack(s.length());

//         int longestValidParentheses = 0; // initially this will be 0 

//         vector<int> startingPoints;
//         vector<int> endingPoints;

//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == '('){
//                 if(stack.isEmpty()){
//                     startingPoints.push_back(i); 
//                 } 
//                 stack.push(i);
//             }
//             else{
//                 if(stack.isEmpty()){
//                     // nothing will happen here
//                 }
//                 else{
//                     longestValidParentheses = max(i-stack.top()+1, longestValidParentheses);

//                     stack.pop();

//                     if(stack.isEmpty()){
//                         endingPoints.push_back(i);
//                     }

//                 }
//             }
//         }

//         for(int n : startingPoints){
//             cout << n << " "; 
//         }
        
//         cout << endl; 

//         for(int n : endingPoints){
//             cout << n << " " ; 
//         }

//         cout << endl; 

//         int endIndex = min(startingPoints.size(), endingPoints.size());

//         {
//             int ind = 1;
//             while(ind < endIndex){
//                 int currentInd = ind;
//                 while(currentInd < endIndex && startingPoints[currentInd] - endingPoints[currentInd-1] == 1){
//                     longestValidParentheses = max(longestValidParentheses, endingPoints[currentInd] - startingPoints[ind-1] + 1);
//                     currentInd ++;
//                 }
//                 ind = currentInd + 1;
//             }
//         }

//         return longestValidParentheses;
//     }
//     int max(int n1, int n2){
//         if(n1 > n2) return n1;  
//         return n2;    
//     }
//     int min(int n1, int n2){
//         if(n1 > n2) return n2; 
//         return n1;
//     }
// };



int main(){

    // Solution s = Solution(); 

    // cout << s.longestValidParentheses("(()()") << endl;

    return 0; 
}
