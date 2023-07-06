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
            int LeafNodesCount(Node *p);
            int Deg0Count(Node *p);
            int Deg1Count(Node *p);
            int Deg2Count(Node *p);
            int Deg_1_and_2_Count(Node *p);
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
int Tree :: Count(Node *p)  // Counting the number of nodes in the tree
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Count(p->lchild);
            y=Count(p->rchild);

            return x+y+1;
      }
      return 0;
}


int Tree :: LeafNodesCount(Node *p) // Counting the leaf node present in the tree
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=LeafNodesCount(p->lchild);
            y=LeafNodesCount(p->rchild);

            if(!p->lchild && !p->rchild)
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



int Tree :: Deg0Count(Node *p) // Counting the nodes with degree zero
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Deg0Count(p->lchild);
            y=Deg0Count(p->rchild);

            if(p->lchild == NULL && p->rchild==NULL)
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

int Tree :: Deg1Count(Node *p) // Counting the nodes with degree one
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Deg1Count(p->lchild);
            y=Deg1Count(p->rchild);



            // if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL) )
            // {
            //       return x+y+1;
            // }

            // Or 


            if(p->lchild !=NULL ^ p->rchild!=NULL)
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

int Tree :: Deg_1_and_2_Count(Node *p) // number of nodes with degree 1 and degree 2 
{
      int x=0,y=0;
      if(p!=NULL)
      {
            x=Deg_1_and_2_Count(p->lchild);
            y=Deg_1_and_2_Count(p->rchild);

            if(p->lchild !=NULL || p->rchild!=NULL)
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


int main()
{
      Tree t;
      t.createTree();

      cout<<"Number of Nodes in the Tree: "<<t.Count(t.root);
      cout<<endl;


      cout<<"Number of Leaf Nodes in the Tree: "<<t.LeafNodesCount(t.root);
      cout<<endl;

      cout<<"Number of Nodes (whose Degree is 0) in the Tree: "<<t.Deg0Count(t.root);
      cout<<endl;

      cout<<"Number of Nodes (whose Degree is 1) in the Tree: "<<t.Deg1Count(t.root);
      cout<<endl;

      cout<<"Number of Nodes (whose Degree is 2) in the Tree: "<<t.Deg2Count(t.root);
      cout<<endl;

      cout<<"Number of Nodes (whose Degree is 1 and 2) in the Tree: "<<t.Deg_1_and_2_Count(t.root);
      cout<<endl;


      return 0;
}

/*
Output:
Enter the root value: 8
Enter the left child value of 8 :3
Enter the right child value of 8 :5
Enter the left child value of 3 :12
Enter the right child value of 3 :-1 
Enter the left child value of 5 :10
Enter the right child value of 5 :6
Enter the left child value of 12 :-1
Enter the right child value of 12 :4
Enter the left child value of 10 :-1
Enter the right child value of 10 :-1
Enter the left child value of 6 :2
Enter the right child value of 6 :-1
Enter the left child value of 4 :9
Enter the right child value of 4 :7
Enter the left child value of 2 :-1
Enter the right child value of 2 :-1
Enter the left child value of 9 :-1
Enter the right child value of 9 :-1
Enter the left child value of 7 :-1
Enter the right child value of 7 :-1
Number of Nodes in the Tree: 10
Number of Leaf Nodes in the Tree: 4
Number of Nodes (whose Degree is 0) in the Tree: 4
Number of Nodes (whose Degree is 1) in the Tree: 3
Number of Nodes (whose Degree is 2) in the Tree: 3
Number of Nodes (whose Degree is 1 and 2) in the Tree: 6
*/