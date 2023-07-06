#include <bits/stdc++.h>
#include "Queue_in_C++.h"
using namespace std;

class Tree
{
      public:
            Node *root;
            Tree()
            {
                  root=NULL;
            }
            void createTree();
            int Count(Node *p);
            int Deg2Count(Node *p);
            int Height(Node *root);
            int Sum(Node *root);
};

void Tree :: createTree() // creating a binary tree
{
      Node *p,*t;
      int x;
      Queue q(100);

      cout<<"Enter the root value: ";
      cin>>x;
      root=new Node;
      root->data=x;
      root->lchild=root->rchild=NULL;
      q.enqueue(root);

      while(!q.isEmpty())
      {
            p=q.dequeue();
            cout<<"Enter the left child value of "<<p->data<<" :";
            cin>>x;
            if(x!=-1)
            {
                  t=(struct Node*)malloc(sizeof(struct Node));
                  t->data=x;
                  t->lchild=t->rchild=NULL;
                  p->lchild=t;
                  q.enqueue(t);
            }
            cout<<"Enter the right child value of "<<p->data<<" :";
            cin>>x;
            if(x!=-1)
            {
                  t=new Node;
                  t->data=x;
                  t->lchild=t->rchild=NULL;
                  p->rchild=t;
                  q.enqueue(t);
            }
      }
}
int Tree :: Count(Node *p)
{
      if(p!=NULL)
      {
            return Count(p->lchild)+Count(p->rchild)+1;
      }
      return 0;
}

int Tree :: Deg2Count(Node *p) // Counting the nodes with degree two
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Deg2Count(p->lchild);
            y=Deg2Count(p->rchild);

            if(p->lchild && p->rchild)
            {
                  return x+y+1;
            }
            else
            {
                  return x+y;
            }
      }
      return 0;
}

int Tree :: Sum(Node *p)
{
      if(p!=NULL)
      {
            return Sum(p->lchild)+Sum(p->rchild)+p->data;
      }
      return 0;
}

int Tree :: Height(Node *p)
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Height(p->lchild);
            y=Height(p->rchild);
            if(x>y)
            {
                  return x+1;
            }
            else
            {
                  return y+1;
            }
      }
      return 0;
}

int main()
{
      Tree t;
      t.createTree();

      cout<<"Number of Nodes in the Tree: "<<t.Count(t.root);
      cout<<endl;


      cout<<"Number of Nodes (whose Degree is 2) in the Tree: "<<t.Deg2Count(t.root);
      cout<<endl;


      cout<<"Sum of Nodes in the Tree: "<<t.Sum(t.root);
      cout<<endl;


      cout<<"Height of the Tree: "<<t.Height(t.root);
      cout<<endl;

      return 0;
}

/*
Output:
Enter the root value: 10
Enter the left child value of 10 :20
Enter the right child value of 10 :30
Enter the left child value of 20 :40
Enter the right child value of 20 :50
Enter the left child value of 30 :60
Enter the right child value of 30 :70
Enter the left child value of 40 :-1
Enter the right child value of 40 :-1
Enter the left child value of 50 :-1
Enter the right child value of 50 :-1
Enter the left child value of 60 :-1
Enter the right child value of 60 :-1
Enter the left child value of 70 :-1
Enter the right child value of 70 :-1
Number of Nodes in the Tree: 7
Number of Nodes (whose Degree is 2) in the Tree: 3
Sum of Nodes in the Tree: 280
Height of the Tree: 3
*/
