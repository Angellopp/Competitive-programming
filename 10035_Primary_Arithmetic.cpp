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

const ll maxn = 1e10;
const u32 MOD = 1000000007;


int main(){ 
    fast_io;
    ll n1, n2;
    while(cin >> n1 >> n2) {
        if(n1 == 0 and n2 == 0) break;
        int ans = 0;
        ll n3 = n1 + n2;
        while (n3 != 0) {
            int un1 = n1 % 10;
            int un2 = n2 % 10;
            int un3 = n3 % 10;
            if (un3 < un2 or un3 < un1) ans++;
            else if (((un2 == 9 or un1 == 9 )and un1*un2 != 0) and (un3 == un2 or un3 == un1)) ans++;
            n1 /= 10; n2 /= 10; n3 /= 10;
        }
        if(ans == 0) cout << "No carry operation.\n";
        else if (ans == 1) cout << "1 carry operation.\n";
        else cout << ans << " carry operations.\n";
    }
    return 0;
}
