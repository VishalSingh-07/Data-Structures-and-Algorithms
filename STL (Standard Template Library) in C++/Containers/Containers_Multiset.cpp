// Containers--> Sets
#include <bits/stdc++.h>
using namespace std;

// MultiSet --> Stored in sorted order and not unique
void explainMultiSet()
{
      // Everything is same as set only stores duplicate element also
      multiset<int> ms;
      ms.insert(1); // {1}
      ms.insert(1); //{1,1}
      ms.insert(1); //{1,1,1}

      ms.erase(1); // all 1's erased

      // {1,1,1,2,3}
      int cnt = ms.count(1); // return 3

      // only a single one erased
      ms.erase(ms.find(1));

      ms.erase(ms.find(1), ms.find(2));

      // rest all function same as set
}
int main()
{
      explainMultiSet();
      return 0;
}
