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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size() ; 
        set<int> s(nums.begin(),nums.end()) ; 

        ListNode* newHead = head ; 
        while(newHead){
            if(s.find(newHead->val)!=s.end()){
                newHead = newHead->next ; 
            }
            else break ; 
        }
        ListNode* temp = newHead ; 
        ListNode* prev = NULL ; 
        while(temp){
            prev = temp ; 
            temp = temp->next ; 
            while(temp && s.find(temp->val)!=s.end()){
                temp = temp->next ; 
            }
            prev->next = temp ; 
        }
        return newHead ; 
    }
};