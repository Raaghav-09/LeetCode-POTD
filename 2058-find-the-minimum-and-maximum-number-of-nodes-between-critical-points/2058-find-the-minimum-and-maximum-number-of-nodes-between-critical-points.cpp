/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical ; 

        ListNode* prev = head ; 
        ListNode* temp = head->next ; 
        int ind = 1 ; 
        while(temp){
            if(temp->next){
                if(temp->val > prev->val && temp->val > temp->next->val){
                    critical.push_back(ind) ; 
                }
                else if(temp->val < prev->val && temp->val < temp->next->val){
                    critical.push_back(ind) ; 
                }
            }
            ind++ ; 
            prev = temp ;
            temp = temp->next ; 
        }

        if(critical.size() <= 1) return {-1,-1} ; 

        int mn = ind , mx = 0 ; 
        int m = critical.size() ; 
        for(int i=0 ; i<m-1 ; i++){
            mn = min(mn,critical[i+1]-critical[i]) ; 
        }
        return {mn,critical.back()-critical.front()} ; 
    }
};