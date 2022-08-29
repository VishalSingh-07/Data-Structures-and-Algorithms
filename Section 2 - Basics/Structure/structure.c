#include <stdio.h>
struct rectangle
{
      int length;
      int breadth;
      char x;
};
int main()
{
      struct rectangle r1={10,5};

      printf("The size of struct is %ld",sizeof(r1));
      // printf("The size of struct is %lu",sizeof(r1));

      r1.length=15;
      r1.breadth=17;

      printf("\n length: %d",r1.length);
      printf("\n Breadth: %d",r1.breadth);


      return 0;
      
}