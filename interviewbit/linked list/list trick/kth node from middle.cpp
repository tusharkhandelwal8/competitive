/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int sum=0;
    ListNode* curr=A;
    while(curr)
        {
            sum++;
            curr=curr->next;
        }
        sum=sum/2+1;
        sum=sum-B ;
        int cur=1;
        if(cur>sum)
            return -1;
        else
            {
                while(cur!=sum)
                    {
                        cur++;
                        A=A->next;
                    }
                    return A->val;
            }
        
}
