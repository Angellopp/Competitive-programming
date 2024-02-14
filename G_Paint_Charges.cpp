#include <bits/stdc++.h>
#define ll long long
#define fori for (int i = 1; i <= n; i++)
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector <int> v(n+1);
        fori cin >> v[i];
        vector <int> dp(n+2, 0);
        dp[0] = v[0];
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i-1] + 1, dp[max(0, i - v[i])] + 1);
        }
        cout << n << ": " ;
        fori {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

