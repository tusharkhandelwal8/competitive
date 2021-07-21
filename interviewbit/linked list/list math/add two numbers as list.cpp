/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int sizea=0,sizeb=0;
        ListNode* curr=A;
        while(curr)
            {
                sizea++;
                curr=curr->next;
            }
        curr=B;
                while(curr)
            {
                sizeb++;
                curr=curr->next;
            }
        ListNode* cn=A;
        int carry=0,digit=0;
        if(sizea>=sizeb)
          { 
              curr=A;
              cn=B;
          }
         else
          curr=B;
          
          ListNode* ans=curr;
          curr=ans;
         
         while(A&&B)
            {
                digit=A->val+B->val+carry;
                carry=digit/10;
                digit=digit%10;
                ans->val=digit;
                A=A->next;
                B=B->next;
                ans=ans->next;
                
            }
        while(A)
            {
                digit=A->val+carry;
                carry=digit/10;
                digit=digit%10;
                ans->val=digit;
                A=A->next;
                if(A)
                ans=ans->next;
            }
        while(B)
            {
                digit=B->val+carry;
                carry=digit/10;
                digit=digit%10;
                ans->val=digit;
                B=B->next;
                if(B)
                ans=ans->next;
            }
            if(carry)
                {
                    
                            ans->next=cn;
                            ans->next->val=1;
                            ans->next->next=NULL;
                     
                        
                }
                return curr;
            
            
}
