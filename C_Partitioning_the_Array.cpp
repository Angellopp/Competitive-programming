#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.end()
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define F first
#define S second

using u32 = uint32_t;
using u64 = uint64_t;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
typedef priority_queue<int> pq_max;
typedef priority_queue<int, vi, greater<int>> pq_min;

const int maxn = 2e5;
const u32 MOD = 1000000007;

vector <int> prim;

void primos() {
    prim.push_back(2);
    for (ll i = 3; i <= 200000; i += 2) {
        bool ok = true;
        for (int j = 0; j < (int)prim.size() && prim[j] * prim[j] <= i; j++) {
            if (i % prim[j] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) prim.push_back(i);
    }
}




int main(){ 
    fast_io;
    int tt;
    cin >> tt;
    primos();
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n+2);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i+1];
        }
        // map <ll,int> f;
        int aux = n;
        // ll ans = 0;
        for (int i = 2; i <= n; i++) {
            if (aux % i) continue;

            int mccc = abs(v[0] - v[1 + n/i]);
            for (int j = 1; j <= n / i; j++) {
                int mcc = abs (v[j] - v[j+n/i]);
                for (int k = 1; k <= i; k++) {
                    mcc = (abs(v[j+k*n/i] - v[j]) == 0) ? mcc : __gcd(abs(v[j+k*n/i] - v[j]), mcc);
                }
                mccc = __gcd(mccc, mcc);
            }
            if (mccc != 1) ans++;
        }
        cout << ans << '\n';


    }

    
    return 0;
}
