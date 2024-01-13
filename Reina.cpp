#include <iostream>
using namespace std;

char a[8][8]{};
int n, m, ans = 0, cnt = 0;
bool flag = false;

bool isvalid(int i, int j) {
    for(int ii = 0; ii < n and ii != i; ii++) {
        if(a[ii][j] == 'R') return false;
    }
    for(int jj = 0; jj < n and jj != j; jj++) {
        if(a[i][jj] == 'R') return false;
    }
    return true;
}

void backtracking (int i, int j) {
    if (cnt == m) {
        ans++;
        return;
    }
    else if (i == n) {
        return;
    }
    int nc = (j + 1 == n) ? 0 : j + 1; // new column
	int nr = (j + 1 == n) ? i + 1 : i; // new row
    if (a[i][j] == '#') {
        if(isvalid(i, j)){
            cnt++;
            a[i][j] = 'R';
            backtracking(nr, nc);
            cnt--;
            a[i][j] = '#';
        }
    }
    backtracking(nr, nc);
    
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == -1 and m == -1) return 0;
        ans = 0, cnt = 0;
        flag = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];}}
        backtracking(0, 0);
        cout << ans << "\n";
        
    }
    
}