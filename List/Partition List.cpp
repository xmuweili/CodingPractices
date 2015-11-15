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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;        
        ListNode* cur = head;

        ListNode* less = NULL;
        ListNode* greater = NULL;
        ListNode* less_cur = NULL;
        ListNode* greater_cur = NULL;

        while(cur != NULL) {
        	if(cur->val < x)
        	{
        		if(less == NULL)
        		{
        			less = cur;
        			less_cur = cur;
        		}
        		else
        		{
        			less_cur->next = cur;
        			less_cur = cur;
        		}
        	}
        	else {
        		if(greater == NULL)
        		{
        			greater = cur;
        			greater_cur = cur;
        		}
        		else
        		{
        			greater_cur->next = cur;
        			greater_cur = cur;
        		}
        	}
        	cur = cur->next;
        }
        
        if(greater != NULL) greater_cur->next = NULL;
        if(less != NULL) {
		    less_cur->next = greater;
		    return less;        	
        }
        else
        	return greater;
    }
};