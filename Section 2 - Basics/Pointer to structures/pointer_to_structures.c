#include <stdio.h>
#include <stdlib.h>
struct rectangle
{
      int length;
      int breadth;
};

int main()
{
      // struct rectangle r={10,5};
      // printf("\n %d",r.length);
      // printf("\n %d",r.breadth);
      
      struct rectangle *p;
      p=(struct rectangle*)malloc(sizeof(struct rectangle));

      p->length=15;
      p->breadth=10;
      printf("\n %d",p->length);
      printf("\n %d",p->breadth);

}