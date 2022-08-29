#include <stdio.h>
void fun(int a[],int n)
{

      printf("%d ",sizeof(a)/sizeof(int));
       for(int i=0;i<n;i++)
      {
            printf("%d ",a[i]);
      }

}
int main()
{
      int a[]={2,4,6,8,10};
      int n=5;
      fun(a,n);

     

      return 0;
}