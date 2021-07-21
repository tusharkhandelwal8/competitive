/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* start=A;
    ListNode* curr=A;
    ListNode* temp=A;
    while(curr->next)
        {
            if(start->val>curr->next->val)
                {
                    temp=curr->next;
                    curr->next=curr->next->next;
                    temp->next=start;
                    start=temp;
                    temp=start;
                    
                }
            else if(curr->val>curr->next->val)
                {
                    while(temp->next->val<curr->next->val)
                        {
                            temp=temp->next;
                        }
                        ListNode* te=curr->next;
                        curr->next=curr->next->next;
                        te->next=temp->next;
                        temp->next=te;
                        temp=start;
                }
            else
                curr=curr->next;
        }
        return start;
}
