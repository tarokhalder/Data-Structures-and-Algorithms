#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector <int> G[N];

int vis[N];

int v = 0 , dep = -1;

void dfs(int node , int p) {
     if (p > dep) {
         dep = p;
	        v = node;
     }
     vis[node] = 1;
     for (int x : G[node]) {
         if (vis[x] == 0) {
	          dfs(x , p + 1);
	       }
     }
}


int main() {
    int n , e;
    cin >> n >> e;
    while (e--) {
        int x , y;
	      cin >> x >> y;
	      G[x].push_back(y);
	      G[y].push_back(x);
    }
    dfs(1 , 0);
    memset(vis , 0 , sizeof(vis));
    dep = -1;
    dfs(v , 0);
    cout << dep << "\n";
    return 0;
}
