#include <bits/stdc++.h>
using namespace std;
struct  Node
{
    int data;
    struct Node *next;
}*head;
void create(int A[], int n) // Circular Singly Linked Listed 
{
    struct Node *t,*last;
    head=new Node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *head)
{
    Node *p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

}

void RDisplay(struct Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
    flag=0;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    // Display(head);
    RDisplay(head);
    return 0;
}