#include <bits/stdc++.h>
#include "Queue_in_c.h"
using namespace std;
struct Node *root=NULL;

void Tcreate() // creating a binary tree
{
      struct Node *p,*t;
      int x;
      struct Queue q;
      create(&q,100);

      cout<<"Enter the root value: ";
      cin>>x;
      root=(struct Node*)malloc(sizeof(struct Node));
      root->data=x;
      root->lchild=root->rchild=NULL;
      enqueue(&q,root);

      while(!isEmpty(q))
      {
            p=dequeue(&q);
            cout<<"Enter the left child value of "<<p->data<<" :";
            cin>>x;
            if(x!=-1)
            {
                  t=(struct Node*)malloc(sizeof(struct Node));
                  t->data=x;
                  t->lchild=t->rchild=NULL;
                  p->lchild=t;
                  enqueue(&q,t);
            }
            cout<<"Enter the right child value of "<<p->data<<" :";
            cin>>x;
            if(x!=-1)
            {
                  t=(struct Node*)malloc(sizeof(struct Node));
                  t->data=x;
                  t->lchild=t->rchild=NULL;
                  p->rchild=t;
                  enqueue(&q,t);
            }
      }
}
void preorder(struct Node *p)
{
      if(p!=NULL)
      {
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
      }
}
void inorder(struct Node *p)
{
      if(p!=NULL)
      {
            
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
      }
}
void postorder(struct Node *p)
{
      if(p!=NULL)
      {
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
      }
}

void LevelOrder(struct Node *root)
{
      struct Queue q;
      create(&q,100);
      cout<<root->data<<" ";
      enqueue(&q,root);
      while(!isEmpty(q))
      {
            root=dequeue(&q);
            if(root->lchild)
            {
                  cout<<root->lchild->data<<" ";
                  enqueue(&q,root->lchild);
            }
            if(root->rchild)
            {
                  cout<<root->rchild->data<<" ";
                  enqueue(&q,root->rchild);
            }
      }
}

int Count(struct Node *p)
{
      if(p!=NULL)
      {
            return Count(p->lchild)+Count(p->rchild)+1;
      }
      return 0;
}

int Height(struct Node *p)
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
      Tcreate();
      cout<<"Preorder of the created Tree: ";
      preorder(root);
      cout<<endl;

      cout<<"Postorder of the created Tree: ";
      postorder(root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      inorder(root);
      cout<<endl;


      cout<<"Levelorder of the created Tree: ";
      LevelOrder(root);
      cout<<endl;


      cout<<"Number of Nodes in the Tree: "<<Count(root);
      cout<<endl;


      cout<<"Height of the Tree: "<<Height(root);
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