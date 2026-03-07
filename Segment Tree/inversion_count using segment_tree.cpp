#include <bits/stdc++.h>

using namespace std;

class ST {
    public:
      int n;
      vector <int> S;
      ST(int n) {
         this-> n = n;
	 S.resize(4 * n , 0);
      }
      void update(int start , int end , int node , int x) {
           if (start == end) {
	       S[node] = 1;
	       return;
	   }
	   int mid = (start + end) /2;
	   if (x <= mid) {
	       update(start , mid , 2 * node + 1 , x);
	   } else {
	       update(mid + 1 , end ,  2 * node +  2 , x);
	   }
	   S[node] = S[2 * node + 1] + S[2 * node + 2];

      }
      int query(int start , int end , int node , int l , int r) {
          if (start > r || end < l) {
	     return 0;
	  }
	  if (start >= l && end <= r) {
	     return S[node];
	  }
	  int mid = (start + end) / 2;
	  int q1 = query(start , mid , 2 * node + 1 , l , r);
	  int q2 = query(mid + 1 , end , 2 * node + 2 , l , r);
	  return q1 + q2;
      }
      void update(int x) {
           update(0 , n , 0 ,  x);
      }
      int query(int l , int r) {
          return query(0 , n , 0 , l , r);
      }
};

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a){ 
        cin >> c;
    }
    vector <int> Ans(n);
    ST tree(n);
    for (int i = 0; i < n; i++) {
        Ans[i] = tree.query(a[i] + 1 , n);
	tree.update(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << Ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
