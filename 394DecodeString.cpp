#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int ind = 0;
        string answer;
        while(ind < s.length()){
            if(s[ind] - '0' >= 0 && s[ind] - '0' < 10){
                answer += decodeChunk(s, ind);
                ind = indexOfLastClosingBracket(s, ind+1);
            }
            else{
                answer += s[ind];
            }
            cout << answer << endl;
            ind++;
        }
        return answer;
    }
    string decodeChunk(string s, int ind){
        // here ind is the index of the first digit of the number
        int order = orderOfInteger(s, ind);
        int number = convertStringToInt(s, ind , order);

        string chunk = "" ;

        ind = ind + order + 1; // now ind is pointing at the first character of the chunk

        // cout << "decodeChunk() called" << endl;

        while(s[ind] != ']'){
            if(s[ind] - '0' >= 0 && s[ind] - '0' < 10){
                string smaller_chunk = decodeChunk(s, ind);
                chunk += smaller_chunk;
                // cout << smaller_chunk << endl;
                while(s[ind] != ']'){ ind ++ ; }
            }
            else{
                chunk += s[ind];
            }
            ind++;
        }

        string complete_chunk;
        complete_chunk.reserve(chunk.size()*number);

        while(number != 0){
            complete_chunk += chunk;
            number--;
        }

        return complete_chunk;

    }
    
    // this function returns the number of the digits in the number
    int orderOfInteger(string s, int ind){
        // here ind is the index of the first digit of the number 
        int counter = 0; 
        while(s[ind] != '['){
            counter++ ;
            ind++;
        }
        return counter;
    }

    int convertStringToInt(string s, int ind, int order){
        // here ind is the index of the first digit of number
        // "300"
        ind = ind + order - 1; // now ind is pointing at the units place
        int num = 0;
        int power_of_ten = 1;
        while(order != 0){
            num = num + power_of_ten*(s[ind] - '0');
            ind--;
            power_of_ten = power_of_ten * 10;
            order--;
        }
        return num;
    }

    int indexOfLastClosingBracket(string s, int ind){
        // here ind the the index of '['
        stack<int> brackets;
        for(int i = ind; i < s.length(); i++){
            if(s[i] == '[') brackets.push(0);
            if(s[i] == ']') brackets.pop();

            if(brackets.empty()) return i;

        }
        return -1;
    }
};







class Solution2 {
public:
    string decodeString(string s) {
        int ind = 0;
        string answer;
        while(ind < s.length()){
            if(s[ind] - '0' >= 0 && s[ind] - '0' < 10){
                answer += decodeChunk(s, ind);
                // ind = indexOfLastClosingBracket(s, ind+1);
            }
            else{
                answer += s[ind];
            }
            // cout << answer << endl;
            ind++;
        }
        return answer;
    }
    string decodeChunk(string s, int& ind){
        // here ind is the index of the first digit of the number
        int order = orderOfInteger(s, ind);
        int number = convertStringToInt(s, ind , order);

        string chunk = "" ;

        ind = ind + order + 1; // now ind is pointing at the first character of the chunk

        // cout << "decodeChunk() called" << endl;

        while(s[ind] != ']'){
            if(s[ind] - '0' >= 0 && s[ind] - '0' < 10){
                string smaller_chunk = decodeChunk(s, ind);
                chunk += smaller_chunk;
                // cout << smaller_chunk << endl;
                // while(s[ind] != ']'){ ind ++ ; }
            }
            else{
                chunk += s[ind];
            }
            ind++;
        }

        string complete_chunk;
        complete_chunk.reserve(chunk.size()*number);

        while(number != 0){
            complete_chunk += chunk;
            number--;
        }

        return complete_chunk;

    }
    
    // this function returns the number of the digits in the number
    int orderOfInteger(string s, int ind){
        // here ind is the index of the first digit of the number 
        int counter = 0; 
        while(s[ind] != '['){
            counter++ ;
            ind++;
        }
        return counter;
    }

    int convertStringToInt(string s, int ind, int order){
        // here ind is the index of the first digit of number
        // "300"
        ind = ind + order - 1; // now ind is pointing at the units place
        int num = 0;
        int power_of_ten = 1;
        while(order != 0){
            num = num + power_of_ten*(s[ind] - '0');
            ind--;
            power_of_ten = power_of_ten * 10;
            order--;
        }
        return num;
    }
};





void increase(int& num){
    num++;
}

int main(){

    Solution s = Solution();
    Solution2 s2 = Solution2();

    int ind = 0;

    // cout << s.decodeString("2[2[y]pq4[2[jk]ef]]ef") << endl; 
    // cout << s.decodeChunk("2[2[y]pq4[2[jk]e1[f]]]ef", 0) << endl;
    
    // cout << s.decodeChunk("2[2[2[a]2[f]]]", 0) << endl;
    
    cout << s2.decodeString("abcabccdcdcdef") << endl;




    return 0;
}