#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m = 0;
int trie[1000000][2];

void add (ll n) {
    int r = 0;
    for (int i = 0; i < 30; i++) {
        int ch = (n >> i) & 1;
        if (!trie[r][ch]) 
            trie[r][ch] = ++m;
        r = trie[r][ch];
        
    }
}

ll max_trie(ll n) {
    ll ans  = 0;
    int r  = 0;
    for (int i = 0; i < 30; i++) {
        int ch = (n >> i) & 1;
        if (trie[r][1-ch]) {
            ans += (1 << i);
            r = trie[r][1-ch];
        }
        else {
            r = trie[r][ch];
        }
    }
    return ans;
}

int main() {
    int tt;
    cin >> tt;
    int n, x, aux, in = 0; ll ans = 0;
    while(tt--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            in ^= aux;
            add(aux);
            ans = max(ans, max_trie(in));
        }
        cout << ans << "\n";
        memset(trie, 0, sizeof(trie));
    }
    return 0;
}