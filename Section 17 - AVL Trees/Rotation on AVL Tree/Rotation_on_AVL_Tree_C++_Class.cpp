#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

 
class AVL
{
      public:
            Node* root;
            AVL()
            { 
                  root = nullptr; 
            }
 
            // Helper methods for inserting/deleting
            int NodeHeight(Node* p);
            int balanceFactor(Node* p);
            Node* LLRotation(Node* p);
            Node* RRRotation(Node* p);
            Node* LRRotation(Node* p);
            Node* RLRotation(Node* p);
 
            // Insert
            Node* RInsert(Node* p, int key);
            void Display(Node *p);
};

int AVL :: NodeHeight(Node *p)
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

int AVL :: balanceFactor(Node *p)
{
      int hl,hr;
      hl=p && p->lchild?p->lchild->height:0;
      hr=p && p->rchild?p->rchild->height:0;

      return hl-hr;
}

Node* AVL :: LLRotation(Node *p)
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

Node* AVL :: RRRotation(Node *p)
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
Node* AVL :: LRRotation(Node *p)
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
Node* AVL :: RLRotation(Node *p)
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

Node* AVL :: RInsert(Node *p,int key)
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

void AVL :: Display(Node *p)
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
      AVL tree1,tree2,tree3,tree4;
      cout<<"Tree 1 : "<<endl;
      cout<<"LL Rotation:--"<<endl; 
      tree1.root=tree1.RInsert(tree1.root,30);
      tree1.RInsert(tree1.root,20);
      tree1.RInsert(tree1.root,40);
      tree1.RInsert(tree1.root,50);
      tree1.RInsert(tree1.root,10);
      tree1.RInsert(tree1.root,25);
      tree1.RInsert(tree1.root,5);
      tree1.RInsert(tree1.root,15);
      tree1.RInsert(tree1.root,28);
      tree1.RInsert(tree1.root,4);

      tree1.Display(tree1.root);

      cout<<endl;
      cout<<endl;

      cout<<"Tree 2 : "<<endl;
      cout<<"LR Rotation:--"<<endl; 
      tree2.root=tree2.RInsert(tree2.root,40);
      tree2.RInsert(tree2.root,20);
      tree2.RInsert(tree2.root,50);
      tree2.RInsert(tree2.root,10);
      tree2.RInsert(tree2.root,30);
      tree2.RInsert(tree2.root,25);
      tree2.RInsert(tree2.root,35);
      tree2.RInsert(tree2.root,5);
      tree2.RInsert(tree2.root,60);
      tree2.RInsert(tree2.root,27);

      tree2.Display(tree2.root);


      cout<<endl;
      cout<<endl;

      cout<<"Tree 3 : "<<endl;
      cout<<"RR Rotation:--"<<endl; 
      tree3.root=tree3.RInsert(tree3.root,10);
      tree3.RInsert(tree3.root,20);
      tree3.RInsert(tree3.root,30);

      tree3.Display(tree3.root);

      cout<<endl;
      cout<<endl;

      cout<<"Tree 4: "<<endl;
      cout<<"RL Rotation:--"<<endl; 
      tree4.root=tree4.RInsert(tree4.root,10);
      tree4.RInsert(tree4.root,30);
      tree4.RInsert(tree4.root,20);

      tree4.Display(tree4.root);
      return 0;
}

/*
Tree 1 : 
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


Tree 2 : 
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


Tree 3 :
RR Rotation:--
20
left child of 20 is 10
right child of 20 is 30


Tree 4:
RL Rotation:--
20
left child of 20 is 10
right child of 20 is 30
*/