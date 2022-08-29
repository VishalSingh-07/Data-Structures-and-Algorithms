#include <stdio.h>
#include <stdlib.h>
struct rectangle
{
      int length;
      int breadth;

};
int main()
{
      int a=10;
      int *p;
      p=&a;

      printf("The value of a is : %d\n",a);

      printf("using pointer %d",*p);

      int b[5] = {2,4,6,8,10};
      int *c;
      c=b;

      for(int i=0;i<5;i++)
      {
            printf("%d ",c[i]);
      }
      
      // *p :- Printing the value of a
      // p :- Printing the address of a
      // &p:- printing the address of a
      // &a:- Printing the address of a 


      int *d;
      d=(int *)malloc(5*sizeof(int));

      d[0]=1,d[1]=2,d[2]=3,d[3]=4,d[4]=5;
      for(int i=0;i<5;i++)
      {
            printf("%d ",d[i]);
      }


      // free(p);  // free() is used c language, delete[ ] p;  is used for c++ language 

      int *p1;
      char *p2;
      float *p3;
      double *p4;
      struct rectangle *p5;


      printf("%d\n",sizeof(p1));
      printf("%d\n",sizeof(p2));
      printf("%d\n",sizeof(p3));
      printf("%d\n",sizeof(p4));
      printf("%d\n",sizeof(p5));


      // whatever the data-types of pointer is pointer take same amount of memory  


     



      return 0;

}