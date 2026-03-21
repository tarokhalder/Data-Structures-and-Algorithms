#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int Mod = 1e9 + 7;

int gethash(string a) {
    int ans = 0;
    int prime = 3;
    int power = 1;
    for (int i = 0; i < int(a.size()); i++) {
         ans = (ans + (a[i] * power)) % Mod;
	 power = (power * prime) % Mod;
    }
    return ans % Mod;
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string a;
	cin >> a;
	cout << gethash(a) << "\n";
    }
    return 0;
}
