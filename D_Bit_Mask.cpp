#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x, aux; 
    cin >> n;
    bitset<64> state;
    vector<bitset<64>> mask(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++){
            cin >> aux;
            mask[i].set(aux);
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int op, i;
        cin >> op;
        switch (op) {
            case 0:
                cin >> i;
                cout << state[i] << '\n';
                break;
            case 1:
                cin >> i;
                state |= mask[i];
                break;
            case 2:
                cin >> i;
                state &= ~mask[i];
                break;
            case 3:
                cin >> i;
                state ^= mask[i];
                break;
            case 4:
                cin >> i;
                cout << (((state & mask[i]) == mask[i]) ? 1 : 0) << '\n';
                break;
            case 5:
                cin >> i;
                cout << ((state & mask[i]).any() ? 1 : 0) << '\n';
                break;
            case 6:
                cin >> i;
                cout << ((state & mask[i]).none() ? 1 : 0) << '\n';
                break;
            case 7:
                cin >> i;
                cout << (state & mask[i]).count() << '\n';
                break;
            case 8:
                cin >> i;
                cout << (state & mask[i]).to_ullong() << '\n';
                break;
        }
    }

    return 0;
}
