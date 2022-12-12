#include <iostream>
using namespace std;

// Pair is the part of the utility library
void explainPair()
{
      pair<int, int> p = {1, 3};
      cout << p.first << " " << p.second; // p.first --> 1 and p.second --> 3

      pair<int, pair<int, int>> a = {1, {3, 4}};

      cout << a.first << " " << a.second.second << " " << a.second.first;
      /*
      a.first --> 1
      a.second.second -->4
      a.second.first --> 3
      */

      pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

      cout << arr[1].second; // 5
}

int main()
{
      explainPair();
      return 0;
}
