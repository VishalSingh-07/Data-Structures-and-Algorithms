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
            return pr;
      }
      return p;
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

      if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1) // LL -Rotation
      {
            return LLRotation(p);
      }

      else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1) // LR -Rotation
      {
            return LRRotation(p);
      }

      else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1) // RR -Rotation
      {
            return RRRotation(p);
      }
      
      else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1) // RL -Rotation
      {
            return RLRotation(p);
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
      // cout<<"LL Rotation:--"<<endl; 
      // root=RInsert(root,30);
      // RInsert(root,20);
      // RInsert(root,40);
      // RInsert(root,50);
      // RInsert(root,10);
      // RInsert(root,25);
      // RInsert(root,5);
      // RInsert(root,15);
      // RInsert(root,28);
      // RInsert(root,4);

      // Display(root);


      // cout<<"LR Rotation:--"<<endl; 
      // root=RInsert(root,40);
      // RInsert(root,20);
      // RInsert(root,50);
      // RInsert(root,10);
      // RInsert(root,30);
      // RInsert(root,25);
      // RInsert(root,35);
      // RInsert(root,5);
      // RInsert(root,60);
      // RInsert(root,27);

      // Display(root);


      // cout<<"RR Rotation:--"<<endl; 
      // root=RInsert(root,10);
      // RInsert(root,20);
      // RInsert(root,30);

      // Display(root);


      cout<<"RL Rotation:--"<<endl; 
      root=RInsert(root,10);
      RInsert(root,30);
      RInsert(root,20);

      Display(root);
      return 0;
}

/*
LL Rotation:--
20
left child of 20 is 10
left child of 10 is 5
left child of 5 is 4
right child of 10 is 15
right child of 20 is 30
left child of 30 is 25
right child of 25 is 28
right child of 30 is 40
right child of 40 is 50

LR Rotation:--
30
left child of 30 is 20
left child of 20 is 10
left child of 10 is 5
right child of 20 is 25
right child of 25 is 27
right child of 30 is 40
left child of 40 is 35
right child of 40 is 50
right child of 50 is 60


RR Rotation:--
20
left child of 20 is 10
right child of 20 is 30

RL Rotation:--
20
left child of 20 is 10
right child of 20 is 30

*/