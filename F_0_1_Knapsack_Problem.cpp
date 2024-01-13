#include <bits/stdc++.h>
using namespace std;

int n, w;
const int N = 100 + 5;
const int W = 1e4 + 5;

vector<int> va(102);
vector<int> we(102);
int dp[N][W];
bool vis[N][W];

int f(int i, int w) {
    if (w < 0) return -(1e9 + 5);
    if (vis[i][w]) return dp[i][w];
    vis[i][w] = true;
    if (i == n) {
        if (w >= we[i]) {
            return dp[i][w] = va[i];
        }
        return 0;
    }
    return dp[i][w] = max(f(i + 1, w), f(i + 1, w - we[i]) + va[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> va[i] >> we[i];
    }
    cout << f(0, w);

}