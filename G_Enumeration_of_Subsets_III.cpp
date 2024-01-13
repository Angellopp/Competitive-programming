#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[20];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int mask=0; mask<int(1<<k); mask++){
        int x = 0;
        for(int i = 0; i < k; i++) {
            x = x | (((mask & (1<<i)) != 0) << a[i]);  
        }
        cout << x << ": ";
        for (int i = 0; i < n; i++) {
            if (x & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

}