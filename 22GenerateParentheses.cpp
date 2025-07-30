#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
    int size;
    char* arr;
    int ptr;

    Stack(int size){
        this->size = size;
        this->arr = new char[size];
        ptr = -1;
    }

    void push(int num){
        if(ptr == size-1){
            return ;
        }
        ptr++;
        arr[ptr] = num;
    }

    void pop(){
        if(ptr == -1){
            return;
        }
        ptr--;
    }

    char top(){
        if(ptr == -1){
            return '*';
        }
        return arr[ptr];
    }

    bool isEmpty(){ return ptr == -1; }

};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string valid_parentheses( 2 * n , '*');
        vector<string> combinations;

        generate(combinations, valid_parentheses, n, n, 0);

        return combinations;

    }
    void generate(vector<string>& combinations, string valid_parentheses, int open, int close, int ind){
        if(open == 0 && close == 0){
            combinations.push_back(valid_parentheses);
            return;
        }

        if(open > 0){
            valid_parentheses[ind] = '(';
            generate(combinations, valid_parentheses, open-1, close, ind+1);
        }

        if(close > open){
            valid_parentheses[ind] = ')';
            generate(combinations, valid_parentheses, open, close-1, ind+1);
        }

    }
};

int main(){

    Solution s = Solution();

    vector<string> combinations = s.generateParenthesis(2);

    for(string sample : combinations){
        cout << sample << endl;
    }

    return 0; 
}