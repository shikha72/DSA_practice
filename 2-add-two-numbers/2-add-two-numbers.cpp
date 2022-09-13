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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head=NULL, *curr=NULL, *c1=l1, *c2=l2;
        int carr=0;
        while(c1!=NULL || c2!=NULL){
            int a=0, b=0;
            if(c1!=NULL)
                a=c1->val;
            if(c2!=NULL)
                b=c2->val;
            
            int sum=a+b+carr;
            carr=sum/10;
            sum=sum%10;
            
            ListNode* temp=new ListNode(sum);
            if(head==NULL){
                head=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=temp;
            }
            
            if(c1!=NULL)
            c1=c1->next;
            
            if(c2!=NULL)
            c2=c2->next;
        }
        
        if(carr!=0){
            ListNode* temp=new ListNode(carr);
            temp->next=NULL;
            curr->next=temp;
        }
        
        return head;
     
    }
};