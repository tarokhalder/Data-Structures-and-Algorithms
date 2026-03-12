#include <bits/stdc++.h>

using namespace std;

int set_ith_bit(int  n , int i) {
    int mask = (1 << i);
    n |= mask;
    return n;
}

int main() {
    int n , i;
    cin >> n >> i;
    cout << set_ith_bit(n , i) << "\n";
    return 0;
}
