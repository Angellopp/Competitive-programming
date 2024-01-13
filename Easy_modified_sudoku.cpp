#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> sudoku(8,vector<int> (8));
vector <vector <int>> sudoku_solved;
vector <vector <pair <int, int>>> quadrant;
int n, N;
bool found;

bool validInRow (int r, int d, vector <vector <int>>& sudoku = sudoku) {
	for (int c = 0; c < N; c++) {
    	if (sudoku[r][c] == d) return false;
	}
	return true;
}

bool validInCol (int c, int d, vector <vector <int>>& sudoku = sudoku) {
	for (int r = 0; r < N; r++) {
		if (sudoku[r][c] == d) return false;
	}
	return true;
}

bool validInQuadrant (int q, int d, vector <vector <int>>& sudoku = sudoku) {
	vector <int> vv(9);
	for (pair <int, int> pos: quadrant[q]) {
    	int r = pos.first;
    	int c = pos.second;
    	if (sudoku[r][c] == d) {
    		if (vv[d] < 2) {
    			vv[d]++;
    		}
    	else return false;
    	}
	}
	return true;
}

int getQuadrant (int r, int c) {
	return (r / n) * n + (c / n);
}

void backtrack (int r, int c) {
    if (r == N) {
    	found = true;
    	sudoku_solved = sudoku;
    	return;
	}
	if (found) {
		return;
	}
	int nc = (c + 1 == N) ? 0 : c + 1; // new column
	int nr = (c + 1 == N) ? r + 1 : r; // new row
	if (sudoku[r][c] != 0) {
    	// int d = sudoku[r][c];
        // sudoku[r][c] = 0;
        // if (!(validInRow(r, d) and
	    //     validInCol(c, d) and
	    //     validInQuadrant(getQuadrant(r, c), d))) {
	    // 	found = false;
        //     return;
	    // }
        // sudoku[r][c] = d;
        backtrack(nr, nc);
    	return;
	} 
	for (int d = 1; d <= 8; d++) {
    	int quadrant = getQuadrant(r, c);
	    if (validInRow(r, d) and
	        validInCol(c, d) and
	        validInQuadrant(getQuadrant(r, c), d)) {
	    	sudoku[r][c] = d;
	    	backtrack(nr, nc);
	    	sudoku[r][c] = 0;
	    }
	}
}

void precomputation () {
    sudoku_solved = sudoku;
	found = false;
	N = 8, n = 4;
	quadrant.resize(N);
	for (int r = 0; r < N; r++) {
    	for (int c = 0; c < N; c++) {
    		quadrant[getQuadrant(r, c)].push_back({r, c});
    	}
	}
}

void print (const vector <vector <int>>& sudoku) {
	for (auto row: sudoku) {
    	for (int elem: row) {
    		cout << elem << ' ';
    	}
    	cout << '\n';
	}
}

bool isValid(const vector <vector <int>>& sudoku) {
	for (int r = 0; r < 8; r++) {
		for(int c = 0; c < 8; c++) {
            int aux = sudoku_solved[r][c];
            sudoku_solved[r][c] = 0;
			if (!(validInRow(r, aux, sudoku_solved) and validInCol(c, aux, sudoku_solved) and validInQuadrant(getQuadrant(r, c), aux, sudoku_solved))) {
	        	return false;
	    	}
        	sudoku_solved[r][c] = aux;
		}
	}
	return true;
}

int main () {
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> sudoku[i][j];    
            }
        }
		precomputation();
		backtrack(0, 0);
        cout << "Test case #" << t + 1 << ": ";
		if (isValid(sudoku_solved)) { 
		// if (found) { 
            cout << "YES\n";
            print(sudoku_solved);
            continue;
        }
        cout << "NO\n";
    }
	return 0;
}