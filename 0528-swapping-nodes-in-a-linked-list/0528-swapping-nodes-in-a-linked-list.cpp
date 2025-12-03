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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *rt = head, *lt = head;
        for(int i=0; i<k-1; i++) rt = rt->next;
        ListNode *temp = rt;
        while (rt->next) {
            lt = lt->next;
            rt = rt->next;
        }
        swap(temp->val, lt->val);
        return head;
    }
};