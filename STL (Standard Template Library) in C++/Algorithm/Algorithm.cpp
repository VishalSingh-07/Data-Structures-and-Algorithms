#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
      if(p1.second <p2.second)
      {
            return true;
      }
      if(p1.second>p2.second)
      {
            return false;
      }

       // they are same

      if(p1.first>p2.first)
      {
            return true;
      }
      return false;
}
void explainExtra()
{
      int n;
      int a[n];
      vector<int> v;
      sort(a, a + n);
      sort(v.begin(), v.end());

      sort(a + 2, a + 4);

      // sort(a, a + n, greater <int> ); // sorted in descending order

      pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

      // Sort it according to second element
      // if second element is same, then sort 
      // it according to first element but in descending

      // (My way)
      sort(a, a + n, comp); // comp --> self written comparator


      // {{4,1}, {2,1, {1,2}}

      int num = 7;
      int cnt = __builtin_popcount(num);   // 3


      long long num = 165786578687;
      int cnt = __builtin_popcountll(num);

      string s = "123";
      sort(s.begin(), s.end());
      do
      {
            /* code */
            cout << s << endl;
      } while (next_permutation(s.begin(),s.end()));

      // {1,10,5,6}
      int maxi = *max_element(a, a + n);// return 10
}
int main()
{
      explainExtra();
      return 0;
}