class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int sz = 1; 
        ListNode* temp = head; 
        
        while (temp->next) {
            temp = temp->next;
            sz++;
        }
        ListNode* lastNode = temp;

        k %= sz; 
        if(k==0) return head ;

        int nextNode = sz - k ;  

        ListNode* start = head ; 
        ListNode* prev = NULL ; 
        int no = 1 ; 
        
        while(no != nextNode + 1){  
            prev = start; 
            start = start->next; 
            no++; 
        }

        prev->next = NULL; 
        lastNode->next = head; 
        
        return start; 
    }
};