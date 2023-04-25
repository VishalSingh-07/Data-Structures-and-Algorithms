#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;

void create(int A[], int n)
{
    struct Node *t;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
 
    for(int i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int middleNode(struct Node* head) {
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    cout<<"\nMiddle of the Linked list is "<<middleNode(first)<<endl;
    return 0;
}

/*
Output:

1 2 3 4 5 
Middle of the Linked list is 3

*/