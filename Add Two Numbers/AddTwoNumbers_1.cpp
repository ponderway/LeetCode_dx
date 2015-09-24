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
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
			
        ListNode* pHead = NULL;
		ListNode* pLast = NULL;
		ListNode* pNode = NULL;
		int token = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int temp = l1->val + l2->val + token;
            token = temp / 10;
            pNode = new ListNode(temp % 10);
			
			if(pHead == NULL)
				pHead = pLast = pNode;
			else
			{
			   	pLast->next = pNode;
			    pLast = pNode; 
			}

			l1 = l1->next;
			l2 = l2->next;
        }
		
		ListNode* l3 = (l1 != NULL) ? l1 : l2;
		while(l3 != NULL)
		{
			int temp = l3->val + token;
			token = temp / 10;
			pNode = new ListNode(temp % 10);
			pLast->next = pNode;
			pLast = pNode;
			l3 = l3->next;
		}
		
		if(token)
			pLast->next = new ListNode(token); 
			
		return pHead;
    }	
        
};