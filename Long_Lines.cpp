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


int main(){ 
    fast_io;
    int n, h0, x, y, q;
    cin >> n >> h0 >> x >> y >> q;
    n = 6;
    vi a(n);
    // a[0] = h0;
    // for (int i = 1; i < n; i++) {
	//     a[i] = (1ll * x * a[i - 1] + y) % q;
    // }
    // a = {4,5,7,6,2,3,8,1,9};
    a = {4,4,5,5, 5,4};
    // for (int i : a) {
    //     cout << i << " ";
    // }cout << endl;
    vi max(n);
    max[0] = a[0];
    int ini = 0;
    int fin = 0;

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        // int it = lower_bound(a.rbegin() + ini, a.rbegin() + fin +1, a[i]) - a.rbegin();
        ll lo = ini, hi = fin;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if (max[mid] >= a[i]) lo = mid; 
            else hi = mid - 1;
        }
        int it = lo;


        cout << "preit :" << it << endl; 
        if(max[ini]< a[i]) {
            max[ini] = a[i];
            ans += (ll)(fin-ini+1); 
            fin = 0;
            ini = 0;
            // ans--;
        }
        else {
            max[it+1] = a[i];
            ans += (ll)(fin-ini+1);
            fin = it+1;
        }
        cout << "ans : " << ans << endl;

        for (int j : max) {
            cout << j << " ";
        }cout << endl;
        for (int j = ini; j <= fin; j++) {
            cout << max[j] << " ";
        }cout << endl;
    }
    cout << ans << "\n";
// <<
    return 0;

}

// int bs (int lo, int hi){
//     int lo = 0, hi = n-1;
//     while (lo < hi) {
//         int mid = (lo + hi + 1) / 2;
//         if (p(mid)) lo = mid; 
//         else hi = mid - 1;
//     }
// }
// // FORMA 1 0
//     bool p[] = {1,1,1,0,0,0,0,0,0};
//     // PRIMER "0"
//     int lo = 0, hi = n-1;
//     while (lo < hi) {
//         int mid = (lo + hi) / 2;
//         if (p(mid)) lo = mid + 1; 
//         else hi = mid;
//     }
//     // ULTIMO "1"
//     int lo = 0, hi = n-1;
//     while (lo < hi) {
//         int mid = (lo + hi + 1) / 2;
//         if (p(mid)) lo = mid; 
//         else hi = mid - 1;
//     }

// // FORMA 0 1
//     bool p[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1};     
//     // PRIMER "1"
//     int lo = 0, hi = n-1;
//     while (lo < hi) {
//         int mid = (lo + hi) / 2;
//         if (!p(mid)) lo = mid + 1; 
//         else hi = mid;
//     }
//     // ULTIMO "0"
//     int lo = 0, hi = n-1;
//     while (lo < hi) {
//         int mid = (lo + hi + 1) / 2;
//         if (!p(mid)) lo = mid; 
//         else hi = mid - 1;
//     }
