#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.end()
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define F first
#define S second

using u32 = uint32_t;
using u64 = uint64_t;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
typedef priority_queue<int> pq_max;
typedef priority_queue<int, vi, greater<int>> pq_min;

const int maxn = 2e1;
const u32 MOD = 1000000007;
int a[maxn][maxn]{};
int ori[maxn][maxn]{};

int main(){ 
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ori[i][j];
            a[i][j] = ori[i][j];
        }
    }

    for (int x = 0; x < m; x++) {
		for (int y = 0; y < m; y++) {
			for (int i = 0 ; i < n; i++) {
			    swap(a[i][x], a[i][y]);
            }
			bool d = true;
			for (int i = 0; i < n; i++) {
				int f = 0;
				for (int j = 0; j < m; j++) {
					if (a[i][j] != j+1) {
						f++;
					}
				}
				if (f > 2) {
					d = false;
					break;
				}
			}
			if (d) {
				cout << "YES\n";
				return 0;
			}

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = ori[i][j];
                }
            }

		}
	}
	cout << "NO\n";
	return 0;
}
