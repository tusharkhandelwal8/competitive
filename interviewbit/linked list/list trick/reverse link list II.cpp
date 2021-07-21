/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* curr=A;
    ListNode* prev=A;
    ListNode* temp=A;
    int count=1;
    if(B==C)
        return A;
   else if(B==1)
    {
    ListNode* pb=A;
     prev=curr;
     curr=curr->next;
     count=B;
    while(count<C)
        {
           count++;
           temp=curr->next;
           curr->next=prev;
           if(count==C)
            {
                A->next=temp;
                return curr;
            }
           prev=curr;    
           curr=temp;

            
        }
        return A;
    }
    while(count<B-1)
        {
        
                    count++;
                    curr=curr->next;
                
        }
    ListNode* joint=curr; 
    ListNode* start=curr->next;
     prev=curr->next;
     curr=curr->next->next;
     count=B;
    while(count<C)
        {
           count++;
           temp=curr->next;
           curr->next=prev;
           if(count==C)
            {
                joint->next=curr;
                start->next=temp;
            }
           prev=curr;    
           curr=temp;

            
        }
        return A;
        
        
}
