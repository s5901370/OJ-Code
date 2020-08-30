class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *ans=NULL,*next;
        ListNode *cur = head;
        while(cur){
            next = cur->next;
            cur->next = ans;
            ans = cur;
            cur = next;
        }
        return ans;
    }
};