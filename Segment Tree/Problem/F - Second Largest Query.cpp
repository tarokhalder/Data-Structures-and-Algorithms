// Problem Link : https://atcoder.jp/contests/abc343/tasks/abc343_f
// My Submission : https://atcoder.jp/contests/abc343/submissions/75002478
#include <bits/stdc++.h>

using namespace std; 

struct Node {	
      int L  , R , Lc  , Rc;
     
};

class ST {
    public:
      vector <Node> S;
      int n;
      ST(int n) {
         this-> n = n;
	 S.resize(4 * n , {0 , 0 , 0 , 0});
      }
      Node merge(Node a , Node b) {
           unordered_map <int , int> M;
	   M[a.L] += a.Lc;
	   M[a.R] += a.Rc;
	   M[b.L] += b.Lc;
	   M[b.R] += b.Rc;
	   vector <pair <int , int>> A;
	   for (auto & [x , y] : M) {
	       A.push_back({x , y});
	   }
	   sort(A.rbegin() , A.rend());
	   Node m;
	   m.L = A[0].first , m.Lc = A[0].second;
	   if (A.size() > 1) {
	      m.R = A[1].first , m.Rc = A[1].second;
	   } else {
	      m.R = 0;
	      m.Rc = 0;
	   }

	   return m;
	   
      }
      void build(int start , int end , int node , vector <int> & a) {
           if (start == end) {
	       S[node] = {a[start] , 0 , 1 , 0};
	       return;
	   }
	   int mid = (start + end) / 2;
	   build(start , mid , 2 * node + 1 , a);
	   build(mid + 1 , end , 2 * node + 2 , a);
	   S[node] = merge(S[2 * node + 1] , S[2 * node + 2]);
      }
      void update(int start , int end , int node , int l , int r) {
           if (start == end) {
	      S[node] = {r , 0 , 1 , 0};
	      return;
	   }
	   int mid = (start + end) / 2;
	   if (l <= mid) {
	       update(start , mid , 2 * node + 1 , l , r);
	   } else {
	       update(mid + 1 , end , 2 * node + 2 , l , r);
	   }
	   S[node] = merge(S[2 * node + 1] , S[2 * node + 2]);
      }
      Node query(int start , int end , int node , int l , int r) {
           if (start > r || end < l) {
               return {0 , 0 , 0 , 0};
	   }
	   if (start >= l && end <= r) {
	      return S[node];
	   }
	   int mid = (start + end) / 2;
	   Node q1 = query(start , mid , 2 * node + 1 , l , r);
	   Node q2 = query(mid + 1 , end , 2 * node + 2 , l , r);
	   return merge(q1 , q2);
      }
      void build(vector <int> & a) {
           build(0 , n - 1 , 0 , a);
      }
      void update(int l , int r) {
           update(0 , n - 1 , 0 , l - 1 , r);
      }
      int query(int l , int r) {
          Node a = query(0 , n - 1 , 0 , l - 1 , r - 1);
	  return a.Rc;
      }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , q;
    cin >> n >> q;
    vector <int> a(n);
    for (auto & c : a) {
         cin >> c;
    }
    ST tree(n);
    tree.build(a);
    while (q--) {
       int x , l , r;
       cin >> x >> l >> r;
       if (x == 1) {
	  tree.update(l , r);
       } else {

          cout << tree.query(l , r) << "\n";
       }
    }
    return 0;
}
