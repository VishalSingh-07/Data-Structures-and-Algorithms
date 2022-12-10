// Finding a Duplicate in a String using Bitiwise Operator

/*

Merging -- Setting a bit on in a memory is called merging.

Masking -- Checking whether a bit is on or not is called masking.

*/

#include <iostream>
using namespace std;
int main()
{
      char str[100];
      cout << "Enter a String: ";
      gets(str);
      long int H = 0;// assigning all bits as zero
      int x = 0;
      for (int i = 0; str[i] != '\0';i++)
      {
            x = 1; // assigning 0 bit as 1 i.e turning is on
            x = x << (str[i] - 97); // turning on the bit for that particular char
            if((x & H)> 0)
            {
                  cout << "Duplicated Letter " << str[i] << endl;
            }
            else
            {
                  H = x | H; // Merging
            }
      }
           
      
      return 0;
}
/*
Output--
Enter a String: finding
Duplicated Letter i
Duplicated Letter n
*/