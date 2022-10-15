#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

      int *p, *q;
      p = (int *)malloc(5 * sizeof(int));
      p[0] = 3;
      p[1] = 5;
      p[2] = 7;
      p[3] = 9;
      p[4] = 11;
      int i;
      cout << "Array p: " << endl;
      for (i = 0; i < 5; i++)
      {
            cout << p[i]<<" ";
      }
      q = (int *)malloc(10 * sizeof(int));
      for (i = 0; i < 5;i++)
      {
            q[i] = p[i];
      }
      delete[] p;
      p = q;
      q = NULL;
     
      cout << "\nIncrease Array of p which is copied from array q: " << endl;
      for (i = 0; i < 5; i++)
      {
            cout << p[i]<<" ";
      }

      return 0;
}