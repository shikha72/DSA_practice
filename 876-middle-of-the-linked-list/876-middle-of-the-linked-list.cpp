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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        int n=1;
        while(curr->next!=NULL){
            curr=curr->next;
            n++;
        }
        
        if(n%2==0)//even
            n=(n/2)+1;
        else
            n=(n+1)/2;
        
        curr=head;
        n=n-1;
        while(n--){
            curr=curr->next;
        }
        
        return curr;
    }
};