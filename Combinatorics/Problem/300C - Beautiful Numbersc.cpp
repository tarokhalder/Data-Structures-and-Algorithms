// Problem Link : https://codeforces.com/contest/300/problem/C
// My Submission : https://codeforces.com/contest/300/submission/368334274
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int Mod = 1e9 + 7;

const int N = 1e6 + 2;


int add(int x , int y){return (x % Mod + y % Mod)% Mod;}
int mul(int x , int y){return ((x % Mod) * (y % Mod)) % Mod;}

int power(int x , int y) {
    int res = 1;
    while (y) {
        if (y & 1) {
	   res = mul(res , x);
	}
	y /= 2;
	x = mul(x , x);
    }
    return res;
}

int divm(int x , int y) {
    return mul(x , power(y , Mod - 2));
}

bool find(int sum , int a , int b) {
     while (sum > 0) {
         if (sum % 10 != a && sum % 10 != b) {
	     return false;
	 }
	 sum /= 10;
     }
     return true;
}

int fact[N];

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);    
    fact[0] = 1;
    for (int i = 1; i < N; i++){ 
        fact[i] = mul(fact[i - 1] , i);
    }
    int a , b , n;
    cin >> a >> b >> n;
    int Ans = 0;
    for (int i = 0; i <= n; i++) {
        int sum = i * a + (n - i) * b;
	     if (find(sum , a , b)) {
	        if (i == 0 || n - i == 0) {
	           Ans = add(Ans , 1);
	        } else {
	           int L = mul(fact[i] , fact[n - i]);
	           Ans = add(Ans , divm(fact[n] , L));
	        }
	  } 

    }
    cout << Ans << "\n";
    return 0;

}
