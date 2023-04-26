#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create()
{
    struct Node *t,*last;
    int num;

    cout<<"Enter the number of terms: ";
    cin>>num;

    cout<<"Enter each term with coefficient and Exponent "<<endl;
    for(int i=0;i<num;i++)
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
long eva(struct Node *p, int x)
{
    long val=0;
    while(p!=NULL)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;

}
int main()
{
    create();
    Display(poly);
    cout<<"\nAnswer of Evaluation for (x==1): "<<eva(poly,1);
    return 0;
}