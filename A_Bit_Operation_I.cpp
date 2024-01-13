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
    ll n;
    cin >> n;
    ll aux = n;

    printBinary(aux);
    aux = ~n;
    printBinary(aux);
    aux = n<<1;
    printBinary(aux);
    aux = n>>1;
    printBinary(aux);
}
