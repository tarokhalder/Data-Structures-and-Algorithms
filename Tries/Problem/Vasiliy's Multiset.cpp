// Problem Link : https://codeforces.com/contest/706/problem/D
// My solution : https://codeforces.com/contest/706/submission/360739862
#include <bits/stdc++.h>

using namespace std;

class Trie {
   public:
      int L , R;
      Trie * children[2];
      Trie() {
         L = R = 0;
	       for (int i = 0; i < 2; i++) {
	         children[i] = nullptr;
	       }
      }
};

void insert(Trie * root , int x) {
     Trie * cur = root;
     for (int i = 30; i >= 0; i--) {
         int d = x & (1 << i);
	 d = min(1 , d);
	 if (d == 0) {
	    cur->L++;
	 } else {
	    cur->R++;
	 }
	 if (cur->children[d] == nullptr) {
	    Trie * newNode = new Trie();
	    cur->children[d] = newNode;
	 }
	 cur = cur->children[d];
     }
}
void remove(Trie * root , int x) {
     Trie * cur = root;
     for (int i = 30; i >= 0; i--) {
         int d = x & (1 << i);
	 d = min(1 , d);
	 if (d == 0) {
	    cur->L--;
	 } else {
	    cur->R--;
	 }
	 cur = cur->children[d];
     }
}

int find(Trie * root , int x) {
    int N = 0;
    Trie * cur = root;
    for (int i = 30; i >= 0; i--) {
        int d = x & (1 << i);
	d = min(1 , d);
	if (d == 1 && cur->L > 0) {
	   N |= (1 << i);
	   cur = cur->children[0];
	} else if(d == 0 && cur->R > 0) {
	   N |= (1 << i);
	   cur = cur->children[1];
	} else {
	   if (cur->children[d] == nullptr) {
	      return N;
	   }
	   cur = cur->children[d];
	}
    }   
 
    return N;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    int n;
    cin >> n;
    Trie * root = new Trie();
    insert(root , 0);
    while (n--) {
       char c;
       int x;
       cin >> c >> x;
       if (c == '+') {
           insert(root , x);
       } else if(c == '-') {
           remove(root , x);
       } else {
          cout << find(root , x) << "\n";
       }
    }
    return 0;
}
