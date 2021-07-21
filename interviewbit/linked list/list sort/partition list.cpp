/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {

    ListNode* s=A;
    ListNode* x=A;
    ListNode* prevx=A;
    ListNode* ret=NULL;
    while(x)
        {
           if(x->val>=B)
            {
                prevx=x;
                x=x->next;
                
            }
            else if(s!=x) 
            {
                
                if(s->val>=B)
                    {
                        prevx->next=x->next;
                        
                        x->next=s;
                        s=x;
                      x=prevx->next;
                      ret=s;
                    }
                else
                    {
                        prevx->next=x->next;
                        x->next=s->next;
                        s->next=x;
                        s=x;
                       x=prevx->next;
                        
                    }
            }
            else
            {
                prevx=x;
                x=x->next;
                if(x)
                    {
                        if(s->next->val<B)
                            s=s->next;
                    }
            }
        }
        if(ret==NULL)
            ret=A;
        
        return ret;    

}
