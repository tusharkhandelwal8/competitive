/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* a=A;
    ListNode* b=A;
    while(b)
        {
            if(b->val==0)
                {   
                    if(a==b)
                        a=a->next;
                    else
                    {
                    a->val=0;
                    b->val=1;
                    a=a->next;
                    }
                }
                b=b->next;
        }
    
        return A;
}
