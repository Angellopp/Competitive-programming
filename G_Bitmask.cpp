#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll min=0;
    for (int i = s.size()-1 ; i >= 0; i--) {
        if (s[s.size()-1 - i] == '?') {
            min = min & ~(1LL<<i);
        }
        else {
            min = min | (1LL * (s[s.size()-1 - i] - '0')) << i;
        }
    }
    if (n<min) {
        cout << "-1\n";
        return 0;
    }
    for (int i = s.size()-1 ; i >= 0; i--) {
        if (s[s.size()-1 - i] == '?') {
            ll aux1 = min | (1LL<<i);
            if (aux1 <= n) min = aux1;
        }
    }
    cout << min << " \n";

}