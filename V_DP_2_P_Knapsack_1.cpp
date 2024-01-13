#include <bits/stdc++.h>
#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

ll n, W, w[100+5], v[100+5], m[100+5][100000+5];

ll dp(int ind, int bag){
    if (bag < 0) return -1e9;
    if (!ind) return 0;
    if (m[ind][bag] != -1) return m[ind][bag];
    return m[ind][bag] = max(dp(ind-1, bag-w[ind]) + v[ind], dp(ind-1, bag));
}

int main(){
    fast_io
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    memset(m, -1, sizeof(m));
    cout << dp(n, W) << "\n";
}