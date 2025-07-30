#include <iostream>
#include <unordered_map>
using namespace std; 

    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            
            int longest_length = 0; 

            int start = 0; // here start indicates the index which is the beginning of the new sub-string 
            unordered_map<char, int> map ; 
            int instantLength = 0; 

            int ind = 0; 

            while(ind < s.length()){
                if(map.find(s[ind]) == map.end()){
                    map[s[ind]] = ind; // entering the char and it's respective index in hash map 
                    longest_length = max(longest_length, ind-start+1); 
                }
                else{ 
                    if(map[s[ind]] < start){
                        // this means that the current is not considered in the sub-string 
                        longest_length = max(longest_length, ind-start+1); 
                    }
                    start = map[s[ind]]+1; 
                    map[s[ind]] = ind; 
                }
                ind++; 
            }
            
            return longest_length; 
        }
    };

int main(){

    Solution s = Solution(); 

    cout << s.lengthOfLongestSubstring("xabakx") << endl; 
    return 0; 
}