/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    int count=0;
    if(A->next==NULL||A==NULL)
        return 1;
    ListNode* curr=A;
    while(curr)
        {
            count++;
            curr=curr->next;
        }
    
            count=count/2;
            
    int tot=1;
    ListNode* left=A  ;
    ListNode* right=A;
        while(tot<=count)
            {
                tot++;
                right=right->next;
                
            }
            ListNode* temp=right;
            ListNode* prev=right;
            curr=right->next;
            while(curr)
                {
                    temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                    
                }
               // right->next=NULL;
        for(int i=0;i<count;i++)
            {
                if(prev->val!=left->val)
                    {
                        return 0;
                    }
                prev=prev->next;
                left=left->next;
            }
            return 1;
            
        
}
