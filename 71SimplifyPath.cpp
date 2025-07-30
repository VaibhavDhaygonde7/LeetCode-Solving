#include <iostream>
#include <vector>
using namespace std;

class Stack{

    public:
    
    int size;
    char* arr;
    int ptr = -1;

    Stack(int size){
        this->size = size;
        arr = new char[size];
    }

    void push(char num){
        if(ptr == this->size - 1){
            // cout << "Stack is already full" << endl;
            return;
        }
        ptr++;
        arr[ptr] = num;
    }

    void pop(){
        if(ptr == -1){
            // cout << "Stack is empty" << endl;
            return;
        }
        ptr--;
    }

    char top(){
        if(ptr == -1){
            return '|';
        }
        return arr[ptr];
    }

    bool isEmpty(){ return ptr == -1; }

};

class Solution {
public:
    string simplifyPath(string path) {
        Stack stack(path.length());

        for(int i = 0; i < path.length(); i++){
            if(path[i] != '/'){
                if(isValid(path, i)){
                    // this means that the folder name contains at least one alphabet
                    while(i < path.length() && path[i] != '/'){
                        stack.push(path[i]);
                        i++;
                    }
                    i--;
                }
                else{
                    int count = dotsCounter(path, i);
                    if(count > 2){
                        while(i < path.length() && path[i] != '/'){
                            stack.push(path[i]);
                            i++;
                        }
                        i--;
                    }
                    else if(count == 2){
                        stack.pop();
                        while(!stack.isEmpty() && stack.top() != '/'){
                            stack.pop();
                        }
                    }
                }
            }
            else{
                if(stack.top()=='/') continue;
                stack.push('/');
            }
        }


        if(stack.top()=='/'){ stack.pop(); }

        if(stack.isEmpty()) return "/";

        // while(!stack.isEmpty()){
        //     cout << stack.top() << endl;
        //     stack.pop();
        // }

        string answer(stack.ptr + 1, ' ');

        for(int i = stack.ptr; i>=0;i--){
            answer[i] = stack.top();
            stack.pop();
        }

        return answer;

    }   

    int dotsCounter(string path, int ind){
        // ind --> this index has '.'
        int counter = 0;
        while(ind < path.length()){
            if(path[ind] == '.'){
                counter++;
                ind++;
            }
            else{
                break;
            }
        }
        return counter;
    }

    bool isValid(string path, int ind){
        while(ind < path.length() && path[ind] != '/'){
            if(path[ind] != '.'){
                return true; 
            }
            ind++;
        }
        return false;
    }

};  


class Solution2{
    
    public:
    
    string simplifyPath(string path) {
        vector<string> folder_names;

        for(int i = 0; i < path.length(); i++){
            if(path[i] != '/'){
                string folder_name = folderName(path, i);
                if(folder_name == ".."){
                    if(!folder_names.empty()){
                        folder_names.pop_back();
                    }
                }
                else if(folder_name == "."){
                    continue;
                }
                else{
                    folder_names.push_back(folder_name);
                    i += folder_name.length() - 1;
                }
            }
        }

        string answer = "/";
        for(int i = 0; i<folder_names.size(); i++){
            answer += folder_names[i];
            if(i != folder_names.size()-1){
                answer += "/";
            }
        }

        return answer;

    }

    string folderName(string path, int ind){
        string temp;
        while(ind < path.length() && path[ind] != '/'){
            temp += path[ind];
            ind++;
        }
        return temp;
    }
}; 

int main(){

    Solution2 s = Solution2();

    cout << s.simplifyPath("/.../a/../b/c/../d/./") << endl;

    return 0; 
}
