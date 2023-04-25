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

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    cout<<"Length is "<<Length(head)<<endl;

    Display(head);

    return 0;
}


