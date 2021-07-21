/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL||A->next==NULL||B==1)
        return A;
    ListNode* ans=A;
    ListNode* an=ans;
    ListNode* curr=A->next,* prev=A,* temp=A;
    prev->next=NULL;
    int count=0;
    int ko=0;
    while(curr)
        {
            
                    temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                    if(count==0)
                        count=2;
                    else    
                        count++;
                
             if(count==B)
                {
                    ko++;
                    if(ko==1)
                       { ans=prev;
                         an=prev;  
                       }
                     else
                     {
                    an->next=prev;
                    an=an->next;
                     }
                    while(prev->next)
                        {
                            an=an->next;
                            prev=prev->next;
                        }
                    
                    prev=curr;
                    if(curr)
                    {
                        curr=curr->next;
                        prev->next=NULL;
                    }
                    count=0;
                }
            
        }
        an->next=NULL;
        return ans;
}
