/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<A.size();i++)
        {
            while(A[i])
                {
                    pq.push(A[i]->val);
                    A[i]=A[i]->next;
                }
        }
    ListNode* ret= new ListNode(pq.top());
    ListNode* t=ret;
    pq.pop();
    while(pq.size())
        {
             ListNode* ne= new ListNode(pq.top());
            t->next=ne;
            pq.pop();
            t=t->next;
        }
    return ret;    
}
