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
            void Preorder(Node *p);
            void Postorder(Node *p);
            void Inorder(Node *p);
            void Levelorder(Node *p);
            int Count(Node *p);
            int Height(Node *root);
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
void Tree :: Preorder(Node *p)
{
      if(p!=NULL)
      {
            cout<<p->data<<" ";
            Preorder(p->lchild);
            Preorder(p->rchild);
      }
}
void Tree :: Inorder(Node *p)
{
      if(p!=NULL)
      {
            
            Inorder(p->lchild);
            cout<<p->data<<" ";
            Inorder(p->rchild);
      }
}
void Tree :: Postorder(Node *p)
{
      if(p!=NULL)
      {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout<<p->data<<" ";
      }
}


void Tree :: Levelorder(Node *root)
{
      Queue q(100);
      cout<<root->data<<" ";
      q.enqueue(root);
      while(!q.isEmpty())
      {
            root=q.dequeue();
            if(root->lchild)
            {
                  cout<<root->lchild->data<<" ";
                  q.enqueue(root->lchild);
            }
            if(root->rchild)
            {
                  cout<<root->rchild->data<<" ";
                  q.enqueue(root->rchild);
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

int Tree :: Height(Node *p)
{
      int x=0,y=0;
      if(p)
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

      cout<<"Preorder of the created Tree: ";
      t.Preorder(t.root);
      cout<<endl;

      cout<<"Postorder of the created Tree: ";
      t.Postorder(t.root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      t.Inorder(t.root);
      cout<<endl;


      cout<<"Levelorder of the created Tree: ";
      t.Levelorder(t.root);
      cout<<endl;


      cout<<"Number of Nodes in the Tree: "<<t.Count(t.root);
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
Preorder of the created Tree: 10 20 40 50 30 60 70
Postorder of the created Tree: 40 50 20 60 70 30 10
Inorder of the created Tree: 40 20 50 10 60 30 70
Levelorder of the created Tree: 10 20 30 40 50 60 70
Number of Nodes in the Tree: 7
Height of the Tree: 3
*/