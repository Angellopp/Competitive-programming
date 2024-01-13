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

const int maxn = 5842;
const u32 MOD = 1000000007;
int dp[maxn];    

int main(){ 
    fast_io;
    int x2 = 0, x3 = 0, x5 = 0, x7 = 0, r, t;
    dp[0] = 1;
    
    for (int i = 1; i <= maxn; i++){
        dp[i] = min(min(2 * dp[x2], 3 * dp[x3]), min(5 * dp[x5], 7 * dp[x7]));        
        if (dp[i] == 2 * dp[x2]) x2++;
        if (dp[i] == 3 * dp[x3]) x3++;
        if (dp[i] == 5 * dp[x5]) x5++;
        if (dp[i] == 7 * dp[x7]) x7++;
    }
    int n = 1;
    while (cin >> n and n) {
        string nn = "th";
        int u = n % 10, d = n % 100;
        if (u == 1 and d != 11) nn = "st";
        if (u == 2 and d != 12) nn = "nd";
        if (u == 3 and d != 13) nn = "rd";
        cout << "The " << n << nn << " humble number is " << dp[n-1] << ".\n";
    }
    return 0;
}
