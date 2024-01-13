#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;
const int MAX = 1e6+5;
using namespace std;

ll fac[MAX]{}, facinv[MAX]{}, inv[MAX]{};

void factorial() {
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = (fac[i - 1] * i )% MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        facinv[i] = (facinv[i - 1] * inv[i]) % MOD;
    }
}

ll combi(ll n, ll k){
    if (n < k or n < 0 or k < 0) return 0;
    return fac[n] * ((facinv[n-k] * facinv[k]) % MOD) % MOD;
}

int main() {
    int x, y;
    cin >> x >> y;
    if ((2*y - x) % 3 or (2*x - y) % 3 or 2*y - x < 0 or 2*x - y < 0) {
        cout << "0\n";
        return 0;
    }
    ll a = (2*y - x)/3;
    ll b = (2*x - y)/3;
    factorial();
    cout << combi(a+b, a) << "\n";

}