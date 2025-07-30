#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int highest_temp = temperatures[temperatures.size()-1];
        int lowest_temp = temperatures[temperatures.size()-1];
        vector<int> answer(temperatures.size());
        answer[temperatures.size()-1] = 0;
        for(int i = temperatures.size()-2; i >= 0; i--){
            if(temperatures[i] < lowest_temp){
                lowest_temp = temperatures[i];
            }
            if(highest_temp < temperatures[i]){
                highest_temp = temperatures[i];
            }
            if(temperatures[i] < highest_temp && temperatures[i] >= lowest_temp){
                if(temperatures[i] == temperatures[i+1]){
                    // answer.push_back(answer[answer.size()-1] + 1);
                    answer[i] = answer[i+1] + 1;
                }
                else{
                    answer[i] = nextGreaterElem(temperatures, i);
                }
            }
            else{   
                answer[i] = 0;
            }
        }

        return answer;
    }
    
    int nextGreaterElem(vector<int>& temperatures, int ind){
        int current_temp = temperatures[ind++];
        int counter = 1;
        while(ind < temperatures.size()){
            if(temperatures[ind] > current_temp){
                return counter;
            }
            counter++;
            ind++;
        }
        return 0;
    }
};

// slower way
class Solution2{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answers;
        answers.push_back(nextWarmerDay(temperatures, 0));

        for(int i = 1; i < temperatures.size(); i++){
            if(temperatures[i] > temperatures[i-1]){
                answers.push_back(nextWarmerDay(temperatures, i));
            }
            else if(temperatures[i] == temperatures[i-1]){
                if(answers[answers.size()-1] == 0) answers.push_back(0);
                else answers.push_back(answers[answers.size()-1] - 1);
            }
            else{
                answers.push_back(nextWarmerDay(temperatures,i));
            }
        }

        return answers;

    }
    int nextWarmerDay(vector<int>& temperatures, int current){
        
        int current_temp = temperatures[current];
        int index = current;
        while(index <= temperatures.size()-1){
            if(temperatures[index] > current_temp){
                return index - current;
            }
            index++;
        }
        return 0;
    }
};












class Stack{
    public:
    int size;
    int ptr = -1;
    int* arr;

    Stack(int size){
        this->size = size; 
        arr = new int[size]; 
    }

    void push(int num){
        if(ptr == size-1){
            return;
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

    int top(){
        if(ptr == -1){
            return -1;
        }
        return arr[ptr]; 
    }

    bool isEmpty(){ return ptr == -1; }

};

class Solution3 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        Stack stack(temperatures.size());
        vector<int> answers(temperatures.size(), 0);

        for(int i = temperatures.size()-1; i>=0; i--){
            while(!stack.isEmpty() && temperatures[i] >= temperatures[stack.top()]){
                stack.pop();
            }
            if(!stack.isEmpty()){
                answers[i] = stack.top() - i;
            }
            stack.push(i);
        }

        return answers;

    }
};





int main(){

    Solution3 s3 = Solution3();

    vector<int> temperatures = {30,60,90};
    
    vector<int> answer = s3.dailyTemperatures(temperatures);

    for(int n : answer){
        cout << n << " ";
    }
    cout << endl;

    return 0;   
}