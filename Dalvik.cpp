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
int main() {
    fast_io;
    int tt ;
    cin >> tt;
    while (tt--) {
        ll v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18;
        
        cin >> v0 >> v1 >> v2;
        v6 = 1;
        v9 = v0 + v1;
        v10 = 0;
        v12 = 1;
        
        for (int i = 1 ; i < v2; i++) {
            v13 = abs(i*v0 - ((2*i*v0 + v1 - 1) / (2 * v1)) * v1);
            if(v13 * v6 < v9 * i) {
                v6 = i;
                v9 = v13;
            }
            cout << v6 << endl;
        }

            
        cout << v6 << "\n";
            
    }
    return 0;

}