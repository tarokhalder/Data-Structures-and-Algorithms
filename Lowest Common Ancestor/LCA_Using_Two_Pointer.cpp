#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 1;
 
vector <int> G[N];
 
int dep[N] , Par[N];
 
 
void dfs(int node , int par) {
     Par[node] = par;
     dep[node] = dep[par] + 1;
     for (int x : G[node]) {
         if (x != par) {
	    dfs(x , node);
	 }
     }
}
 
int LCA(int u , int v) {
    if (u == v) {
        return u;
    }
    if (dep[u] < dep[v]) {
        swap(u , v);
    }
    int dif = dep[u] - dep[v];
    while (dif--) {
        u = Par[u];
    }
    while (u != v) {
        u = Par[u];
	v = Par[v];
    }
    return u;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x , y ;
	cin >> x >> y;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(1 , 0);
    int qq;
    cin >> qq;
    while (qq--) {
        int x , y;
	cin >> x >> y;
	cout << LCA(x , y) << "\n";
    }
    return 0;

}
