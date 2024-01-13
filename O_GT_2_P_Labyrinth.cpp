#include <bits/stdc++.h>
#include <vector>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ll long long
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const map<pair<int,int>, char> m = {
    {{0, 1}, 'R'}, 
    {{0, -1}, 'L'}, 
    {{1, 0}, 'D'}, 
    {{-1, 0}, 'U'}
};

queue<pair<int,int>> q;

void solve(vector<vector<char>>& l, pair<int,int> ini, pair<int,int> fin) {
    vector<vector<bool>> visited(l.size(), vector<bool>(l[0].size(), false));
    vector<vector<pair<int,int>>> parent(l.size(), vector<pair<int,int>>(l[0].size(), {-1, -1}));

    // Cola para realizar BFS
    q.push(ini);
    visited[ini.F][ini.S] = true;

    while (!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();

        // Verificar si alcanzamos el punto de llegada
        if (curr.F == fin.F && curr.S == fin.S) {
            stack<pair<int,int>> path;
            while (!(curr.F == ini.F && curr.S == ini.S)) {
                path.push(curr);
                curr = parent[curr.F][curr.S];
            }
            path.push(ini);

            cout << "YES" << endl;
            cout << path.size() - 1<< "\n";
            while (!path.empty()) {
                int x = path.top().F, y = path.top().S;
                // cout << x << " " << y << "\n";
                path.pop();
                if (!path.empty()) 
                    cout << m.at({path.top().F - x,path.top().S - y});
            }
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.F + dx[i];
            int ny = curr.S + dy[i];

            if (nx >= 0 && nx < l.size() && ny >= 0 && ny < l[0].size() && l[nx][ny] != '#' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = curr;
            }
        }
    }
    cout << "NO" << "\n";
    return;
}

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> l(n, vector<char>(m));
    pair<int,int> ini, fin;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> l[i][j];
            if (l[i][j] == 'A') ini = {i,j};
            if (l[i][j] == 'B') fin = {i,j}; 
        }
    }

    solve(l, ini, fin);

    return 0;
}
