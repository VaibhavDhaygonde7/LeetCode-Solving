#include <iostream>
#include <deque>
#include <vector>
using namespace std; 

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0; 
        int r = 1;  // points to last not included element
        deque<int> dqMinElem; 
        deque<int> dqMaxElem; 
        dqMaxElem.push_back(nums[l]); 
        dqMinElem.push_back(nums[l]); 

        int maxWindowSize = 0; 

        while(r < nums.size()){
            // window expansion 
            while(r < nums.size() && dqMaxElem.front() - dqMinElem.front() <= limit){
                includeInDqMaxElem(dqMaxElem, nums[r]); 
                includeInDqMinElem(dqMinElem, nums[r]); 
                r++; 
            }
            if(r == nums.size()){
                // a small edge case 
                if(dqMaxElem.front() - dqMinElem.front() <= limit){
                    maxWindowSize = max(maxWindowSize, r - l); 
                }
                else{
                    // because last element also makes the range invalid 
                    maxWindowSize = max(maxWindowSize, r-l-1); 
                }
            }
            else{
                maxWindowSize = max(maxWindowSize, r - l-1); // because r points to the element which is not included yet. window lies in the range [l, r-1] which satisfies the condition 
            }

            // cout << l <<" "<< r-1 << endl ;
            // cout << dqMaxElem.front() << " " << dqMinElem.front() << endl; 

            while(((r < nums.size() && l<=r) || (r == nums.size() || l < r)) && dqMaxElem.front() - dqMinElem.front() > limit){
                excludeFromDqMaxElem(dqMaxElem, nums[l]);
                excludeFromDqMinElem(dqMinElem, nums[l]);
                l++; 
            }

        }

        return maxWindowSize; 
    }

    void includeInDqMaxElem(deque<int>& dqMaxElem, int elem){
        while(!dqMaxElem.empty() && dqMaxElem.back() < elem){
            // not introducing equality in the comparison because it may remove the max element and give false max element in the future 
            dqMaxElem.pop_back(); 
        }
        dqMaxElem.push_back(elem); 
    }

    void includeInDqMinElem(deque<int>& dqMinElem, int elem){
        while(!dqMinElem.empty() && dqMinElem.back() > elem){
            // not introducing equality in the comparison because it may remove the min element and give false min element in the future 
            dqMinElem.pop_back(); 
        }
        dqMinElem.push_back(elem); 
    }

    void excludeFromDqMaxElem(deque<int>& dqMaxElem, int elem){
        if(dqMaxElem.empty()) return ;
        if(dqMaxElem.front() == elem){
            dqMaxElem.pop_front(); 
        }
    }

    void excludeFromDqMinElem(deque<int>& dqMinElem, int elem){
        if(dqMinElem.empty()) return; 
        if(dqMinElem.front() == elem){
            dqMinElem.pop_front(); 
        }
    }

};


class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if(nums.size() == 1) return 1;
        int l = 0; 
        int r = 1;  // points to last excluded element
        deque<int> dqMinElem; 
        deque<int> dqMaxElem; 
        dqMaxElem.push_back(nums[l]); 
        dqMinElem.push_back(nums[l]); 

        int maxWindowSize = 0; 
        
        while(r < nums.size()){
            if(dqMaxElem.front() - dqMinElem.front() <= limit){
                maxWindowSize = max(maxWindowSize, r-l);
                // expanding window size 
                includeInDqMaxElem(dqMaxElem, nums[r]);
                includeInDqMinElem(dqMinElem, nums[r]);
                r++; 
            }
            else{
                excludeFromDqMaxElem(dqMaxElem, nums[l]); 
                excludeFromDqMinElem(dqMinElem, nums[l]); 
                l++; 
            }
        }

        return maxWindowSize; 
    }

    void includeInDqMaxElem(deque<int>& dqMaxElem, int elem){
        while(!dqMaxElem.empty() && dqMaxElem.back() < elem){
            // not introducing equality in the comparison because it may remove the max element and give false max element in the future 
            dqMaxElem.pop_back(); 
        }
        dqMaxElem.push_back(elem); 
    }

    void includeInDqMinElem(deque<int>& dqMinElem, int elem){
        while(!dqMinElem.empty() && dqMinElem.back() > elem){
            // not introducing equality in the comparison because it may remove the min element and give false min element in the future 
            dqMinElem.pop_back(); 
        }
        dqMinElem.push_back(elem); 
    }

    void excludeFromDqMaxElem(deque<int>& dqMaxElem, int elem){
        if(dqMaxElem.empty()) return ;
        if(dqMaxElem.front() == elem){
            dqMaxElem.pop_front(); 
        }
    }

    void excludeFromDqMinElem(deque<int>& dqMinElem, int elem){
        if(dqMinElem.empty()) return; 
        if(dqMinElem.front() == elem){
            dqMinElem.pop_front(); 
        }
    }

};


int main(){

    vector<int> nums = {8,2,4,7}; 
    int limit = 4; 

    Solution s = Solution(); 
    Solution2 s2 = Solution2(); 

    cout << s.longestSubarray(nums, limit) << endl; 
    cout << s2.longestSubarray(nums, limit) << endl; 

    return 0 ;  
}
