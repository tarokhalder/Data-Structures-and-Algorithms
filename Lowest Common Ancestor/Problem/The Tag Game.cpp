//Problem Link : https://codeforces.com/contest/813/problem/C
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int N = 2e5 + 1 , M = 20;

vector <int> G[N];

int par[N][M];

int dep[N] , edge[N];

void dfs(int x , int p) {
     dep[x] = dep[p] + 1;
     par[x][0] = p;
     for (int i = 1; i < M; i++) {
        par[x][i] = par[par[x][i - 1]][i - 1];
     }
     for (int c : G[x]) {
         if (c != p) {
	   dfs(c , x);
	 }
     }
}


int LCA(int x , int y) {
    if (dep[x] < dep[y]) {
        swap(x , y);
    }
    int diff = dep[x] - dep[y]; 
    for (int i = M - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
	   x = par[x][i];
	}
    }
    if (x == y) {
       return x;
    }
    for (int i = M - 1; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
	    x = par[x][i];
	    y = par[y][i];
	}
    }
    return par[x][0];
}

int path(int x , int y) {
    int lca = LCA(x , y);
    return dep[x] + dep[y] - 2 * dep[lca];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    dep[0] = -1;   
    int n , k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
         int x , y;
	 cin >> x >> y;
	 G[x].push_back(y);
	 G[y].push_back(x);
	 edge[x]++ , edge[y]++;
    }
    dfs(1 , 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (edge[i] == 1) {
	   if (dep[i]  > path(i , k)) {
	      ans = max(ans , dep[i] * 2);
	   }
	}
    }
    cout << ans << "\n";
    return 0;
}
