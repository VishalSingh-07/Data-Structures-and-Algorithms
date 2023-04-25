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
void Insert(struct Node *p,int index, int x)
{
    struct Node *temp;
    if(index<0 ||  index>Length(p))
    {
        cout<<"Wrong Index[Out of the range]"<<endl;
        return;
    }
    if(index==0)
    {
        temp=new Node;
        temp->data=x;
        if(head==NULL)
        {
            head=temp;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=temp;
            temp->next=head;
            head=temp;
        }
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        temp=new Node;
        temp->data=x;
        temp->next=p->next;
        p->next=temp;
    }
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    Display(head);
    cout<<endl;
    Insert(head,8,10);
    Display(head);
    return 0;
}