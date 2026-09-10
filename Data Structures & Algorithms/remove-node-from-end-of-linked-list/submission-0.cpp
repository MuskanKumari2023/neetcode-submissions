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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return NULL;
        int total=0;
        ListNode* temp=head;
        while(temp){
            total++;
            temp=temp->next;
        }
        // cout<<total<<'\n';
        n=(total-n);
        if(n==0)return head->next;
        // cout<<n<<'\n';
        temp=head;
        n--;
        while(n--){
            temp=temp->next;
        }
        // cout<<temp->val<<'\n';
        temp->next=temp->next->next;
        return head;
    }
};
