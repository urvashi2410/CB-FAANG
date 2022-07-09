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
#define p pair<int, ListNode* >
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l = new ListNode();
        ListNode* ans = l;
        // min priority queue 
        priority_queue<p, vector<p>, greater<p>>q;
        
        for(int i = 0; i < lists.size(); i++){
            // inserting first node of all Lists in heap 
            if(lists[i]){
                q.push(make_pair(lists[i]->val, lists[i]));
            }
        }
        
        while(!q.empty()){
            ListNode* top = q.top().second;
            q.pop();
            
            if(top->next){
                q.push(make_pair(top->next->val, top->next));
            }
            
            ans->next = top;
            ans = ans->next;
        }
        return l->next;
    }
};