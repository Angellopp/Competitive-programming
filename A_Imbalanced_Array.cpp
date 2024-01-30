#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 1e6+5;
ll t; 
int tam;

vector <ll> pref(1e6+5), suf(1e6+5);
vector <int> v;
vector <pair<int, int>> sumpref(1e6+5), sumsuf(1e6+6);

ll ans (int l, int r) {
    int n = r - l + 1;
    ll aux = 0;
    vector <pair<int, int>> maxminpref(n/2 + 1), maxminsuf(n - n/2 + 1);
    maxminpref[n/2] = {INT_MAX, 0};
    maxminsuf[0] = {INT_MAX, 0};

    for (int i = l; i < l + n/2; i++) {
        maxminpref[l + n/2 - i - 1].first = min(v[i], maxminpref[l + n/2 - i].first);
        maxminpref[l + n/2 - i - 1].second = max(v[i], maxminpref[l + n/2 - i].second);
        sumpref[l + n/2 - i - 1].first += maxminpref[l + n/2 - i].first;
        sumpref[l + n/2 - i - 1].second += maxminpref[l + n/2 - i].second;
    }

    for (int i = l + n/2; i < r + 1; i++) {
        maxminsuf[i - n/2 + 1].first = min(v[i], maxminsuf[i - n/2].first);
        maxminsuf[i - n/2 + 1].second = max(v[i], maxminsuf[i - n/2].second);
        sumsuf[i - n/2 + 1].first += maxminsuf[i - n/2].first;
        sumsuf[i - n/2 + 1].second += maxminsuf[i - n/2].second;
    }
    cout << "min: ";
    for(int i = 0; i < n/2 + 1; i++) {
        cout << maxminpref[i].first << " ";
    }
    cout << "\nmax: ";
    for(int i = 0; i < n/2 + 1; i++) {
        cout << maxminpref[i].second << " ";
    }

    cout << "\nmin: ";
    for(int i = 0; i < n - n/2 + 1; i++) {
        cout << maxminsuf[i].first << " ";
    }
    cout << "\nmax: ";
    for(int i = 0; i < n - n/2 + 1; i++) {
        cout << maxminsuf[i].second << " ";
    }
    cout << "\n\nmin: ";
    for(int i = 0; i < n/2 + 1; i++) {
        cout << sumpref[i].first << " ";
    }
    cout << "\nmax: ";
    for(int i = 0; i < n/2 + 1; i++) {
        cout << sumpref[i].second << " ";
    }

    cout << "\nmin: ";
    for(int i = 0; i < n - n/2 + 1; i++) {
        cout << sumsuf[i].first << " ";
    }
    cout << "\nmax: ";
    for(int i = 0; i < n - n/2 + 1; i++) {
        cout << sumsuf[i].second << " ";
    }


    // auxsumsuf += (ans(l, l + n/2) + ans(l + n/2 + 1, r));
    return aux;
}

int main() {
    int n, aux; 
    cin >> n;
    tam = n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    // pref[0] = v[0];
    // suf[0] = v[n-1];
    // for (int i = 1; i < n; i++) {
    //     pref[i] = pref[i-1] + v[i];
    //     suf[i] = suf[i-1] + v[n-i-1];
    // }
    cout << "\n" << ans(0, n-1) << endl;
}