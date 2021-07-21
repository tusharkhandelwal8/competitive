/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    vector<ListNode*> v;
    ListNode* temp=A;
    while(A)
        {
            v.push_back(A);
            A=A->next;
        }
    B=B%(v.size());
    if(B==0||B==v.size())
        return temp;
    
     ListNode* ans=v[v.size()-B];
     v[v.size()-1]->next=v[0];
     v[v.size()-B-1]->next=NULL;
     return ans;
    
}
