#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*head=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;

    // head=(struct Node *)malloc(sizeof(struct Node));
    head=new Node;
    head->data=A[0];
    head->prev=head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Length(struct Node *p)
{
    int len=0; 
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *temp,*q;
    if(index<0 || index>Length(p))
    {
        cout<<"Wrong Index [Out of the Range]"<<endl;
        return ;
    }
    if(index==0)
    {
        temp=new Node;
        temp->data=x;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
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
        temp->prev=p;
        
        if(p->next!=NULL)
        {
            p->next->prev=temp;
        }
        p->next=temp;
    }
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    cout<<"Length is "<<Length(head)<<endl;

    Display(head);
    cout<<endl;

    Insert(head,5,44);
    Display(head);

    return 0;
}