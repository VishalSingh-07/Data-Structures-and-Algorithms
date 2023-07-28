#include <bits/stdc++.h>
using namespace std;
struct Node{
      struct Node *lchild;
      int data;
      int height;
      struct Node *rchild;
}*root=NULL;


int NodeHeight(struct Node *p)
{
      if(p==NULL)
      {
            return 0;
      }
      int hl,hr;
      hl=p && p->lchild?p->lchild->height:0;
      hr=p && p->rchild?p->rchild->height:0;

      return hl>hr?hl+1:hr+1;

}

int balanceFactor(struct Node *p)
{
      int hl,hr;
      hl=p && p->lchild?p->lchild->height:0;
      hr=p && p->rchild?p->rchild->height:0;

      return hl-hr;
}

struct Node* LLRotation(struct Node *p)
{
      struct Node *pl=p->lchild;
      struct Node *plr=pl->rchild;

      pl->rchild=p;
      p->lchild=plr;

      p->height=NodeHeight(p);
      pl->height=NodeHeight(pl);

      if(root==p)
      {
            root=pl;
      }
      return pl;
}

struct Node* RRRotation(struct Node *p)
{
      Node *pr=p->rchild;
      Node *prl=pr->lchild;

      p->rchild=prl;
      pr->lchild=p;

      p->height=NodeHeight(p);
      pr->height=NodeHeight(pr);

      if(p==root)
      {   
            root=pr;
      }
      return pr;
}
struct Node* LRRotation(struct Node *p)
{
      struct Node *pl=p->lchild;
      struct Node *plr=pl->rchild;  
      
      pl->rchild=plr->lchild;
      p->lchild=plr->rchild;

      plr->lchild=pl;
      plr->rchild=p;

      pl->height=NodeHeight(pl);
      p->height=NodeHeight(p);
      plr->height=NodeHeight(plr);

      if(root==p)
      {
            root=plr;
      }
      return plr;
}
struct Node* RLRotation(struct Node *p)
{
      Node *pr=p->rchild;
      Node *prl=pr->lchild;

      p->rchild=prl->lchild;
      pr->lchild=prl->rchild;
      prl->lchild=p;
      prl->rchild=pr;

      p->height=NodeHeight(p);
      pr->height=NodeHeight(pr);
      prl->height=NodeHeight(prl);

      if(p==root)
      {
            root=prl;
      }
      return prl;
}

struct Node * InPre(Node *p)
{
      while(p && p->rchild !=nullptr)
      {
            p=p->rchild;
      }
      return p;
}

struct Node * InSucc(Node *p)
{
      while(p && p->lchild !=nullptr)
      {
            p=p->lchild;
      }
      return p;
}

void Inorder(Node *p)
{
      if(p!=NULL)
      {
            Inorder(p->lchild);
            cout<<p->data<<" ";
            Inorder(p->rchild);
      }
}

struct Node* RInsert(struct Node *p,int key)
{
      struct Node *t=NULL;
      
      if(p==NULL)
      {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=key;
            t->height=1; // For leaf nodes (I am assuming height as 1 instead 0)
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

      p->height=NodeHeight(p);

      if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1) // LL - Rotation
      {
            return LLRotation(p);
      }

      else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1) // LR - Rotation
      {
            return LRRotation(p);
      }

      else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1) // RR - Rotation
      {
            return RRRotation(p);
      }
      
      else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1) // RL - Rotation
      {
            return RLRotation(p);
      }
      
      return p;
}


struct Node * DeleteNode(struct Node *p, int key)
{
      if(p==nullptr)
      {
            return nullptr;
      }
      if(p->lchild==nullptr && p->rchild==nullptr)
      {
            if(p==root)
            {
                  root=nullptr;
            }
            delete p;
            return nullptr;
      }
      if(key<p->data)
      {
            p->lchild=DeleteNode(p->lchild,key);
      }
      else if(key>p->data)
      {
            p->rchild=DeleteNode(p->rchild,key);
      }
      else{
            Node *q;
            if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
            {
                  q=InPre(p->lchild);
                  p->data=q->data;
                  p->lchild=DeleteNode(p->lchild,q->data);
            }
            else {
                  q=InSucc(p->rchild);
                  p->data=q->data;
                  p->rchild=DeleteNode(p->rchild,q->data);
            }
      }
      // Update height
      p->height = NodeHeight(p);
      
      // Balance Factor and Rotation
      if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)  // L1 Rotation
      {  
          return LLRotation(p);
      } 
      else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)  // L-1 Rotation
      { 
          return LRRotation(p);
      } 
      else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) // R-1 Rotation
      {  
          return RRRotation(p);
      } 
      else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) // R1 Rotation
      { 
            return RLRotation(p);
      } 
      else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0) // L0 Rotation
      {  
          return LLRotation(p);
      } 
      else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0) // R0 Rotation
      {  
          return RRRotation(p);
      }
      
      return p;

}


void Display(struct Node *p)
{
    cout<<p->data<<endl;
    if(p->lchild)
    {
        cout<<"left child of "<<p->data<<" is ";
        Display(p->lchild);
    }
        
    if(p->rchild)
    {
        cout<<"right child of "<<p->data<<" is ";
        Display(p->rchild);
    }
}

int main()
{
      int A[] = {10, 20, 30, 25, 28, 27, 5};
      for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        root = RInsert(root, A[i]);
      }

      Display(root);

      cout<<endl;
      cout<<endl;
      cout<<"Inorder Traversal: "<<endl;
      Inorder(root);
      cout<<endl;

      
      int del;
      cout<<endl;
      cout<<"Enter the value to be deleted from AVL Free: ";
      cin>>del;

      if(DeleteNode(root,del)==NULL)
      {
            cout<<del<<" is not deleted from the tree";
      }
      else
      {
            cout<<del<<" is deleted from the tree";
      }

      
      cout<<endl;
      Display(root);

      cout<<endl;
      cout<<endl;
      cout<<"Inorder Traversal: "<<endl;
      Inorder(root);
      cout<<endl;
      return 0;
}

/*
25
left child of 25 is 10
left child of 10 is 5
right child of 10 is 20
right child of 25 is 28
left child of 28 is 27
right child of 28 is 30


Inorder Traversal: 
5 10 20 25 27 28 30 

Enter the value to be deleted from AVL Free: 25
25 is deleted from the tree
27
left child of 27 is 10
left child of 10 is 5
right child of 10 is 20
right child of 27 is 28
right child of 28 is 30


Inorder Traversal:
5 10 20 27 28 30
*/