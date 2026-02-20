#include <bits/stdc++.h>

using namespace std;

class dsu{
    public:
      vector <int> Parent, Rank;
      dsu(int n) {
          Parent.resize(n + 1);
	      Rank.resize(n + 1 , 1);
	      iota(Parent.begin() , Parent.end() , 0);
      }
      int find(int x) {
          if (x == Parent[x]) {
	         return x;
	      }
	     return Parent[x] = find(Parent[x]);
      }
      void unite(int x , int y) {
           x = find(x);
	       y = find(y);
	      if (x != y) {
	         if (Rank[x] < Rank[y]) {
	           swap(x , y);
	         }
	         Parent[y] = x;
	         Rank[x] += Rank[y];
	      }
      }
};

int main() {
   
}
