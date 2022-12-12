// Containers -- Stack (Last in First Out (LIFO))
#include <bits/stdc++.h>
using namespace std;
void explainStack()
{
      stack<int> st;
      st.push(1); //{1}
      st.push(2); // {2, 1}
      st.push(3); // {3,2,1}
      st.push(3); // {3,3,2,1}
      st.emplace(5); // {5,3,3,2,1}

      cout << st.top(); // print 5 ** st[2] is invalid**

      st.pop(); // st look like {3,3,2,1}

      cout << st.top(); //3
      cout << st.size(); //4
      cout << st.empty(); // false

      stack<int> str1, str2;
      str1.swap(str2); // swap str1 and str2
}


int main()
{
      explainStack();
      return 0;
}