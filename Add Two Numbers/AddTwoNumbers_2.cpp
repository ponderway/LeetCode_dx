/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* pHead = new ListNode(-1); //头节点
		ListNode* pLast = pHead;
		int token = 0; // 进位
		
		for(ListNode* p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL; 
			p1 = (p1 == NULL ? NULL : p1->next),
			p2 = (p2 == NULL ? NULL : p2->next),
			pLast = pLast->next)
		{
			int a = (p1 == NULL ? 0 : p1->val);
			int b = (p2 == NULL ? 0 : p2->val);
			int sum = a + b + token;
			token = sum / 10;
			pLast->next = new ListNode(sum % 10);
		}
		
		if(token)
			pLast->next = new ListNode(token);
			
		return pHead->next;   
    }
};