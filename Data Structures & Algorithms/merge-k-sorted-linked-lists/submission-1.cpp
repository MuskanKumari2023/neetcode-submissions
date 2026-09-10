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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
       int n=lists.size();
       for(int i=0;i<n;i++)
       {
          if(lists[i])pq.push({lists[i]->val,lists[i]});
       }
       ListNode* dummy=new ListNode(-1);
       ListNode* temp=dummy;
       while(!pq.empty()){
         auto cur=pq.top();
         pq.pop();
         temp->next=cur.second;
         if(cur.second->next)pq.push({cur.second->next->val,cur.second->next});
         temp=temp->next;
       }
       return dummy->next;
    }
};
