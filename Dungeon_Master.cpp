#include <iostream>
using namespace std;

char a[30][30][30]{};
int l, r, c, i0, j0, k0, in, jn, kn, ans = 0, cnt = 0;
bool flag = false;

void backtracking (int i, int j, int k) {
    // for (int i = 0; i < l; i++) {
    //     for (int j = 0; j < r; j++) {
    //         for (int k = 0; k < c; k++) {
    //             cout << a[i][j][k];
    //         }cout << "\n"; 
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    if (i == in and j == jn and k == kn) {
        flag = true;
        cout << "Escaped in " << ans << " minute(s)." << "\n";
        return;
    }
    if (i < l and a[i + 1][j][k] == '.') {a[i + 1][j][k] = 'S'; ans++; backtracking(i + 1, j, k); a[i + 1][j][k] = '.'; if(flag) return ;}
    if (0 < i and a[i - 1][j][k] == '.') {a[i - 1][j][k] = 'S'; ans++; backtracking(i - 1, j, k); a[i - 1][j][k] = '.'; if(flag) return ;}
    if (j < r and a[i][j + 1][k] == '.') {a[i][j + 1][k] = 'S'; ans++; backtracking(i, j + 1, k); a[i][j + 1][k] = '.'; if(flag) return ;}
    if (0 < j and a[i][j - 1][k] == '.') {a[i][j - 1][k] = 'S'; ans++; backtracking(i, j - 1, k); a[i][j - 1][k] = '.'; if(flag) return ;}
    if (k < c and a[i][j][k + 1] == '.') {a[i][j][k + 1] = 'S'; ans++; backtracking(i, j, k + 1); a[i][j][k + 1] = '.'; if(flag) return ;}
    if (0 < k and a[i][j][k - 1] == '.') {a[i][j][k - 1] = 'S'; ans++; backtracking(i, j, k - 1); a[i][j][k - 1] = '.'; if(flag) return ;}
    // cout << ans << "\n\n";
    // if(!flag)
    ans = 0;
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (true) {
        cin >> l >> r >> c;
        if (l == 0 and r == 0 and c == 0) return 0;
        ans = 0, cnt = 0;
        flag = false;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S'){
                        i0 = i, j0 = j, k0 = k;
                        // a[i][j][k] = '.';
                    }
                    if (a[i][j][k] == 'E'){
                        in = i, jn = j, kn = k;
                        a[i][j][k] = '.';
                    }
                }
            }
        }
        backtracking(i0, j0, k0);
        if(!flag) cout << "Trapped!" << "\n";
        // cout << ans << "\n";
        
    }
    
}