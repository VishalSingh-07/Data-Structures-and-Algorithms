#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;

    // head=(struct Node *)malloc(sizeof(struct Node));
    head=new Node;
    head->data=A[0];
    head->prev=head;
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=head;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

void Display(Node* p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int Length(struct Node* p)
{
    int len = 0;
    if(p==NULL)
    {
        return len;
    }
    do
    {
        len++;
        p=p->next;
    } while (p!=head);
    return len;
}


int Delete(struct Node *p, int index)
{
    struct Node *temp;
    int x=-1;
    if(index<0 || index>Length(p))
    {
        cout<<"Wrong Index [Out of the Range]"<<endl;
        return -1;
    }
    if(index==0)
    {
        x=p->data;
        p=p->next;
        if(p==head)
        {
            delete p;
            head=NULL;
        }
        else
        {
            p->prev=head->prev;
            head->prev->next=p;
            delete head;
            head=p;
        }
        
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        x=p->data;
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
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

    // cout<<Delete(head,6)<<" is deleted from Linked List"<<endl;
    Delete(head,5);
    Display(head);
    return 0;
    
}


