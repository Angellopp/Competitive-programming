#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n, x, y;
    cin >> n; 
    while (n--) {
        cin >> x >> y;
        ll aux = x, i = 0;
        while (true) {
            if ((aux | (1LL<<i)) > y) break;
            aux = (aux | (1LL<<i));
            i++;
        }
        cout << aux << "\n";
    }
}