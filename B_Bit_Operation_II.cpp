#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void printBinary(ll& n) {
    for (ll i = 31; i >= 0; i--) {
        cout << ((n*1LL >> i) & 1*1LL);
    }
    cout << "\n";
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll aux = a & b;

    printBinary(aux);
    aux = a | b;
    printBinary(aux);
    aux = a ^ b;
    printBinary(aux);
}
