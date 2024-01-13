#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    bitset<64> state;
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
                state.set(i, true);
                break;
            case 2:
                cin >> i;
                state.set(i, false);
                break;
            case 3:
                cin >> i;
                state.flip(i);
                break;
            case 4:
                cout << (state.all() ? 1 : 0) << '\n';
                break;
            case 5:
                cout << (state.any() ? 1 : 0) << '\n';
                break;
            case 6:
                cout << (state.none() ? 1 : 0) << '\n';
                break;
            case 7:
                cout << state.count() << '\n';
                break;
            case 8:
                cout << state.to_ullong() << '\n';
                break;
        }
    }

    return 0;
}
