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

const int maxn = 1e5;
const u32 MOD = 1000000007;

int dp[maxn]{};

int ver(int n) {
    int ans = 1;
    while (n != 1) {
        n = (n % 2) ? 3*n+1 : n/2;
        ans++;
    }
    return ans;
}

int main(){ 
    fast_io;
    int i, j, ans;
    while (cin >> i >> j) {
        ans = 0;
        cout << i << " " << j << " ";
        if (i > j) swap(i, j);
        for (int k = i; k <= j; k++) {
            ans = max(ans, ver(k));
        }
        cout << ans << "\n";
    }
    return 0;
}
