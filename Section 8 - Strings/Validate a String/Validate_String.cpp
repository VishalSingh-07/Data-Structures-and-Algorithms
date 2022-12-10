// Checking whether a string is valid or not
/*
Given a string str, the task is to check if the string is a valid identifier or not. In order to qualify as a valid identifier, the string must satisfy the following conditions:  

1. It must start with an either underscore(_) or any of the characters from the ranges [‘a’, ‘z’] and [‘A’, ‘Z’].
2. There must not be any white space in the string.
3. And, all the subsequent characters after the first character must not consist of any special characters like $, #, % etc.
*/
#include <iostream>
using namespace std;
int valid(char *str)
{
      int i;
      for (i = 0; str[i] != '\0';i++)
      {
            if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) && !(str[i]>=48 && str[i]<=57) && !str[i]=='_')
            {
                  return 0;
            }
      }
      return 1;
}
int main()
{
      char str[100];
      cout << "Enter the string: ";
      cin.get(str, 100);

      if(valid(str)==1)
      {
            cout << str << " is valid string" << endl;
      }
      else
      {
            cout << str << " is invalid string" << endl;
      }

      return 0;
}
/*
Enter the string: data_structures_and_algorithms
data_structures_and_algorithms is valid string
*/