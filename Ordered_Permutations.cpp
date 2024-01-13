#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int count_permutations(int N, string R) {
    vector<vector<long long>> DP(N + 1, vector<long long>(2, 0));

    DP[1][0] = 1;
    DP[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= i - 1; k++) {
                if ((j == 0 && R[i - 2] == '<' && k < i - 1) || (j == 1 && R[i - 2] == '>' && k == i - 1)) {
                    DP[i][j] = (DP[i][j] + DP[i - 1][1 - j]) % MOD;
                }
            }
        }
    }

    int total_permutations = (DP[N][0] + DP[N][1]) % MOD;
    return total_permutations;
}

int main() {
    int N;
    cin >> N;
    string R;
    cin >> R;

    int result = count_permutations(N, R);

    cout << result << endl;

    return 0;
}
