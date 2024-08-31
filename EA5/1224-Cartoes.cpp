/* Lislaila Tarsila Pereira - 202020550
EA5 - Cartoes */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {   
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        vector<vector<long long>> dp(N, vector<long long>(2, 0));

        // Inicializa o dp para intervalos de tamanho 2
        for (int i = 0; i < N - 1; ++i) {
            dp[i][0] = max(v[i], v[i + 1]);
        }

        int vezAtual = 0;
        int vezAnterior = 1;

        // Preenche a tabela dp para intervalos maiores
        for (int tamanhoIntervalo = 4; tamanhoIntervalo <= N; tamanhoIntervalo += 2) {
            vezAnterior = vezAtual;
            vezAtual = 1 - vezAtual; // alterna entre 0 e 1
            for (int i = 0, j = tamanhoIntervalo - 1; j < N; ++i, ++j) {
                dp[i][vezAtual] = max(v[i] + min(dp[i + 1][vezAnterior], dp[i + 2][vezAnterior]),
                                      v[j] + min(dp[i][vezAnterior], dp[i + 1][vezAnterior]));
            }
        }

        cout << dp[0][vezAtual] << endl;
    }
    return 0;
}
