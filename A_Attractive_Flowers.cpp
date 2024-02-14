#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n % 2) {
        for (int i = 0; i < n; ++i) {
            sum += (a[i] & 1 ? a[i] : a[i] - 1);
        }
    }
    else {
        for (int i = 1; i < n; ++i) {
            sum += (a[i] & 1 ? a[i] : a[i] - 1);
        }
    }
    cout << sum << '\n';
	
	return 0;
}