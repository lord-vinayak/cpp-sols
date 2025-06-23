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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set <int> store(nums.begin(), nums.end());
	ListNode* dum= new ListNode(0);
	ListNode* curr= dum;
	while(head)
		{
			if(store.find(head->val)==store.end())
			{
				curr->next = head;
				curr= curr->next;
			}
			head=head->next;
		}
    curr->next = nullptr;
    ListNode* result = dum->next;
		delete dum;
		return result;
}
};