#include <bits/stdc++.h>
#include "Queue_in_C++.h"
#include "Stack_in_C++.h"
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
            void RPreorder(Node *p);
            void RPostorder(Node *p);
            void RInorder(Node *p);
           

            void IPreorder(Node *p);
            void IPostorder(Node *p);
            void IInorder(Node *p);
            void Levelorder(Node *p);
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
void Tree :: RPreorder(Node *p)
{
      if(p!=NULL)
      {
            cout<<p->data<<" ";
            RPreorder(p->lchild);
            RPreorder(p->rchild);
      }
}
void Tree :: RInorder(Node *p)
{
      if(p!=NULL)
      {
            
            RInorder(p->lchild);
            cout<<p->data<<" ";
            RInorder(p->rchild);
      }
}
void Tree :: RPostorder(Node *p)
{
      if(p!=NULL)
      {
            RPostorder(p->lchild);
            RPostorder(p->rchild);
            cout<<p->data<<" ";
      }
}





// Iterative Approach

void Tree :: IPreorder(Node *p)
{
      Stack stk(100);
      
      while(p!=NULL || !stk.isEmptyStack())
      {
            if(p!=NULL)
            {
                  cout<<p->data<<" ";
                  stk.push(p);
                  p=p->lchild;
            }
            else
            {
                  p=stk.pop();
                  p=p->rchild;
            }
      }
}
void Tree :: IInorder(Node *p)
{
      Stack stk(100);
      
      while(p!=NULL || !stk.isEmptyStack())
      {
            if(p!=NULL)
            {
                  stk.push(p);
                  p=p->lchild;
            }
            else
            {
                  p=stk.pop();
                  cout<<p->data<<" ";
                  p=p->rchild;
            }
      }
}
void Tree :: IPostorder(Node *p)
{
      Stack stk1(100),stk2(100);
      stk1.push(p); // Push the root node onto stk1

      while(!stk1.isEmptyStack())
      {
            p=stk1.pop();
            stk2.push(p); // Push the popped node onto stk2

            if (p->lchild)
                  stk1.push(p->lchild); // Push the left child onto stk1

            if (p->rchild)
                  stk1.push(p->rchild); // Push the right child onto stk1

      }

      // Print nodes in stk2 to get the postorder traversal
      while (!stk2.isEmptyStack())
      {
            p = stk2.pop();
            cout << p->data << " ";
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




int main()
{
      Tree t;
      t.createTree();

      cout<<"\n--------Recursive Approach -----"<<endl;

      cout<<"Preorder of the created Tree: ";
      t.RPreorder(t.root);
      cout<<endl;

      cout<<"Postorder of the created Tree: ";
      t.RPostorder(t.root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      t.RInorder(t.root);
      cout<<endl;


      cout<<"\n--------Iterative Approach -----"<<endl;

      cout<<"Preorder of the created Tree: ";
      t.IPreorder(t.root);
      cout<<endl;

      cout<<"Postorder of the created Tree: ";
      t.IPostorder(t.root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      t.IInorder(t.root);
      cout<<endl;


      cout<<"Levelorder of the created Tree: ";
      t.Levelorder(t.root);
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

--------Recursive Approach -----
Preorder of the created Tree: 10 20 40 50 30 60 70
Postorder of the created Tree: 40 50 20 60 70 30 10
Inorder of the created Tree: 40 20 50 10 60 30 70

--------Iterative Approach -----
Preorder of the created Tree: 10 20 40 50 30 60 70
Postorder of the created Tree: 40 50 20 60 70 30 10
Inorder of the created Tree: 40 20 50 10 60 30 70
Levelorder of the created Tree: 10 20 30 40 50 60 70
*/