// Vector --
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void explainVector()
{
      vector<int> v;
      v.push_back(1);
      v.emplace_back(2);

      // emplace_back is faster than push_back

      vector<pair<int, int>> vec;
      vec.push_back({1, 2});
      vec.emplace_back(1, 2);

      vector<int> ve(5, 100);

      vector<int> vic(5);

      vector<int> v1(5, 20);
      
      vector<int> v2(v1); // Another container which is copy the vector v1

      vector<int>::iterator it = v1.begin();
      it++;
      cout << *(it) << " ";
      
      it = it + 2;
      cout << *(it) << " ";

      vector<int>::iterator it = v1.end();

      // Never use this 
      // vector<int> :: iterator it = v1.rend();

      // vector<int>::iterator it = v1.rbegin();

      cout << v[0] << " " << v.at(0);

      cout << v.back() << " ";

      for (vector<int>::iterator it = v.begin(); it != v.end();it++)
      {
            cout << *(it) << " ";
      }

      for (auto it = v.begin(); it != v.end();it++)
      {
            cout <<  *(it) << " ";
      }

      for (auto it: v)
      {
            cout << it << " ";
      }

      // {10,20,12,23}
      v.erase(v.begin() + 1);

      // {10,20,30,40,50}
      v.erase(v.begin() + 2, v.begin() + 4); // {10,20,50}

      // Insert Function --
      vector<int> vv(2, 100); //{100,100};
      vv.insert(vv.begin(), 300); // {300,100,100}
      vv.insert(vv.begin() + 1, 2, 10); // {300,10,10,100,100} where 2 is number of element

      vector<int> copy(2, 50); // {50,50};
      vv.insert(vv.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

      //v-->{10,20}
      cout << v.size(); // 2

      // v--> {10,20}
      v.pop_back(); // {10} it pop the last element in the vector

      // v1 --> {10,20}
      // v2 --> {30,40}
      v1.swap(v2); // v1--> {30,40} , v2--> {10,20}

      v1.clear(); // erases the entire vector

      cout << v.empty(); // Give true when vector is empty otherwise false
}
int main()
{
      explainVector();
      return 0;
}
