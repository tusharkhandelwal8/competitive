/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* merge(ListNode* ans,ListNode* left,ListNode* right)
    {   ListNode* curr=ans;
        while(left&&right)
            {
                if(left->val<=right->val)
                    {
                        curr->next=left;
                        curr=curr->next;
                        left=left->next;
                    }
                else
                    {
                        curr->next=right;
                        curr=curr->next;
                        right=right->next;
                    }
            }
        while(left)
            {
                        curr->next=left;
                        curr=curr->next;
                        left=left->next;
            }
        while(right)
            {
                         curr->next=right;
                        curr=curr->next;
                        right=right->next;
            }
            return ans->next;
    }
ListNode* Solution::sortList(ListNode* A) {
    ListNode* start=A;
    if(A->next==NULL)
        return A;
    int count=0;
    while(start)
        {
            start=start->next;
            count++;
        }
        count=(count+1)/2;
    ListNode* left=A;
    ListNode* right=A;
    start=A;
    int curr=1;

    while(curr<count)
        {
            start=start->next;
            curr++;
        }
        right=start->next;
        start->next=NULL;
        left=A;
        left=sortList(left);
        right=sortList(right);
        ListNode* ans= new ListNode(0);
        ans=merge(ans,left,right);
        return ans;
        
    
}
