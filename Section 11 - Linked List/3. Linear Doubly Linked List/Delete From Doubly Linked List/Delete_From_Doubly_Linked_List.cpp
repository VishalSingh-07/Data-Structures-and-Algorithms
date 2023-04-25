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

int Delete(struct Node *p, int index)
{
    struct Node *temp;
    int x=-1;
    if(index<1 || index>Length(p))
    {
        cout<<"Wrong Index [Out of the Range]"<<endl;
        return -1;
    }
    if(index==1)
    {
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        x=p->data;
        delete p;
        
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        delete p;
    }
    return x;
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    cout<<"Length is "<<Length(head)<<endl;

    Display(head);
    cout<<endl;

    Delete(head,4);
    Display(head);

    return 0;
}