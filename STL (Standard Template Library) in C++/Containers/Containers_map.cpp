// Containers--> Maps
#include <bits/stdc++.h>
using namespace std;

// Map --> respect of key and value {key, value} { key --> ds, int, double, pair}
void explainMap()
{
      map < int, int > mpp;

      map<int, pair<int, int>> mpp;

      map<pair<int, int>, int> mpp;

      mpp[1] = 2; //  Store 2 on key 1 --> {{1,2}}

      // {
      //       {1,2}
      //       {2,4}
      //       {3,1}
      // }

      for (auto it: mpp)
      {
            cout << it.first << " " << it.second << endl;
      }

      cout << mpp[1];
      cout << mpp[5];

      // auto it = mpp.find(3);
      // cout << *(it).second;

      auto it = mpp.find(5); // return mpp.end()

      // This is the syntax
      auto it = mpp.lower_bound(2);
      auto it = mpp.upper_bound(3);

      // erase, swap, size, empty, are same as above
      
}
int main()
{
      explainMap();
      return 0;
}
