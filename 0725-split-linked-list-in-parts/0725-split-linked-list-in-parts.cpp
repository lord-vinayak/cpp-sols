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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<ListNode*> parts(k, nullptr);
	ListNode* current = head;
	int len=0;
	while(current)
	{
		len++;
		current = current->next;
	}
	int size = len/k;
	int xtra = len%k;
	current=head;
	for(int i=0; i<k && current ; i++)
	{
		parts[i] = current;
		int thissize = size;
		if(xtra>0)
		{
			thissize += 1;
			xtra--;
		}
		for(int j=1; j<thissize ; j++)
			current = current->next;
		ListNode* newpart = current->next;
		current->next = nullptr;
		current = newpart;
	}
	return parts;
    }
};