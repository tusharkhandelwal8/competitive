/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int count=0;
    if(A==NULL)
        return A;
    if(A->next==NULL)
        return NULL;
        
    ListNode* curr=A;
    while(curr)
        {
            count++;
            curr=curr->next;
        }
    curr=A;
    if(B>=count)
        return A->next;
    
    count=count-B+1;
    int c=1;
    while(c!=count-1)
        {
            curr=curr->next;
            c++;
        }
        curr->next=curr->next->next;
        return A;
}
