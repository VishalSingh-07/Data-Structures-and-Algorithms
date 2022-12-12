// Containers --> Priority Queue
// Largest Element stay at the top
// Element not store in linear fashion it actually store in a tree
#include <bits/stdc++.h>
using namespace std;
void explainPriorityQueque()
{
      // Maximum Heap priority queue
      priority_queue<int> pq;
      pq.push(5); //{5}
      pq.push(2); // {5,2}
      pq.push(8); // {8,5,2}
      pq.emplace(10); // {10,8,5,2}

      cout << pq.top(); // print 10

      // Minimum Heap priority queue
      priority_queue<int,vector<int>,greater<int>> pq;
      pq.push(5); //{5}
      pq.push(2); // {2,5}
      pq.push(8); // {2,5,8}
      pq.emplace(10); // {2,5,8,10}

      cout << pq.top(); // print 2

}
int main()
{
      explainPriorityQueque();
      return 0;
}

/*
time complexity
push --> logn
top ---> O(1)
pop --> logn
*/