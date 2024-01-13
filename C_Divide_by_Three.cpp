#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 1e5;
int dp[maxn][3]{};
vector <vector<int>> v(3);

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int dig = s[0] - '0';
    dp[0][(dig % 3)] = 1;
    // v[dig % 3].pb(dig);
    bool couldBe0 = false;
    for (int i = 1; i < n; i++) {
        dig = s[i] - '0';
        int r = (dig % 3);
        if (r == 0) {
            if (couldBe0 or dig != 0) {
                dp[i][0] = dp[i-1][0] + 1;
                // v[0].pb(r);
            }
            else {
                if (dp[i-1][0] != 0) {
                    dp[i][0] = dp[i-1][0] + 1;
                    // v[0].pb(r);
                }
                if (dp[i][0]) couldBe0 = true;
            }
            if (dp[i-1][1] != 0) {
                dp[i][1] = dp[i-1][1] + 1;
                // v[1].pb(r);
            }
            if (dp[i-1][2] != 0) {
                dp[i][2] = dp[i-1][2] + 1;
                // v[2].pb(r);
            }

        }
        else {
            for (int j = 0; j < 3; j++) {
                if (dp[i-1][(j+2*r)%3] != 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][(j+2*r)%3] + 1);
                    // v[j].pb(r);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    cout << "\n" << dp[n-1][0] << "\n";
}
