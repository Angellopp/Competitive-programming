#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define rep(ini, n) for (int i = ini; i < n; i++)
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

// typedef long  ll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
typedef priority_queue<int> pq_max;
typedef priority_queue<int, vi, greater<int>> pq_min;

const int maxn = 2e5;
const u32 MOD = 1000000007;
// #define int long long int
int main(){ 
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        if(n <= 2) {
            int aux;
            for (int j = 0; j < k; j++)
                for(int i = 0; i < n; i++)
                cin >> aux;
            cout << "YES\n";
            continue;
        }
        if (n == 3){
            if (k <= 2) {
                int aux;
                for (int j = 0; j < k; j++)
                    for(int i = 0; i < n; i++)
                        cin >> aux;
                cout << "YES\n";
            }
            else {
                vector <int> k1(n);
                for (int i = 0; i < n; i++) {
                    cin >> k1[i];
                }
                set <int> auxxxx;
                auxxxx.insert(k1[1]);
                for (int j = 1; j < k; j++) {
                    for (int i = 0; i < n; i++) {
                        cin >> k1[i];
                    }
                    auxxxx.insert(k1[1]);
                }
                if(auxxxx.size() == 2) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            continue;
        }
        vector <int> k1(n);
        bool can = 1;
        vector <int> k2(n);
        vector <int> ini(n);
        for (int i = 0; i < n; i++) {
            cin >> k1[i];
            ini[i] = k1[i];
        }
        for(int j = 0; j < k-1; j++) {
            vector <int> aux1, aux2;
            for (int i = 0; i < n; i++) 
                cin >> k2[i];
            for (int i = 1; i < n; i++) {
                if (k2[0] != k1[i]) {
                    aux1.emplace_back(k1[i]);
                }
                if (k1[0] != k2[i]) {
                    aux2.emplace_back(k2[i]);
                }
            }
            k1 = k2;
            if (aux1.size() != 0 and aux2.size() != 0) {
                if (aux1 != aux2) {
                    can = 0;
                }
            }
        }
        if (k>=3) {
            vector <int> aux1, aux2;
            for (int i = 1; i < n; i++) {
                if (k2[0] != ini[i]) {
                    aux1.emplace_back(ini[i]);
                }
                if (ini[0] != k2[i]) {
                    aux2.emplace_back(k2[i]);
                }
            }
            if (aux1.size() != 0 and aux2.size() != 0) {
                if (aux1 != aux2) {
                    can = 0;
                }
            }

        }


        if (can) {
            cout << "YES\n";
        }
        
        else {
            cout << "NO\n";
        }
    }
    return 0;
}