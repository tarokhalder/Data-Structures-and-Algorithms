// Problem Link : https://cses.fi/problemset/task/1687/
// My Submission : https://cses.fi/problemset/result/16665844/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 , M = 20;

vector <int> G[N];

int Par[N][M];

void dfs(int x , int p) {
     Par[x][0] = p;
     for (int i = 1; i < M; i++) {
         Par[x][i] = Par[Par[x][i - 1]][i - 1];
     }
     for (auto c : G[x]) {
         if (c != p) {
	          dfs(c , x);
	       }
     }
}
int main() {
    int n , qq;
    cin >> n >> qq;
    for (int i = 2; i <= n; i++) {
        int x;
	      cin >> x;
	      G[x].push_back(i);
	      G[i].push_back(x);
    }
    dfs(1 , 0);
    while (qq--) {
        int x , y;
	      cin >> x >> y;
	      for (int i = 19; i >= 0; i--) {
	         if (y & (1 << i)) {
	             x = Par[x][i];
	          }
	       }
	      if (x == 0) {
	        x = -1;
	      }
	      cout << x << "\n";
    }
    return 0;
    
}
