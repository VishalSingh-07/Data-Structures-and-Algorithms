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
int Length(struct Node *p)
{
    int length=0;
    do
    {
        length++;
        p=p->next;
    } while (p!=head);
    return length; 
}
int  Delete(struct Node *p,int index)
{
    struct Node *q;
    int x;
    if(index<0 ||  index>Length(p))
    {
        cout<<"Wrong Index[Out of the range]"<<endl;
        return -1;
    }
    if(index==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(head==p)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for(int i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    Display(head);
    cout<<endl;

    cout<<Delete(head,2)<< "element is deleted from Linked List"<<endl;
    Display(head);
    return 0;
}