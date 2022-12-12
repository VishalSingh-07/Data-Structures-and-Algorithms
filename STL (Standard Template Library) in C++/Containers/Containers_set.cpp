// Containers--> Sets
#include <bits/stdc++.h>
using namespace std;

// Set --> Stored in sorted order and unique
void explainSet()
{
      set<int> st;
      st.insert(1); // {1}
      st.emplace(2); //{1,2}
      st.insert(2); // {1,2}
      st.insert(4); //{1,2,4}
      st.insert(3); // {1,2,3,4}

      /*
      functionality of insert in vector can be used also, 
      that only increases efficiency
      */
      //begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above
      
      // {1,2,3,4,5}
      auto it = st.find(3); // point to the iterator

      // {1,2,3,4,5}
      auto it = st.find(6); // return st.end()

      // {1,4,5};
      st.erase(5); // erases 5 (takes logarithmic time)

      int cnt = st.count(1); // It always 1 if the 1 is present otherwise 0

      auto it = st.find(3);
      st.erase(it); // Erase 3 fromt the array, it takes constant time 

      // {1,2,3,4,5}
      auto it1 = st.find(2);
      auto it2 = st.find(4);
      st.erase(it1, it2); // after erase {1,4,5} using erase{first, last}

      // lower_bound() and upper_bound() function works in the same way

      // This is the syntax

      auto it = st.lower_bound(2);
      auto it = st.upper_bound(3);
}
int main()
{
      explainSet();
      return 0;
}

/*
Time complexity -- Logn
*/