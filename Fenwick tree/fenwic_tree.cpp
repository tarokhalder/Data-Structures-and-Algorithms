#include <bits/stdc++.h>

using namespace std;

class fenwik {
    public:
       int n;
       vector <int> fn;
       fenwik(int n) {
          this->n = n + 1;
	        fn.resize(this->n , 0);
       }
       void add(int x , int y) {
            x++;
	         while (x < n) {
	           fn[x] += y;
		         x += (x & (-x));
	        }
       }
       int sum(int x) {
           x++;
	         int sum = 0;
	         while (x) {
	           sum += fn[x];
	           x -= (x & (-x));
	         }
	         return sum;
       }
       int sum(int l , int r) {
           return sum(r) - sum(l - 1);
       }
};

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    fenwik tree(n);
    for (int i = 0; i < n; i++) {
        tree.add(i , a[i]);
    }
    int qq;
    cin >> qq;
    while (qq--) {
        int l , r;
	      cin >> l >> r;
	      cout << tree.sum(l , r) << "\n";
    }
    return 0;
}
