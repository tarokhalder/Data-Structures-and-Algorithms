// Problem Link : https://codeforces.com/contest/339/problem/D
// My submission : https://codeforces.com/contest/339/submission/330015635
#include <bits/stdc++.h>

using namespace std;

class Segment_tree{
    public:
      int n , bit;
      vector <int> S;
      Segment_tree() {
         this->n = 0;
      }
      Segment_tree(int n) {
         this -> n = n;
	       S.resize(n * 4 , 0);
      }
      void build(int start , int end , int node , int s , vector <int> & a) {
           if (start == end) {
	      S[node] = a[start];
	      bit = s;
	      return;
	   }
	   int mid = (start + end) / 2;
	   build(start , mid , 2 * node + 1 , s ^ 1 , a);
	   build (mid + 1 , end , 2 * node + 2 , s ^ 1 , a);
	   if (bit == s) {
	      S[node] = S[2 * node + 1] ^ S[2 * node + 2];
	   } else {
	      S[node] = S[2 * node + 1] | S[2 * node + 2];
	   }
      }
      void build(vector <int> & a) {
          build(0 , n - 1 , 0 , 0 , a);
      }
      void update(int start , int end , int node , int s , int x , int r) {
           if (start == end) {
	       S[node] = r;
	       bit = s;
	       return;
	   }
	   int mid = (start + end) / 2;
	   if (x <= mid) {
	       update(start , mid , 2 * node + 1 ,s ^ 1 , x , r);
	   } else {
	      update(mid + 1 , end , 2 * node + 2 , s ^ 1 , x , r);
	   }
	   if (s == bit) {
	       S[node] = S[2 * node + 1] ^ S[2 * node + 2];

	   } else {
	       S[node] = S[2 * node + 1] | S[2 * node + 2];
	   }
      }
      void update(int x , int r) {
           update(0 , n - 1 , 0 , 0 , x , r);
      }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n , q;
    cin >> n >> q;
    n = pow(2 , n);
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    Segment_tree tree(n);
    tree.build(a);
    while (q--) {
        int x , r;
	cin >> x >> r;
	tree.update(x - 1 , r);
	cout << tree.S[0] << "\n";

    }
    return 0;
}
