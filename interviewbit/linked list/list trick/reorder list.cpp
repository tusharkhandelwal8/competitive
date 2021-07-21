/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    vector<ListNode*> ans;
    ListNode* curr=A;
    while(curr)
        {
            ans.push_back(curr);
            curr=curr->next;
        }
        curr=A;
    int count=1,st=1,end=ans.size()-1;
    for(int i=1;i<ans.size();i++)
        {
            if(count%2==0)
                {
                    curr->next=ans[st];
                    st++;
                }
            else
                {
                    curr->next=ans[end];
                    end--;
                }
                count++;
                curr=curr->next;
        }
        curr->next=NULL;
        return A;
        
}
