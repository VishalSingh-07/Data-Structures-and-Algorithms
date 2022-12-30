// C++ Program for Lower Triangular Matrix 
#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
      int *A;
      int n;
};

// Row Major Mapping

void RSet(struct Matrix *m, int i, int j,int x) // Set for Row Major Mapping
{ 
      if(i>=j)
      {
            m->A[((i * (i - 1)) / 2) + (j - 1)] = x;
      }

}

int RGet(struct Matrix *m, int i, int j)// Set for Row Major Mapping
{
      if(i>=j)
      {
            return m->A[((i * (i - 1)) / 2) + (j - 1)];
      }
      else
      {
            return 0;
      }
}

void RDisplay(struct Matrix *m) // Display for row major Mapping
{
      for (int i = 1; i <=m->n;i++)
      {
            for (int j = 1; j <= m->n;j++)
            {
                  if(i>=j)
                  {
                        printf("%d ",  m->A[((i * (i - 1)) / 2) + (j - 1)]);
                  }
                  else
                  {
                        printf("0 ");
                  }
                 

            }
            printf("\n");
      }
}

// Column Major Mapping
void CSet(struct Matrix *m, int i, int j,int x) // Set for Column Major Mapping
{ 
      if(i>=j)
      {
            int t = (m->n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
            m-> A[t]= x;
      }

}

int CGet(struct Matrix *m, int i, int j)// Set for Column Major Mapping
{
      int t = (m->n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
      if(i>=j)
      {
            return m->A[t];
      }
      else
      {
            return 0;
      }
}

void CDisplay(struct Matrix *m) // Display for Column major Mapping
{
      
      for (int i = 1; i <=m->n;i++)
      {
            for (int j = 1; j <= m->n;j++)
            {
                  
                  if(i>=j)
                  {
                        int t = (m->n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
                        printf("%d ",  m->A[t]);
                  }
                  else
                  {
                        printf("0 ");
                  }
                 

            }
            printf("\n");
      }
}
int main()
{
      struct Matrix m;
      int i, j, x,choice;
      printf("Enter the value of n: ");
      scanf("%d",& m.n);
      // m.A = (int *)malloc(m.n*(m.n-1)/2*sizeof(int));// creating an array in heap
      m.A = (int *)malloc(((m.n*(m.n+1))/2)*sizeof(int));// creating an array in heap

      printf("Choose the Method: \n");
      printf("\nEnter 1: Row Major Mapping");
      printf("\nEnter 2: Column Major Mapping");
      printf("\nEnter 3: For Exit");
      printf("\nEnter your Choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
            case 1:
                  printf("Enter all elements of Lower Triangular Matrix: \n");
                  for (i = 1; i <= m.n;i++)
                  {
                        for (j = 1; j <= m.n;j++)
                        {
                              if(i>=j)
                              {
                                    printf("Enter the value of A[%d][%d]: ", i, j);
                                    scanf("%d", &x);
                                    RSet(&m, i, j, x);

                              }

                        }
                  }
                  printf("\nRequired Matrix: \n");
                  RDisplay(&m);
                  printf("\nGetting the value of A[2][2]: %d", RGet(&m, 2, 2));

                  break;
            
            case 2:
                  printf("Enter all elements of Lower Triangular Matrix: \n");
                  for (i = 1; i <= m.n;i++)
                  {
                        for (j = 1; j <= m.n;j++)
                        {
                              if(i>=j)
                              {
                                    printf("Enter the value of A[%d][%d]: ", i, j);
                                    scanf("%d", &x);
                                    CSet(&m, i, j, x);

                              }

                        }
                  }
                  printf("\nRequired Matrix: \n");
                  CDisplay(&m);
                  printf("\nGetting the value of A[2][2]: %d", CGet(&m, 2, 2));
                  break;
            
            case 3:
                  exit(0);
                  break;
      
            default:
                  printf("\nWrong Choice");
                  break;
      }
      return 0;
}