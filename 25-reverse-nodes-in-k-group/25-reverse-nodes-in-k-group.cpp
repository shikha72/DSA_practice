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
    int length(ListNode* head){
        int n=0;
        while(head!=NULL){
            ++n;
            head=head->next;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
        
        int len=length(head);
        
        ListNode* dummynode=new ListNode(0);
        dummynode->next=head;
        ListNode* pre=dummynode, *curr, *nex;
        
        while(len>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            len=len-k;
        }
        
        return dummynode->next;
    }
};