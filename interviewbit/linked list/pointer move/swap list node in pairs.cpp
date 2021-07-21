/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL||A->next==NULL)
        return A;
    ListNode* ans=A->next;    
    ListNode* curr=A->next->next;
    ListNode* prev=A;
   ListNode* temp=A;
 //   ListNode* next=A;
    A->next->next=A;
    A->next=curr;
    while(curr&&curr->next)
        {
            temp=curr->next->next;
            prev->next=curr->next;
            prev->next->next=curr;
            curr=temp;
            prev=prev->next->next;
            
        }
    if(curr)
        prev->next=curr;
    else
        prev->next=NULL;
    
    return ans;    
    
}
