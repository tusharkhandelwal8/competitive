/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* t=A;
    while(t&&t->next)
        {
            if(t->next->val==t->val)
                {
                    t->next=t->next->next;
                }
            else
                t=t->next;
                
        }
        return A;
}
