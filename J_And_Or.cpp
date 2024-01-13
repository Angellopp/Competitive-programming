#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int tt;
    ll x, y, aux, aux2;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> x >> y;
        aux = x;
        aux2 = y;
        for(int i = 0; i <=62; i++) {
            if ((((aux >> (i*1LL)) | 1LL) << (i*1LL)) <= y) {
                aux |= (1LL << i);
            }
        }
        for(int i = 0; i <=62; i++) {
        // for(int i = 62; i >=0; i--) {
            if (((((aux2 >> (i*1LL)) & (-1LL - 1)) << (i*1LL)) >= x) or ((x >> (i*1LL)) & 1LL == 0)) {
                aux2 &= ~(1LL << i);
            }
        }
        cout << ((x >> (1*1LL)) & 1LL) << endl << endl;
        cout << "Case " << t << ": " << aux << " " << aux2 << "\n";
    }
}