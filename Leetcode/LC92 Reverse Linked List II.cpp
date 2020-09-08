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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode *curr = head,*tail = NULL,*prev = NULL,*store = head;
        while(curr){
            if(count == m){
                prev = tail = curr;
                curr = curr->next;
            }
            else if (count > m && count < n){
                ListNode * temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            else if(count == n){
                if(m == 1){
                    tail->next = curr->next;
                    curr->next = prev;
                    head = curr;
                }
                else{
                    store->next = curr;
                    tail->next = curr->next;
                    curr->next = prev;
                }
                curr = curr->next;
            }
            else{
                store = curr;
                curr = curr->next;
            }
            
            count++;
        }
        return head;
    }
};