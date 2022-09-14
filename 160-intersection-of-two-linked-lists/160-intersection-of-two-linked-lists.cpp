/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA, *b=headB;
        int l1=0, l2=0;
        while(a!=NULL){
            a=a->next;
            l1++;
        }
        while(b!=NULL){
            b=b->next;
            l2++;
        }
        
        int diff=abs(l1-l2);
        
        a=headA, b=headB;
        if(l1>l2){
            while(diff--){
                a=a->next;
            }
        }
        else if(l2>l1){
            while(diff--){
                b=b->next;
            }
        }
        
        while(a!=NULL && b!=NULL){
            if(a!=b){
                a=a->next;
                b=b->next;
            }
            else 
                return a;
        }
        return NULL;
    }
};