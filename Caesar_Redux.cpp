#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie (0); cout.tie(0)
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())
using namespace std;

const int N = 2e5 + 5;

char move_left(char c, int k) {
    if (c == ' ') return c;
    int d = (c - 'a' - k + 26) % 26;
    return d + 'a';
}

char move_right(char c, int k) {
    if (c == ' ') return c;
    int d = (c - 'a' + k + 26) % 26;
    return d + 'a';
}

void solve() {
    int k; cin >> k;
    string s;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,s);
    int len = s.length();
    auto idx = s.find("the");
    bool left = 0;
    while(idx != string::npos) {
        int i = idx;
        bool c1 = ((i - 1) >= 0) ? (s[i - 1] == ' ') : 1;
        bool c2 = ((i + 3) < len) ? (s[i + 3] == ' ') : 1;
        if (c1 and c2) left = 1;
        idx = s.find("the", idx + 1);
    }
    string ans = "";
    for (int i = 0; i < len; i++) {
        if (left) ans += move_left(s[i], k);
        else ans += move_right(s[i],k);
    }
    // for(int i = 0; i < (int)ans.size()-1; i++) {
    //     cout << ans[i];
    // }
    cout << ans;
}

int main() {
    fast_io;
    int t; cin >> t;
    for (int i = 0; i < t - 1; i++) {
        solve();
        cout << "\n";
    }
    solve();
    return 0;
}