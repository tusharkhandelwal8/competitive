#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
    void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node();  
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);  
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;  
} 







void append(Node** head_ref,int new_data)
{
    Node* new_node = new Node();
    new_node->data=new_data;
    Node* last=*head_ref;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}
void deletenode(Node** head_ref,int key)
{
    Node* temp= *head_ref,*prev;
    
    if(temp!=NULL&&temp->data==key)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
        
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
    return;
}

void deletepos(Node **head_ref,int pos)
{
    Node* temp=*head_ref,*del;
    for(int i=0;i<pos-1;i++)
    {   if(temp==NULL)
            return;
        if(temp!=NULL&&i==pos-2)
        {
            del=temp->next;
            temp->next=del->next;
            free(del);
            return;
        }
        temp=temp->next;
    }
    if(pos==1)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
}
int linklen(Node** head_ref,int count)
{   Node* check=*head_ref;
    if(*head_ref==NULL)
        return count;
    else
    {
        while(check->next!=NULL)
        {
            count++;
            check=check->next;
        }
        return count;
    }
    
}
void reverse(Node** head_ref)
{
    Node* cur=*head_ref;
    Node *prev=NULL,*next=NULL;
    while(cur!=NULL)
    {
       { next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;}
        *head_ref=prev;
        
    }
}


// Program to create a simple linked 
// list with 3 nodes 
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 
  
    
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with 

  
    // assign data to second node 
    second->data = 2; 
  
    // Link second node with the third node 
    second->next = third; 
  

  
    third->data = 3; // assign data to third node 
    third->next = NULL; 

push( &head,5);
push(&head,12);
append(&head,7);
deletenode(&head,5);


Node* n =head;
int count=1;
int p=linklen(&head,count);

while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
    cout << endl << p << endl;
reverse(&head);
n=head;
while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    }     
    
  
    
  
    return 0; 
} 
