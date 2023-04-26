#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* create(int n)
{
    struct Node *t,*last,*poly=NULL;

    cout<<"Enter each term with coefficient and Exponent "<<endl;
    for(int i=0;i<n;i++)
    {
        t=new Node;
        cout<<"For Node "<<i<<endl;
        cout<<"Enter Coefficient: ";
        cin>>t->coeff;
        cout<<"Enter Exponent: ";
        cin>>t->exp;
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
    return poly;
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->coeff<<"x^"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<endl;
}
struct Node *add(struct Node *p1, struct Node *p2)
{
    struct Node *t,*last=NULL,*sum=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->exp>p2->exp)
        {
            t=new Node;
            t->coeff=p1->coeff;
            t->exp=p1->exp;
            p1=p1->next;
            t->next=NULL;

            if(sum==NULL)
            {
                sum=t;
                last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
        }
        else if(p1->exp<p2->exp)
        {
            t=new Node;
            t->coeff=p2->coeff;
            t->exp=p2->exp;
            p2=p2->next;
            t->next=NULL;

            if(sum==NULL)
            {
                sum=t;
                last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
        }
        else
        {
            t=new Node;
            t->coeff=p1->coeff+p2->coeff;
            t->exp=p1->exp;
            p1=p1->next;
            p2=p2->next;
            t->next=NULL;

            if(sum==NULL)
            {
                sum=t;
                last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
        }
    }
    while(p1!=NULL)
    {
        t=new Node;
        t->coeff=p1->coeff;
        t->exp=p1->exp;
        p1=p1->next;
        last->next=t;
        last=t;
    }
    while(p2!=NULL)
    {
         t=new Node;
        t->coeff=p2->coeff;
        t->exp=p2->exp;
        p2=p2->next;
        last->next=t;
        last=t;
    }
    return sum;
}
int main()
{
    struct Node *p1=NULL,*p2=NULL,*sum=NULL;
    int n1,n2;
    cout<<"Enter the number of terms in Polynomial 1: ";
    cin>>n1;
    p1=create(n1);

    cout<<"Enter the number of terms in Polynomial 2: ";
    cin>>n2;
    p2=create(n2);

    cout<<"Polynomial 1: "<<endl;
    Display(p1);

    cout<<"Polynomial 2: "<<endl;
    Display(p2);


    sum=add(p1,p2);
    cout<<"Adding of Polynomial 1 and Polynomial 2"<<endl;
    Display(sum);
    return 0;
}

/*
Output:

Enter the number of terms in Polynomial 1: 4
Enter each term with coefficient and Exponent 
For Node 0
Enter Coefficient: 5
Enter Exponent: 4
For Node 1
Enter Coefficient: 4
Enter Exponent: 3
For Node 2
Enter Coefficient: 3
Enter Exponent: 2
For Node 3
Enter Coefficient: 1
Enter Exponent: 0


Enter the number of terms in Polynomial 2: 4
Enter each term with coefficient and Exponent 
For Node 0
Enter Coefficient: 4
Enter Exponent: 3
For Node 1
Enter Coefficient: 9
Enter Exponent: 2
For Node 2
Enter Coefficient: 6
Enter Exponent: 1
For Node 3
Enter Coefficient: 7
Enter Exponent: 0


Polynomial 1:
5x^4 + 4x^3 + 3x^2 + 1x^0 +

Polynomial 2:
4x^3 + 9x^2 + 6x^1 + 7x^0 +

Adding of Polynomial 1 and Polynomial 2
5x^4 + 8x^3 + 12x^2 + 6x^1 + 8x^0 +
*/