#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int row;
    int column;
    int value;
    Node *next;
};

class Sparse_Matrix{
    private:
        Node *first=NULL;
        int m,n;
    public:
        Sparse_Matrix();
        void Display();
        void Add(Sparse_Matrix);
        Node *GetHead(){
            return first;
        }
};

void Sparse_Matrix::Add(Sparse_Matrix b)
{
    Node *first1=first,*first2=b.GetHead(),*first3=NULL,*p=NULL,*q=NULL;
    while (first1!=NULL && first2!=NULL)
    {
        if(first1->row<first2->row)
        {
            p=first1;
            if(q!=NULL)
            {
                q->next=p;
            }     
            else
            {
                first3=p;
            }    
            q=p;
            first1=first1->next;
            p->next=NULL;
        }
        else if(first2->row<first1->row)
        {
            p=first2;
            if(q!=NULL)
            {
                q->next=p;
            } 
            else
            {
                first3=p;
            }
            q=p;
            first2=first2->next;
            p->next=NULL;
        }
        else
        {   
            if(first1->column<first2->column)
            {
                p=first1;
                if(q!=NULL)
                {
                    q->next=p;
                }
                else
                {
                    first3=p;
                }
                q=p;
                first1=first1->next;
                p->next=NULL;
            }
            else if(first2->column<first1->column)
            {
                p=first2;
                if(q!=NULL)
                {
                    q->next=p;
                }   
                else
                {
                    first3=p;
                }  
                q=p;
                first2=first2->next;
                p->next=NULL;
            }
            else{
                p=first1;
                if(q!=NULL)
                {
                    q->next=p;
                }  
                else
                {
                    first3=p;
                }   
                q=p;
                p->value=first1->value+first2->value;
                first1=first1->next;
                Node *temp=first2;
                first2=first2->next;
                temp->next=NULL;
                p->next=NULL;
            }
        }
    }
    if(first1!=NULL)
    {
         p->next=first1;
    }  
    else
    {
        p->next=first2;
    }   
    first=first3;
    
}

Sparse_Matrix::Sparse_Matrix()
{
    int i,j,data;
    cout<<"Enter the dimension of Matrix: "<<endl;
    cout<<"Enter the Number of Rows: ";
    cin>>m;
    cout<<"Enter the Number of Columns: ";
    cin>>n;
    Node *p=NULL,*q=NULL;
    cout<<"Enter the Matrix: \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>data;
            if(data!=0)
            {
                p=new Node;
                if(q!=NULL)
                {
                    q->next=p;
                }  
                else
                {
                    first=p;
                }    
                p->value=data;
                p->row=i;
                p->column=j;
                p->next=NULL;
                q=p;
            }
        }
    }

}
void Sparse_Matrix::Display()
{
    Node *p=NULL;
    p=first;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {   
            if(p && p->row==i && p->column==j)
            {
                cout<<p->value<< " ";
                p=p->next;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


int main()
{
    cout<<"For Sparse Matrix A:"<<endl;
    Sparse_Matrix a;
    cout<<endl;
    cout<<"Matrix A:"<<endl;
    a.Display();

    cout<<"For Sparse Matrix B:"<<endl;
    Sparse_Matrix b;
    cout<<endl;
    cout<<"Matrix B:"<<endl;
    b.Display();

    cout<<"Addition of Matrix A and Matrix B"<<endl;
    a.Add(b);
    a.Display();
    return 0;

}

/*
Output:
For Sparse Matrix A:
Enter the dimension of Matrix: 
Enter the Number of Rows: 5
Enter the Number of Columns: 6
Enter the Matrix: 
0 0 0 0 8 0
0 0 0 7 0 0
5 0 0 0 9 0
0 0 0 0 0 3
6 0 0 4 0 0

Matrix A:
0 0 0 0 8 0 
0 0 0 7 0 0 
5 0 0 0 9 0 
0 0 0 0 0 3 
6 0 0 4 0 0 


For Sparse Matrix B:
Enter the dimension of Matrix:
Enter the Number of Rows: 5
Enter the Number of Columns: 6
Enter the Matrix:
0 0 0 0 8 0
0 0 0 7 0 0
5 0 0 0 9 0
0 0 0 0 0 3
6 0 0 4 0 0

Matrix B:
0 0 0 0 8 0
0 0 0 7 0 0
5 0 0 0 9 0
0 0 0 0 0 3
6 0 0 4 0 0


Addition of Matrix A and Matrix B
0 0 0 0 16 0
0 0 0 14 0 0
10 0 0 0 18 0
0 0 0 0 0 6
12 0 0 8 0 0
*/