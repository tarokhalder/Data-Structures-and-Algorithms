#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int Mod = 1e9 + 7;

const int sz = 2;

struct Mat {
    int m[sz][sz];
    Mat() {
       memset(m , 0 , sizeof(m));
    }
    void identity ( ){
        for (int i = 0; i < sz; i++) {
	           m[i][i] = 1;
	      }
    }
    Mat operator *(Mat a) {
        Mat res;
	      for (int i = 0; i < sz; i++) {
	         for (int j = 0; j < sz; j++) {
	             for (int k = 0; k < sz; k++) {
		               res.m[i][j] += m[i][k] * a.m[k][j];
		               res.m[i][j] %= Mod;
		           }
	         }
	      }
	      return res;
    }
};

int fib(int n) {
    Mat res , T;
    res.identity();
    T.m[0][0] = 1 , T.m[0][1] = 1 , T.m[1][0] = 1;
    if (n <= 2) {
       return 1;
    }
    n -= 2;
    while (n > 0) {
        if (n & 1) {
	         res = res * T;
	     }
	     n /= 2;
	     T = T * T;
    }
    return (res.m[0][0] + res.m[0][1]) % Mod;
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
	      cin >> n;
	      cout << fib(n) << "\n";
    }
    return 0;

}
