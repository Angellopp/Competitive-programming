#include <bits/stdc++.h>
#define ll long long
using namespace std;

char grid[1500][1500];

void solve(){
    int n;
    cin >> n;
    int col[1500];
    int row[1500];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
        // cin >> col[i];
    }
    for (int i = 0; i < n; i++) cin >> row[i];
    int q;
    cin >> q;
    vector<pair<int,int>> cords;
    for (int i = 0; i < q; i++) cin >> cords[i].first >> cords[i].second;
    cout << 1;
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int x = i;
    //         int y = j;
    //         do {
    //             if (grid[x][y] == 'R') x++;
    //             else y++;
    //         } 
    //         while (!(x == n || y == n));
    //         if (x == n) ans += col[y];
    //         else ans += row[x];
    //     }
    // }
    // cout << ans << "\n";
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}