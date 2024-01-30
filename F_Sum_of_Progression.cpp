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
typedef vector<ll> vll;
typedef vector<pll> vllll;
typedef vector<string> vs;
typedef priority_queue<int> pq_max;
typedef priority_queue<int, vi, greater<int>> pq_min;

const int maxn = 1e5;
const u32 MOD = 1000000007;


int main(){ 
    fast_io;
    int tt;
    cin >> tt;
    vll v(maxn), suf(maxn + 1), sum(maxn + 1);
    while (tt--) {
        int n, q; 
        cin >> n >> q;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 1; i <= n; i++) {
            suf[i] = suf[i-1] + i*v[i-1];
            sum[i] = sum[i-1] + v[i-1];
        }
        for (int i = 0; i <= n; i++) {
            cout << suf[i] << " ";  
        }
        cout << "\n";
        for (int i = 0; i <= n; i++) {
            cout << sum[i] << " ";
        }
        cout << "\n";
        ll ini, num, step;
        for (int i = 0; i < q; i++) {
            cin >> ini >> step >> num; ini --; step = 1;
            cout << suf[ini + step*(num-1) + 1] - suf[ini] - (sum[ini + step*(num-1) + 1] - sum[ini]) * (ini) << " ";
        }
        cout << "\n";
    }
    
}
