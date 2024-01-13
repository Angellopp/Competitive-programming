#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll x, y;
    cin >> x >> y;
    
    ll aux = y,  sz = 1;
    while (aux != 1) {
        aux = aux >> 1LL;
        sz++;
    }
    aux = ((1LL << sz) - 1) - y; 
    // cout << "i: " << i << endl;
    // aux = 0;

    // for (int it = i; it >= 0; it--) {
    //     if (!(((x>>(i*1LL)) & 1) and ((y>>(i*1LL)) & 1))) {
    //         aux |= (1LL<<it);
    //     }
    // }
    // cout << (aux) << "\n";
    int i = 0; 
    while (true) {
        if ((aux >= x)) break;
        aux = (aux | (1LL<<i));
        i++;
    }
    cout << (aux ^ y) << "\n";

}