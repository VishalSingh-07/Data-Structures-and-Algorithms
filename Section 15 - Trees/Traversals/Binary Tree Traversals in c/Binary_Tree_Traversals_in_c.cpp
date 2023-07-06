#include <bits/stdc++.h>
#include "Queue_in_c.h"
#include "Stack_in_C.h"
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


// Recursive Approach

void RPreorder(struct Node *p)
{
      if(p!=NULL)
      {
            cout<<p->data<<" ";
            RPreorder(p->lchild);
            RPreorder(p->rchild);
      }
}
void RInorder(struct Node *p)
{
      if(p!=NULL)
      {
            
           RInorder(p->lchild);
            cout<<p->data<<" ";
            RInorder(p->rchild);
      }
}
void RPostorder(struct Node *p)
{
      if(p!=NULL)
      {
            RPostorder(p->lchild);
            RPostorder(p->rchild);
            cout<<p->data<<" ";
      }
}


// Iterative Approach

void IPreorder(struct Node *p)
{
      struct Stack stk;
      stackCreate(&stk,100);

      while(p!=NULL || !isEmptyStack(stk))
      {
            if(p!=NULL)
            {
                  cout<<p->data<<" ";
                  push(&stk,p);
                  p=p->lchild;
            }
            else
            {
                  p=pop(&stk);
                  p=p->rchild;
            }
      }
}
void IInorder(struct Node *p)
{
      struct Stack stk;
      stackCreate(&stk,100);

      while(p!=NULL || !isEmptyStack(stk))
      {
            if(p!=NULL)
            {
                  push(&stk,p);
                  p=p->lchild;
            }
            else
            {
                  p=pop(&stk);
                  cout<<p->data<<" ";
                  p=p->rchild;
            }
      }
}

void IPostorder(struct Node *p)
{
      struct Stack stk1, stk2;
      stackCreate(&stk1, 100);
      stackCreate(&stk2, 100);

      push(&stk1, p); // Push the root node onto stk1

      while (!isEmptyStack(stk1))
      {
            p = pop(&stk1);
            push(&stk2, p); // Push the popped node onto stk2

            if (p->lchild)
                  push(&stk1, p->lchild); // Push the left child onto stk1

            if (p->rchild)
                  push(&stk1, p->rchild); // Push the right child onto stk1
      }

      // Print nodes in stk2 to get the postorder traversal
      while (!isEmptyStack(stk2))
      {
            p = pop(&stk2);
            cout << p->data << " ";
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

int main()
{
      Tcreate();

      cout<<"\n--------Recursive Approach -----"<<endl;
      cout<<"Preorder of the created Tree: ";
      RPreorder(root);
      cout<<endl;

      cout<<"Postorder of the created Tree: ";
      RPostorder(root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      RInorder(root);
      cout<<endl;



      cout<<"\n--------Iterative Approach -----"<<endl;
      cout<<"Preorder of the created Tree: ";
      IPreorder(root);
      cout<<endl;


      cout<<"Postorder of the created Tree: ";
      IPostorder(root);
      cout<<endl;

      cout<<"Inorder of the created Tree: ";
      IInorder(root);
      cout<<endl;

      cout<<"Levelorder of the created Tree: ";
      LevelOrder(root);
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