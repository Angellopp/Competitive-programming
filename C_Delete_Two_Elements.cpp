#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        ll a, s;
        cin >> a >> s;
        ll b = s - 2 * a;
        if (b < 0) {
            cout <<  "No\n";
            continue;
        }
        int aux1, aux2;
        bool f = true;
        for (int i = 0; i < 61; i++) {
            aux1 = (a >> i) & 1LL;
            aux2 = (b >> i) & 1LL;
            if (aux1 and aux2) {
                cout << "No\n";
                f = false;
                break;
            }
        }
        if (f) cout << "Yes\n";


    }

}