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
    stack<Node*> st;
    Node *p=head;
    while(p!=NULL)
    {
        st.push(p);
        p=p->next;
    }
    int stackLength=st.size();

    // floor() means lower value i.e. floor(4.8)= 4, floor(4.2)= 4

    int popLength=(int)floor(stackLength/2.0);

    // pop values up to pop length
    while(popLength!=0)
    {
        st.pop();
        popLength--;
    }
    return st.top()->data;
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