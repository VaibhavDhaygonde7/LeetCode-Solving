#include <iostream>
#include <stack>
using namespace std; 

bool isValid(string s){
    stack<char> st; 
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]); 
        }
        else{
            if(!st.size()) return false; 
            if(s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '['){
                st.pop(); 
            }
            else{
                return false; 
            }
        }
    }
    return true; 
}

int main(){

    cout << isValid("([)]") << endl; 

    return 0; 
}
