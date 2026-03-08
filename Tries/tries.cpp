#include <bits/stdc++.h>

using namespace std;

class Trie{
    public:
      Trie * children[26];
      bool isleaf;
      Trie() {
         isleaf = false;
	       for (int i = 0; i < 26; i++) {
	          children[i] = nullptr;
	       }
      }
};

void insert(Trie * root , string a) {
    Trie * cur = root;
    for (char c : a) {
       if (cur->children[c - 'a'] == nullptr) {
          Trie * newchild = new Trie();
	  cur->children[c - 'a'] = newchild;
       }
       cur = cur->children[c - 'a'];
    }
    cur->isleaf = true;
}

bool search(Trie * root , string a) {
    Trie * cur = root;
    for (char c : a) {
        if (cur->children[c - 'a'] == nullptr) {
	   return false;
	}
	cur = cur->children[c - 'a'];
    }
    return cur->isleaf;
}
int main() {
    int n;
    cin >> n;
    vector <string> a(n);
    for (auto & c : a) {
        cin >> c;
    }
    Trie * root = new Trie();
    for (string c : a) {
       insert(root , c);
    }
    int qq;
    cin >> qq;
    while (qq--) {
       string c;
       cin >> c;
       cout << (search(root , c) ? "YES" : "NO" ) << "\n";
    }
    return 0;
}
