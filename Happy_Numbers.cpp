#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.end()
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define F first
#define S second
#define sz(x) ((int) x.size())

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

int dp[1300*10];

int f(int n) {
    int sa = 0;
    while(n) {
	sa += (n % 10) * (n % 10);
	n /= 10;
    }
    return sa;
}

bool is_happy(int n) {
    set<int> a({n});
    //cout << n << " ";
    while(true) {
	int len = sz(a);
	a.insert(f(n));
	//cout << f(n) << " ";
	n = f(n);
	if (sz(a) == len) break;
    }
    return a.count(1);
}

int main() {
    ll a,b;
    cin >> a >> b;
    
    for (int i = 1; i <= 1000*a; i++) {
	    dp[i] = is_happy(i);
        
    }
    
    int ans = 0;
    int num[10]{};
    for (int i = 0; i <= 1000*a; i++) {
	    // cout << "i: " << i << "\tf(i) : " << f(i) << endl; 
	    if (dp[i]) {
            string s = to_string(i);
            num[(int)(s[0]-'0')]++;
            ans += dp[f(i)];
        //     cout << i  << endl;
        }
    }
    cout << ans << "\n\n";
    for (int i = 0; i < 10; i++) {
        cout << "i: " << num[i] << "\n";
    }
    return 0;
}


