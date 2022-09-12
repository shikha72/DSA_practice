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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1=list1, *curr2=list2, *prev=NULL;
        
        ListNode* head=list1;
        if(head==NULL)
            head=list2;
        
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val < curr2->val){
                prev=curr1;
                curr1=curr1->next;
            }
            else if(curr1->val > curr2->val){
                ListNode* nx2=curr2->next;
                
                if(prev!=NULL)
                    prev->next=curr2;
                else head=curr2;
                
                curr2->next=curr1;
                prev=curr2;
                curr2=nx2;
            }
            else{
                ListNode* nx1=curr1->next, *nx2=curr2->next;
                
                curr1->next=curr2;
                curr2->next=nx1;
                
                prev=curr2;
                curr1=nx1;
                curr2=nx2;
            }
        }
        
        if(curr2!=NULL && prev!=NULL){
            prev->next=curr2;
        }
        
        return head;        
    }
};