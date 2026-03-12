#include <bits/stdc++.h>

using namespace std;

int get(int n , int i) {
    return n & (1 << i) ? 1 : 0;
}

int main() {
    int n , i;
    cin >> n >> i;
    cout << get(n , i) << "\n";
    return 0;
}
