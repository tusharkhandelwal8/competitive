/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* curr=new ListNode(0);
    ListNode* cg=curr;
    ListNode* temp=A;
    int count=0;
    int odd=1;
    while(A)
        {   count=0;
           
            if(odd%2==1)
            { 
            while(count<B)
                {
                   count++;
        
                }
               
            }
            else
            {
                while(count<=B)
                    {
                        cg->next=A;
                        cg=cg->next;
                        A=A->next;
                        count++;
                    }
            }
            odd++;
                
                    
            
        }
        return curr->next;
    
}
