#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set; // this includes the elements which have occured only once
        unordered_set<char> dupli_set; // this set contains the element which violates the condition and hence is a duplicate of an existing element
        int maxWindowSize = 0; 
        int l = 0; 
        int r = 1; // points to the element which is not included yet 

        set.insert(s[l]); 
    
        while(r < s.length()){
            if(dupli_set.size() == 0){
                maxWindowSize = max(maxWindowSize, r-l); 
                // cout << l << " " << r << endl; 
                if(set.find(s[r]) != set.end()){
                    dupli_set.insert(s[r]); 
                    // cout << s[r] << endl; 
                }
                else{
                    set.insert(s[r]); 
                }
                r++; 
            }
            else{
                if(dupli_set.find(s[l]) != dupli_set.end()){
                    dupli_set.erase(s[l]); 
                }
                else{
                    set.erase(s[l]); 
                }
                l++; 
            }
        }

        if(dupli_set.size() == 0) maxWindowSize = max(maxWindowSize, r-l); 

        return maxWindowSize; 
        
    }
};


int main(){

    Solution s = Solution(); 
    Solution2 s2 = Solution2(); 

    cout << s.lengthOfLongestSubstring("oongaboonga") << endl; 
    cout << s2.lengthOfLongestSubstring("oongaboonga") << endl; 
    return 0; 
}
