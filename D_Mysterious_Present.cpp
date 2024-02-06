#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w, h, aux1, aux2;
    cin >> n >> w >> h;
    vector <pair<pair<int,int>, int>> vp;
    for (int i = 0; i < n; i++) {
        cin >> aux1 >> aux2;
        if (aux1 > w and aux2 > h) {
            vp.push_back({{aux1, aux2}, i+1});
        }
    }
    if(vp.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    sort(vp.begin(), vp.end());
    n = vp.size();
    
    vector <int> aux(n, 0);
    vector <vector<int>> lis(n);
    // set <int> s; 
    aux[0] = 1;
    lis[0].push_back(vp[0].second);
    // s.insert(1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vp[j].first.first < vp[i].first.first and vp[j].first.second < vp[i].first.second) {
                if (aux[j] + 1 > aux[i]) {
                    aux[i] = aux[j] + 1;
                    lis[i] = lis[j];
                    lis[i].push_back(vp[i].second);
                }
            }
        }
    }
    int ind = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (aux[i] > mx) {
            ind = i;
            mx = aux[i];
        }
    }
    cout << mx << "\n";
    for (int i : lis[ind]){
        cout << i << " ";
    }
}