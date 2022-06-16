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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* odd_head = NULL;
        ListNode* even_head = NULL;
        ListNode* odd_tail = NULL;
        ListNode* even_tail = NULL;
        ListNode* temp = head;
        bool isOdd = 1;
        
        while(temp != NULL){
            if(isOdd){
                if(odd_head == NULL){
                    odd_head = odd_tail = temp;
                }
                else{
                    odd_tail->next = temp;
                    odd_tail = temp;
                }
                temp = temp->next;
                odd_tail->next = NULL;
            }
            else{
                if(even_head == NULL){
                    even_head = even_tail = temp;
                }
                else{
                    even_tail->next = temp;
                    even_tail = temp;
                }
                temp = temp->next;
                even_tail->next = NULL;
            }
            isOdd = !isOdd;
        }
        odd_tail->next = even_head;
        return odd_head;
    }
};