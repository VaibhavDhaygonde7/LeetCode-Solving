#include <iostream>
#include <vector>
using namespace std; 

class Node{
    public: 

    double val; 
    Node* next; 

    Node(double val){
        this->val = val; 
        this->next = nullptr; 
    }

    Node(){
        this->val = 0; 
        this->next = nullptr; 
    }

}; 


// using linked list
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here

        Node* head = convertToLL(stations); 

        // for(int i = 0; i < K; i++){
        //     insertAtMaxDistance(head); 
        //     traversal(head); 
        // }

        int numOfNodes = K; 

        traversal(head); 

        while(numOfNodes > 0){
            numOfNodes -= insertAtMaxDistance(head); 
            traversal(head); 
        }

        return maxDistance(head) ; 
    }
    Node* convertToLL(vector<int>& nums){
        Node* head = new Node(nums[0]); 
        Node* ptr = head;
    
        for(int i = 1; i < nums.size(); i++){
            Node* temp = new Node(nums[i]); 
            ptr->next = temp; 
            ptr = ptr->next; 
        }
    
        return head; 
    }

    int insertAtMaxDistance(Node* head){
        Node* maxDistanceNode = nullptr; 
        int maxDistance = 0; 
        int secondMaxDistance = -1; 
        Node* ptr = head; 
        while(ptr->next != nullptr && ptr != nullptr){
            if(ptr->next->val - ptr->val >= maxDistance){
                maxDistanceNode = ptr; 
                secondMaxDistance = maxDistance; 
                maxDistance = ptr->next->val - ptr->val; 
            }
            else{
                int instantDistance = ptr->next->val - ptr->val; 
                secondMaxDistance = max(secondMaxDistance, instantDistance); 
            }
            ptr = ptr->next; 
        }   
        // cout << endl;
        int i = 1; 

        // cout << maxDistance << " " << secondMaxDistance << endl; 
        if(secondMaxDistance != 0){
            while(maxDistance/i >= secondMaxDistance){
                i++; 
            }
        }
        else i = 2; 
        // cout << endl; 
        // cout << i << " " << endl; 

        int numOfNodes = i-1; 

        double val = (maxDistanceNode->next->val - maxDistanceNode->val)/i; 

        // cout << maxDistanceNode->val << " " << maxDistanceNode->next->val << endl; 

        // ptr = maxDistanceNode; 


        ptr = maxDistanceNode; 
        
        for(int i = 0; i < numOfNodes; i++){
            Node* temp = new Node(ptr->val + val); 
            temp->next = ptr->next; 
            ptr->next = temp; 
            ptr = ptr->next; 
        }
        return numOfNodes; 
    }

    void traversal(Node* head){
        Node* ptr = head; 
        while(ptr != nullptr){
            cout << ptr->val << " "; 
            ptr = ptr->next; 
        }
        cout << endl; 
    }

    double maxDistance(Node* head){

        Node* ptr = head; 
        double distance = 0; 

        while(ptr->next != nullptr && ptr != nullptr){
            if(ptr->next->val - ptr->val > distance){
                distance = ptr->next->val - ptr->val;
            }
            ptr = ptr->next; 
        }

        return distance; 

    }
};


int main(){

    vector<int> nums = {0,10,20}; 

    Solution s = Solution(); 

    cout << s.minMaxDist(nums, 2) << endl; 

    return 0 ;
}
