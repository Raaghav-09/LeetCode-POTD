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
    typedef pair<int,ListNode*> pil ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil,vector<pil>,greater<pil>> pq ;  //minheap
        for(ListNode* ele : lists){
            ListNode* t = ele ; 
            while(t!=NULL){
                pq.push({t->val,t}) ; 
                cout<< t->val << " ";
                t = t->next ; 
            }
        }
        if(pq.size()==0) return NULL ; 
        ListNode* head = pq.top().second ; 
        ListNode* t = head ; 
        pq.pop() ; 
        while(pq.size()){
            t->next = pq.top().second ; 
            t=t->next;
            pq.pop() ; 
        }
        return head ; 
        
    }
};