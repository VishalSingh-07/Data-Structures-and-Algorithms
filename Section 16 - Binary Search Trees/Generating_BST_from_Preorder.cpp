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

void CreatePre(int pre[], int n)
{
     stack<Node*> st;
     Node *p,*t;
     int i=0; 
     root=new Node;
     root->data=pre[i++];
     root->lchild=root->rchild=NULL;
     p=root;

     while(i<n)
     {
            if(pre[i]<p->data)
            {
                  t=new Node;
                  t->data=pre[i++];
                  t->lchild=t->rchild=NULL;
                  p->lchild=t;
                  st.push(p);
                  p=t;
            }
            else if(pre[i]>p->data && st.empty()?1:(st.top()->data>pre[i]?1:0))
            {
                  t=new Node;
                  t->data=pre[i++];
                  t->lchild=t->rchild=NULL;
                  p->rchild=t;
                  p=t;
            }
            else
            {
                  p=st.top();
                  st.pop();
            }
     }
}

int main()
{
      int pre[]={30,20,10,15,25,40,50,45};
      int n=8;

      CreatePre(pre,n);


      cout<<"\nInorder Traversal: "<<endl;
      Inorder(root);

      return 0;
}

/*
Inorder Traversal: 
10 15 20 25 30 40 45 50 
*/