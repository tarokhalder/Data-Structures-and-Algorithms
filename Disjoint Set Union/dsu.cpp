#include <bits/stdc++.h>

using namespace std;

class dsu{
    public:
      vector <int> Parent;
      dsu(int n) {
          Parent.resize(n + 1);
	  iota(Parent.begin() , Parent.end() , 0);
      }
      int find(int x) {
          if (x == Parent[x]) {
	     return x;
	  }
	  return find(Parent[x]);
      }
      void unite(int x , int y) {
           x = find(x);
	   y = find(y);
	   if (x != y) {
	      Parent[y] = x;
	   }
      }
};

int main() {
   
}
