#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[20];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int mask=0; mask<int(1<<n); mask++){
        int x = 0;
        for(int i = 0; i < k; i++){
            x |= (1<<a[i]);
        }
        if ((x & mask) == x) {
            cout << mask << ": ";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }

}