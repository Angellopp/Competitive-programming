#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt, n;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> n >> s;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            (s[i] == '+') ? sum++ : sum--;
        }
        cout << abs(sum) << "\n";

    }
}