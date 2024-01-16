#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

ll t; 
int tam;

vector <ll> pref(2e5), suf(2e5);
vector <int> v;

ll ans (int l, int r) {
    int n = r - l;
    ll aux = 0;

    aux += (ans(l, l + n/2) + ans(l + n/2 + 1, r));
}

int main() {
    int n, aux; 
    cin >> n >> t;
    tam = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    pref[0] = v[0];
    suf[0] = v[n-1];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + v[i];
        suf[i] = suf[i-1] + v[n-i-1];
    }
    cout << ans(0, tam) << endl;
}