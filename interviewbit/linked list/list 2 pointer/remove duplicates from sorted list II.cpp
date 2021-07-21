/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A->next==NULL)
    return A;
    map<int,int> m;
    ListNode* ans=A,*temp=A;
    while(ans)
        {
            m[ans->val]++;
            ans=ans->next;
        }
        ans=A;
    while(ans)
        {
            if(m[ans->val]>1)
                ans=ans->next;
            else
                break;
        }
    temp=ans;
    while(temp&&temp->next)
        {
            if(m[temp->next->val]>1)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        return ans;
}
