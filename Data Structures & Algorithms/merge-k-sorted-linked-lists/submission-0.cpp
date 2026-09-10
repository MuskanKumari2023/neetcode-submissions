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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(l1!=NULL and l2!=NULL){
            if(l1->val>=l2->val){
                tail->next=l2;
                l2=l2->next;
            }
            else
            {
                tail->next=l1;
                l1=l1->next;
            }
            tail=tail->next;
        }
        if(l1)tail->next=l1;
        else tail->next=l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        int n=lists.size();
        if(n==0)return head;
        for(int i=1;i<n;i++){
            head=merge(lists[i],lists[i-1]);
            lists[i]=head;
        }
        return lists[n-1];
    }
};
