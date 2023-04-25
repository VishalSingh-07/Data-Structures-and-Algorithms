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
        Node *head;
    public:
        LinkedList()
        {
            head=NULL;
        }
        LinkedList(int A[],int n);
        ~LinkedList();
        void Display();
        int MiddleUsingLength();
        int MiddleUsingTwoPointers();
        int MiddleUsingStack();
};

LinkedList:: LinkedList(int A[], int n) // creating a linked list
{
    head=new Node;
    head->data=A[0];
    head->next=NULL;
    Node *last=head;
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

LinkedList:: ~LinkedList()
{
    Node *p=head;
    while(p!=NULL)
    {
        p=p->next;
        delete p;
        p=head;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int LinkedList:: MiddleUsingLength() {
    int count=0;
    Node* p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    Node *q=head;
    count=count/2;
    while(count--)
    {
        q=q->next;
    }
    return q->data;
}

int LinkedList:: MiddleUsingTwoPointers() {
    if(head==NULL)
    {
        return -1;
    }
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int LinkedList:: MiddleUsingStack() {
    stack<Node*> st;
    Node *p=head;
    while(p!=NULL)
    {
        st.push(p);
        p=p->next;
    }
    int stackLength=st.size();

    // floow() means lower value i.e. floor(4.8)= 4, floor(4.2)= 4

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
    int A[] = {3,4,5,6,7};
    int n = sizeof(A)/sizeof(A[0]);
    // cout<<n<<endl;
    LinkedList L(A,n);
    L.Display();

    cout<<"Middle Element using Method 1 [Length]: "<<L.MiddleUsingLength()<<endl;
    cout<<"Middle Element using Method 2 [Two Pointer]: "<<L.MiddleUsingTwoPointers()<<endl;
    cout<<"Middle Element using Method 3 [Using Stack]: "<<L.MiddleUsingStack()<<endl;
    return 0;
}

/*
Output --

3 4 5 6 7 
Middle Element using Method 1 [Length]: 5
Middle Element using Method 2 [Two Pointer]: 5
Middle Element using Method 3 [Using Stack]: 5
*/