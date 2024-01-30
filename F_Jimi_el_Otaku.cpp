#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1500;
ll ans = 0;
int n;
int col[MAXN], fil[MAXN];
vector <vector<char>> tab(1500, vector<char>(1500));
vector <vector<int>> val(1500, vector<int>(1500, 1));

void bucle(int x, int y, int i) {
    int xmas = x, ymas = y;
    while (xmas != n and ymas != n) {
        if (tab[xmas][ymas] == 'R') {
            ymas++;
            if (ymas != n) val[xmas][ymas] += i * val[x][y];
            else ans += i * val[x][y] * col[xmas];
        }
        else {
            xmas++;
            if (xmas != n) val[xmas][ymas] += i * val[x][y];
            else ans += i * val[x][y] * fil[ymas];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> tab[i][j]; 
        cin >> col[i];
    }
    for (int i = 0; i < n; i++) cin >> fil[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (tab[i][j] == 'R') {
                if (j != n-1) val[i][j+1] += val[i][j];
                else ans += val[i][j] * col[i];
            }
            else{
                if (i != n-1) val[i+1][j] += val[i][j];
                else ans += val[i][j] * fil[j];
            }
        }
    }
    cout << ans << "\n";
    int q, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        x--; y--;
        char aux = tab[x][y], rev = (char)('D' + 'R' - aux);

        tab[x][y] = rev;
        bucle(x, y, 1);
        tab[x][y] = aux;
        bucle(x, y, -1);
        tab[x][y] = rev;   
        cout << ans << "\n";
    }
    return 0;
}