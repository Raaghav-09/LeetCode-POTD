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
    int pairSum(ListNode* head) {
        stack<ListNode*> st ; 
        ListNode* temp = head ; 
        int len = 1 ; 
        while(temp){
            st.push(temp) ; 
            temp = temp->next ; 
            len++ ; 
        }

        int count = 1 ; 
        temp = head ; 
        int mx = INT_MIN ; 
        while(count<=len/2){
            ListNode* t = st.top() ; 
            st.pop() ; 
            int sum = temp->val + t->val ;
            temp = temp->next ;
            mx = max(sum,mx) ; 
            count++ ; 
        }
        return mx ; 
    }
};