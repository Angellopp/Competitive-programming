#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int mask=0; mask<int(1<<n); mask++){
        cout << mask << ": ";
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

}