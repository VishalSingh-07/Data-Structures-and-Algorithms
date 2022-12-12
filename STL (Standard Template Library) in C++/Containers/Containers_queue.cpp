// Containers --> Queueu (FIFO --> First in first out)
#include <bits/stdc++.h>
using namespace std;
void explainQueque()
{
      queue<int> q;
      q.push(1); //{1}
      q.push(2); // {1,2}
      q.push(4); //{1,2,4}

      q.back() += 5; // add 5 in the last element (4+5=9)

      cout << q.back(); // print 9

      // Q is {1,2,9}
      cout << q.front(); //print 1

      q.pop(); // {2,9}

      cout << q.front(); // print 2

      // size, swap, empty same as stack
}
int main()
{
      explainQueque();
      return 0;
}