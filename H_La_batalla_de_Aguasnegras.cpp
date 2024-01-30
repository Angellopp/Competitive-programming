#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
int dp[MAXN][MAXN]{};

int calcular(int x, int y) {
    if(x == 1) {
        dp[x][y] = y+1;
        return y+1;
    }

    int ans = 0;
    for (int i = y; i >= 0; i--) {
        ans += (dp[x-1][i]) ? dp[x-1][i] : calcular(x-1, i);
    }
    dp[x][y] = ans;
    return ans;
}

int main() {
    cout << calcular(10,10)<< " ";
    for (int i = 1; i < 10; i++) {
        cout << dp[i][i] << endl;

    }
}