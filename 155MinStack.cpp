#include <iostream>
#include <stack>
using namespace std; 

class MinStack {
public:
    stack<int> st;  
    int min; 
    MinStack() {
        min = __INT_MAX__;  
    }
    
    void push(int val) {
        if(val < min){
            int prevMin = min; 
            min = val; 
            st.push((2*val) - prevMin);
        }
        else{
            st.push(val); 
        }
    }
    
    void pop() {
        if(!st.size()) return; 
        if(st.top() < min){
            min = (2*min) - st.top(); 
        }
        st.pop();
    }
    
    int top() {
        if(!st.size()) return -1; 
        if(st.top() < min){
            return min; 
        }
        return st.top(); 
    }
    
    int getMin() {
        return min; 
    }
};


int main(){

    return 0; 
}
