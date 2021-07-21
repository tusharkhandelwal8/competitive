/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ca=A;
    ListNode* cb=B;
    ListNode* ans=A;
    if(A->val<=B->val)
        {   ans=A;
            ca=ca->next;
            while(ca&&cb)
                {
                    if(ca->val<=cb->val)
                        {
                            ans->next=ca;
                            ans=ans->next;
                            ca=ca->next;
                        }
                    else
                        {
                             ans->next=cb;
                            ans=ans->next;
                            cb=cb->next;
                        }
                }
            while(ca)
                {
                    ans->next=ca;
                            ans=ans->next;
                            ca=ca->next;
                }
            while(cb)
                {
                                                 ans->next=cb;
                            ans=ans->next;
                            cb=cb->next;
                }
                return A;
        }
    else
        {   ans=B;
            cb=cb->next;
            while(ca&&cb)
                {
                    if(ca->val<=cb->val)
                        {
                            ans->next=ca;
                            ans=ans->next;
                            ca=ca->next;
                        }
                    else
                        {
                             ans->next=cb;
                            ans=ans->next;
                            cb=cb->next;
                        }
                }
            while(ca)
                {
                    ans->next=ca;
                            ans=ans->next;
                            ca=ca->next;
                }
            while(cb)
                {
                                                 ans->next=cb;
                            ans=ans->next;
                            cb=cb->next;
                }
                return B;
        }
    
}
