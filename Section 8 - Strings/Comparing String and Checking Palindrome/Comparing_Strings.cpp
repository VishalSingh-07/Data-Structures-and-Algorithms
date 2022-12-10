// Comparing two string whether it is equal, greater and smaller
// Stop the condition when (Mismatch found and end of the string(either))
#include <iostream>
using namespace std;
int main()
{
      char a[100];
      char b[100];
     
      cout << "Enter the string A : ";
      gets(a);
      cout << "Enter the string B: ";
      gets(b);

      int i, j;
      for (i = 0, j = 0; a[i] != '\0' || b[i] != '\0';i++,j++) // cheking condition if string ends
      {
            if(a[i]>=65 && a[i]<=90) // checking it its uppercase then converting to lowercase
            {
                  a[i] = a[i] + 32;
            }
            else if(b[i]>=65 && b[i]<=90) // cheking if its uppercase then converting to lowercase
            {
                  b[i] = b[i] + 32;
            }
            if(a[i]!=b[j]) // checking if they are not equal
            {
                  break;
            }
      }
      if(a[i]==b[j])
      {
            cout << "Both are equal";
      }
      else if (a[i]>b[j])
      {
            cout << "A is greater than B";
      }
      else
      {
            cout << "B is greater than A";
      }

      return 0;
}