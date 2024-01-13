#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        ((a+b)%2) ? cout << "Alice\n" : cout << "Bob\n";
    }
}