#include <bits/stdc++.h>
using namespace std;

struct Node{
      struct Node *lchild;
      int data;
      struct Node *rchild;
}*root=NULL;

void Inorder(struct Node *p)
{
      if(p!=NULL)
      {
            Inorder(p->lchild);
            cout<<p->data<<" ";
            Inorder(p->rchild);
      }
}

int Height(struct Node *p)
{
      int x,y;
      if(p==NULL)
      {
            return -1;
      }
      x=Height(p->lchild);
      y=Height(p->rchild);
      if(x>y)
      {
            return x+1;
      }
      else{
            return y+1;
      }
}

struct Node *InPre(struct Node *p)
{
      while(p!=NULL && p->rchild!=NULL)
      {
            p=p->rchild;
      }
      return p;
}

struct Node *InSucc(struct Node *p)
{
      while(p!=NULL && p->lchild!=NULL)
      {
            p=p->lchild;
      }
      return p;
}




// Iterative Approach

void Insert(int key)
{
      struct Node *t=root;
      struct Node *r=NULL,*p;
      if(root==NULL)
      {
            p=(struct Node*)malloc(sizeof(struct Node));
            p->data=key;
            p->lchild=p->rchild=NULL;
            root=p;
            return;
      }
      while(t!=NULL)
      {
            r=t;
            if(key==t->data)
            {
                  return;
            }
            else if(key<t->data)
            {
                  t=t->lchild;
            }
            else
            {
                  t=t->rchild;
            }
      }
      p=(struct Node*)malloc(sizeof(struct Node));
      p->data=key;
      p->lchild=p->rchild=NULL;

      if(key<r->data)
      {
            r->lchild=p;
      }
      else{
            r->rchild=p;
      }
      
}

Node* Search(struct Node *t, int key)
{
      while(t!=NULL)
      {
            if(key==t->data)
            {
                  return t;
            }
            else if(key<t->data)
            {
                  t=t->lchild;
            }
            else{
                  t=t->rchild;
            }
      }
      return NULL;
}

// Recursive Approach

Node* RInsert(struct Node *p,int key)
{
      struct Node *t=NULL;
      if(p==NULL)
      {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=key;
            t->lchild=t->rchild=NULL;
            return t;
      }
      if(key<p->data)
      {
            p->lchild=RInsert(p->lchild,key);
      }
      else if(key > p->data)
      {
            p->rchild=RInsert(p->rchild,key);
      }
      return p;
}

Node* RSearch(struct Node *t, int key)
{
      if(t==NULL)
      {
            return NULL;
      }
      if(key==t->data)
      {
            return t;
      }
      else if(key<t->data)
      {
            RSearch(t->lchild,key);
      }
      else 
      {
            RSearch(t->rchild,key);
      }
}

struct Node *RDelete (struct Node *p, int key)
{
      struct Node *q;
      if(p==NULL)
      {
            return NULL;
      }
      if(p->lchild==NULL && p->rchild==NULL)
      {
            if(p==root)
            {
                  root=NULL;
            }
            delete p;
            return NULL;
      }
      if(key<p->data)
      {
            p->lchild=RDelete(p->lchild,key);
      }
      else if(key>p->data)
      {
            p->rchild=RDelete(p->rchild,key);
      }
      else 
      {
            if(Height(p->lchild)>Height(p->rchild)) // Inorder Predecessor
            {
                  q=InPre(p->lchild);
                  p->data=q->data;
                  p->lchild=RDelete(p->lchild,q->data);
            }
            else // Inorder Successor
            {
                  q=InSucc(p->rchild);
                  p->data=q->data;
                  p->rchild=RDelete(p->rchild,q->data); 
            }
      }
      return p;
}





int main()
{
      cout <<"Iterative Approach:---"<<endl;
      Insert(10);
      Insert(5);
      Insert(20);
      Insert(8);
      Insert(30);
      

      cout<<"Inorder Traversal: "<<endl;
      Inorder(root);

      int x;
      cout<<endl;
      cout<<"Enter the value to be search in BST: ";
      cin>>x;

      if(Search(root,x)==NULL)
      {
            cout<<x<<" is not found in the tree";
      }
      else
      {
            cout<<x<<" is found in the tree";
      }


      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<endl;

      cout <<"\nRecursive Approach:---"<<endl;
      root=RInsert(root,10);
      RInsert(root,5);
      RInsert(root,20);
      RInsert(root,8);
      RInsert(root,30);
      

      cout<<"Inorder Traversal: "<<endl;
      Inorder(root);

      int y;
      cout<<endl;
      cout<<"Enter the value to be search in BST: ";
      cin>>y;

      if(RSearch(root,y)==NULL)
      {
            cout<<y<<" is not found in the tree";
      }
      else
      {
            cout<<y<<" is found in the tree";
      }


      int del;
      cout<<endl;
      cout<<"Enter the value to be deleted from BST: ";
      cin>>del;

      if(RDelete(root,del)==NULL)
      {
            cout<<del<<" is not deleted from the tree";
      }
      else
      {
            cout<<del<<" is deleted from the tree";
      }
      
      cout<<"\nInorder Traversal: "<<endl;
      Inorder(root);


      return 0;
}

/*
Output:

Iterative Approach:---
Inorder Traversal: 
5 8 10 20 30 
Enter the value to be search in BST: 5
5 is found in the tree




Recursive Approach:---
Inorder Traversal: 
5 8 10 20 30 
Enter the value to be search in BST: 5
5 is found in the tree
Enter the value to be deleted from BST: 5
5 is deleted from the tree
Inorder Traversal: 
8 10 20 30
*/