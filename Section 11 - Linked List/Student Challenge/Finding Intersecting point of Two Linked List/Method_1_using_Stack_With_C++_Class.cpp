#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *head1;
        Node *head2;
    public:
        Node *getHead1()
        {
            return head1;
        }
        Node *getHead2()
        {
            return head2;
        }
        void create1(int A[], int n1);
        void create2(int B[], int n2, Node *q);
        void Display1();
        void Display2();
        int IntersectionPointUsingStack();
};

void LinkedList:: create1(int A[], int n) // creating a linked list
{
    head1=new Node;
    head1->data=A[0];
    head1->next=NULL;
    Node *last=head1;
    Node *t;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void LinkedList:: create2(int B[], int n, Node *q) // creating a linked list
{
    head2=new Node;
    head2->data=B[0];
    head2->next=NULL;
    Node *last=head2;
    Node *t;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=q;
}

void LinkedList::Display1()
{
    Node *p = head1;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
void LinkedList::Display2()
{
    Node *p = head2;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int LinkedList:: IntersectionPointUsingStack(){
    stack<Node*> st1;
    stack<Node*> st2;
    Node *p=head1;
    Node *q=head2;
    while(p!=NULL)
    {
        st1.push(p);
        p=p->next;
    }
    while(q!=NULL)
    {
        st2.push(q);
        q=q->next;
    }

    Node *i;
    while(st1.top()==st2.top())
    {
        i=st1.top();
        st1.pop();
        st2.pop();
    }
    return i->data;

}


int main()
{
    int A[] = {8,6,3,9,10,4,2,2};
    int B[]={20,30,40};
    int n1 = sizeof(A)/sizeof(A[0]);

    LinkedList L;

    L.create1(A,n1);


    // create second linked list

    Node *temp=L.getHead1();


    // move temp pointer to node where we have connected second LL to first LL

    int i=4;
    while(i>0)
    {
        temp=temp->next;
        i--;
    }

    cout<<"Here we have connected 2nd LL to 1st LL at Node = "<<temp->data<<endl;

    int n2= sizeof(B)/sizeof(B[0]);
    L.create2(B,n2,temp);
    cout<<"First Linked List: ";
    L.Display1();
    cout<<"\nSecond Linked List: ";
    L.Display2();
    cout<<endl;
    cout<<"Intersection Point: "<<L.IntersectionPointUsingStack()<<endl;
    
    return 0;
}


/*
Output:
Here we have connected 2nd LL to 1st LL at Node = 10
First Linked List: 8 6 3 9 10 4 2 2 

Second Linked List: 20 30 40 10 4 2 2 

Intersection Point: 10
*/