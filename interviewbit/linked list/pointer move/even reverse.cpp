/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL||A->next==NULL||A->next->next==NULL||A->next->next->next==NULL)
        return A;
   
    ListNode* even=A->next;
    ListNode* odd=A;
    ListNode* tempo=odd,*tempe=even;
      A=A->next->next;  
     int  count=3;
    while(A)
        {
            if(count%2==0)
                {
                    tempe->next=A;
                    A=A->next;
                    tempe=tempe->next;
                }
            else
                {
                    tempo->next=A;
                    A=A->next;
                    tempo=tempo->next;
                }
                count++;
            
        }
        tempo->next=NULL;
        tempe->next=NULL;
       // return odd;
      //  return even;
        ListNode* prev=even;
        ListNode* curr=even->next;
        tempe=even;
        even->next=NULL;
        
        while(curr)
            {
                tempe=curr->next;
                curr->next=prev;
                prev=curr;
                curr=tempe;
            }
        ListNode* ans=odd;
         ListNode* temp=odd;
        even=prev; 
         count=1;
        odd=odd->next;
        while(odd||even)
            {
                if(count%2==1)
                    {
                        temp->next=even;
                        temp=temp->next;
                        even=even->next;
                    }
                else
                    {
                        temp->next=odd;
                        temp=temp->next;
                        odd=odd->next;
                    }
                    count++;
                    
            }
            return ans;
        
    
    
    
}
