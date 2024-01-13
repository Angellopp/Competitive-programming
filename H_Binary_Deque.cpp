#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;
const int MAX = 2*1e5+5;
using namespace std;

int main() {
    int tt;
    cin >> tt;
    int v[MAX];
    while(tt--) {
        int n, aux;
        cin >> n >> aux;
        ll sum  = 0;
        for(int i = 0; i < n; i++) 
        {cin >> v[i]; sum += v[i];}	
        if (sum == aux) {cout << 0 << "\n"; continue;}
        for (int i = 0; i < n/2; i++) {
            sum -= (v[i] + v[n-i-1]);
            if (sum == aux) {
                cout << i+1 << "\n";
                break;
            }
        }

    }
}
