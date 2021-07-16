/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* ret=new RandomListNode(A->label) ;
    RandomListNode* t=A;
    RandomListNode* r=ret;
      unordered_map<int,RandomListNode*> um,umc;
    while(t)
        {
          um[t->label]=t;
          t=t->next;
        }
    t=A;    
    umc=um;
    while(t->next!=NULL)
        {
            
            t=t->next;
            r->next=new RandomListNode(t->label);
            r=r->next;
        }
    r=ret;
    while(r)
        {
            umc[r->label]=r;
            r=r->next;
        }
   // umc=um;
    t=A;
    r=ret;
    while(t)
        {
            if(t->random)
                {
                    r->random=umc[t->random->label];
                }
            t=t->next;
            r=r->next;
        }
    
     
    
  
    return ret;
}
