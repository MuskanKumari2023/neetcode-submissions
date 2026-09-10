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
        ListNode* head=new ListNode(-1);
        ListNode* dummy=head;
        int carry=0;
        while(l1!=NULL or l2!=NULL){
            int val1=(l1!=NULL)?l1->val:0;
            int val2=(l2!=NULL)?l2->val:0;
            int temp=val1+val2;
            temp+=carry;
            carry=temp/10;
            temp%=10;
            dummy->next=new ListNode(temp);
            dummy=dummy->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        // cout<<carry<<'\n';
        if(carry)dummy->next=new ListNode(carry);
        return head->next;
    }
};
