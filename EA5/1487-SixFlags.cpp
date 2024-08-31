/* Lislaila Tarsila Pereira - 202020550
EA5 - Six Flags */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SixFlagsPD(const vector<int>& duracoes, const vector<int>& pontuacoes, int T) {
    int N = duracoes.size();
    vector<int> dp(T + 1, 0);

    for (int t = 0; t <= T; ++t) {
        for (int i = 0; i < N; ++i) {
            if (duracoes[i] <= t) {
                dp[t] = max(dp[t], dp[t - duracoes[i]] + pontuacoes[i]);
            }
        }
    }

    return dp[T];
}

int main() {
    int instancia = 1;

    while (true) {
        int N, T;
        cin >> N >> T;

        if (N == 0 && T == 0)
            break;

        vector<int> duracoes(N);
        vector<int> pontuacoes(N);

        for (int i = 0; i < N; ++i) {
            cin >> duracoes[i] >> pontuacoes[i];
        }

        int resultado = SixFlagsPD(duracoes, pontuacoes, T);

        cout << "Instancia " << instancia++ << endl;
        cout << resultado << endl << endl;
    }

    return 0;
}