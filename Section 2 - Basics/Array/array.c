#include <stdio.h>
int main()
{
  // int a[5];
  // a[0]=1;
  // a[1]=2;

  // printf("Size of the array is %d",sizeof(a));
  int n,i;
  printf("Enter the value of n: ");
  scanf("%d",&n);
  int a[n];

  printf("\n Enter the element value of array:\n");
  // input the element array
  for(i=0;i<n;i++)
  {
    printf("Enter the value of element a[%d]: ",i);
    scanf("%d",&a[i]);
  }
  //display
  for(i=0;i<n;i++)
  {
    printf("\n The value of element a[%d]: %d",i,a[i]);
  }


  return 0;
}
